#include <bits/stdc++.h>

using namespace std;

template <typename T> class TreeNode;
template <typename T> class Tree;
int getOpCode(string cmd);

template <typename T>
class TreeNode{
friend class Tree<T>;
public:
    TreeNode(T elem = 0);
    void Set(T elem);
private:
    T data;
    TreeNode *leftchild, *rightchild, *parent;
};

template <typename T>
TreeNode<T>::TreeNode(T elem):
    data{ elem }, leftchild{ 0 }, rightchild{ 0 }, parent{ 0 } {}

template <typename T>
class Tree{
public:
    Tree();
    bool Insert(T elem);
    bool Delete(T elem);
    bool depth(int k, ofstream &out);
    void leaf(ofstream &out);
private:
    TreeNode<T> *root;
    void depth(int l, int k, TreeNode<T> *current, vector<T> &lst);
    void leaf(TreeNode<T> *current, vector<T> &lst);
};

template <typename T>
Tree<T>::Tree():
    root{ 0 } {}

template <typename T>
bool Tree<T>::Insert(T elem){
    TreeNode<T> *input = new TreeNode<T>(elem);
    if(!root){
        root = input;
        return true;
    }
    else{
        TreeNode<T> *buf = root, *pre = root;
        while(buf){
            pre = buf;
            if(buf->data == elem)
                return false;
            if(buf->data > elem)
                buf = buf->leftchild;
            else
                buf = buf->rightchild;
        }
        if(pre->data > elem)
            pre->leftchild = input;
        else
            pre->rightchild = input;
        input->parent = pre;
    }
    return true;
}

template <typename T>
bool Tree<T>::Delete(T elem){
    TreeNode<T> *buf = root, *target, *pre = root;
    if(root){
        while(buf){
            pre = buf;
            if(buf->data > elem)
                buf = buf->leftchild;
            else if(buf->data < elem)
                buf = buf->rightchild;
            else
                break;
        }
        if(pre->data == elem){
            target = pre;
            T bufdat;
            if(target->leftchild){
                buf = target->leftchild;
                while(buf){
                    pre = buf;
                    buf = buf->rightchild;
                }
                bufdat = pre->data;
                if(pre == target->leftchild)
                    pre->parent->leftchild = pre->leftchild;
                else
                    pre->parent->rightchild = pre->leftchild;
                if(pre->leftchild)
                    pre->leftchild->parent = pre->parent;
                target->data = bufdat;
            }
            else if(target->rightchild){
                buf = target->rightchild;
                while(buf){
                    pre = buf;
                    buf = buf->leftchild;
                }
                bufdat = pre->data;
                if(pre == target->rightchild)
                    pre->parent->rightchild = pre->rightchild;
                else
                    pre->parent->leftchild = pre->rightchild;
                if(pre->rightchild)
                    pre->rightchild->parent = pre->parent;
                target->data = bufdat;
            }
            else{
                if(target->parent){
                    if(target->parent->leftchild == target)
                        target->parent->leftchild = 0;
                    else
                        target->parent->rightchild = 0;
                    pre = target;
                }
                else
                    root = 0;
            }
            return true;
        }
    }
    return false;
}

template <typename T>
bool Tree<T>::depth(int k, ofstream &out){
    vector<T> lst;
    int sz;
    depth(1, k, root, lst);
    sz = lst.size();
    if(!sz){
        out<<"NO\n";
        return false;
    }
    for(int i=0; i<sz; i++)
        out<<lst[i]<<' ';
    out<<'\n';
    return true;
}

template <typename T>
void Tree<T>::depth(int l, int k, TreeNode<T> *current, vector<T> &lst){
    if(!current)
        return;
    if(l == k)
        lst.push_back(current->data);
    else if(l>k)
        return;
    depth(l+1, k, current->leftchild,  lst);
    depth(l+1, k, current->rightchild, lst);
}

template <typename T>
void Tree<T>::leaf(ofstream &out){
    vector<T> lst;
    int sz;
    leaf(root, lst);
    sz = lst.size();
    for(int i=0; i<sz; i++)
        out<<lst[i]<<' ';
    out<<'\n';
}

template <typename T>
void Tree<T>::leaf(TreeNode<T> *current, vector<T> &lst){
    if(!current)
        return;
    else if(!(current->leftchild || current->rightchild)){
        lst.push_back(current->data);
        return;
    }
    leaf(current->leftchild,  lst);
    leaf(current->rightchild, lst);
}

int main(void){
    ifstream input ("bst.inp");
    ofstream output("bst.out");
    Tree<string> mtree;
    string buf;
    int N, depth, opcode;
    input>>N;
    for(int i=0; i<N; i++){
        input>>buf;
        opcode = getOpCode(buf);
        switch(opcode){
        case 0:
            input>>buf;
            mtree.Insert(buf);
            break;
        case 1:
            input>>buf;
            mtree.Delete(buf);
            break;
        case 2:
            input>>depth;
            mtree.depth(depth, output);
            break;
        case 3:
            mtree.leaf(output);
            break;
        }
    }
    input.close();
    output.close();
    return 0;
}

int getOpCode(string cmd) {
    string command[] = { "+","-", "depth", "leaf" };
    int i;
    int arraySize = sizeof(command)/sizeof(command[0]);
    for(i = 0 ; i < arraySize ; i++) {
        if(command[i] == cmd)
            return i;
    }
    return -1;
}

#include <bits/stdc++.h>

using namespace std;

template <typename T> class Tree;
template <typename T> class TreeNode;

bool c(pair<int, string> a, pair<int, string> b){
    if(a.first == b.first)
        return a.second<b.second;
    return a.first > b.first;
}

template <typename T>
class TreeNode {
public:
	friend class Tree<T>;
	TreeNode(T a = 0);
	inline void Set(T a) { data = a; }
	inline int size() { return child.size(); }
	inline T Data() { return data; }
private:
	T data;
	TreeNode<T> *parent;
	vector<TreeNode<T>*> child;
};

template <typename T>
TreeNode<T>::TreeNode(T a) :
	data{ a }, parent{ NULL } {}

template <typename T>
class Tree {
public:
	Tree(TreeNode<T> *a=0);
	void Insert(TreeNode<T> *parent, TreeNode<T> *son);
	int child(TreeNode<T> *root);
	void finish(vector<pair<int, string>> &st);
private:
	TreeNode<T> *root;
	void finish(vector<pair<int, string>> &st, TreeNode<T> *root, int lv);
};

template <typename T>
Tree<T>::Tree(TreeNode<T> *a) :
	root{ a } {}

template <typename T>
void Tree<T>::Insert(TreeNode<T> *parent, TreeNode<T> *son) {
	son->parent = parent;
	parent->child.push_back(son);
	if(son == root)
        root = parent;
/*	parent->weight.push_back(weight);*/
}

template <typename T>
int Tree<T>::child(TreeNode<T> *root) {
	int sum=0, sz=root->size();
	for(int i=0; i<sz; i++)
        sum += child(root->child[i]);
    return sum+sz;
}

template <typename T>
void Tree<T>::finish(vector<pair<int, string>> &st){
    finish(st, root,50);
}

template <typename T>
void Tree<T>::finish(vector<pair<int, string>> &st, TreeNode<T> *root, int lv){
    int sz = root->size();
    if(!root)
        return;
    st.push_back(pair<int, string>(child(root)*1000+lv, root->data));
    for(int i=0; i<sz; i++)
        finish(st, root->child[i],lv-1);
}

int main(void) {
    ifstream input("org.inp");
    ofstream output("org.out");
    vector<pair<int, string>> lst;
    vector<TreeNode<string> *> nlst;
    TreeNode<string> *bufs,*bufp;
    int N,flag1,flag2,sz;
    string P,S;
    input>>N>>S>>P;
    bufp = new TreeNode<string>(P);
    bufs = new TreeNode<string>(S);
    Tree<string> m(bufp);
    m.Insert(bufp,bufs);
    nlst.push_back(bufp);
    nlst.push_back(bufs);
    for(int i=0; i<N-2; i++){
        input>>S>>P;
        cout<<S<<' '<<P<<endl;
        sz = nlst.size();
        flag1 = flag2 = 0;
        for(int j = 0; j < sz; ++j)
            if(nlst[j]->Data() == S){
                bufs = nlst[j];
                break;
            }
            else if( j == sz-1){
                bufs = new TreeNode<string>(S);
                flag1 = 1;
            }
        for(int j = 0; j < sz; ++j)
            if(nlst[j]->Data() == P){
                bufp = nlst[j];
                break;
            }
            else if( j == sz-1){
                bufp = new TreeNode<string>(P);
                flag2 = 1;
            }
        m.Insert(bufp,bufs);
        if(flag1)
            nlst.push_back(bufs);
        if(flag2)
            nlst.push_back(bufp);
    }
    m.finish(lst);
    sort(lst.begin(), lst.end(), c);
    for(auto i=lst.begin(); i != lst.end(); ++i)
        output<<(*i).second<<' ';
	return 0;
}

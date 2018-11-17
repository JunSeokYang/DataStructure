#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream input("rumor.inp");
    ofstream output("rumor.out");
    int N,x,d,p,q,*bfs;
    input>>N>>x>>d;
    bfs = new int[N+1];
    for(int i=0; i<N+1; i++)
        bfs[i] = 1;
    vector<vector<int>> Node(N+1);
    deque<int> lst,buf;
    for(int i=0; i<N; i++){
        input>>p>>q;
        while(q != 0){
            Node[p].push_back(q);
            input>>q;
        }
        sort(Node[p].begin(),Node[p].end());
    }
    lst.push_back(x);
    while(d+1){
        for(int i=0; i<lst.size(); i++)
            if(bfs[lst[i]]){
                output<<lst[i]<<'\n';
                bfs[lst[i]] = 0;
            }
        d--;
        while(!lst.empty()){
            for(int i=0; i<Node[lst.front()].size(); i++)
                if(bfs[Node[lst.front()][i]])
                    buf.push_back(Node[lst.front()][i]);
            lst.pop_front();
        }
        lst.swap(buf);
        buf.clear();
    }

    return 0;
}

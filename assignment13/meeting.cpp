#include <bits/stdc++.h>

using namespace std;

int BFS(vector<vector<int> > &arr, vector<int> &visit, int p, int q){
    queue<int> nodelist;
    int m;
    nodelist.push(p);
    while(!nodelist.empty()){
        m = nodelist.front();
        nodelist.pop();
        if(m == q)
            return visit[m];
        for(auto i=++arr[m].begin(); i != arr[m].end(); ++i)
            if(!visit[*i]){
                visit[*i] = visit[m] + 1;
                nodelist.push(*i);
            }
    }
    return 0;
}


int main(void){
    ifstream input("meeting.inp");
    ofstream output("meeting.out");
    vector<vector<int> > arr(26);
    vector<int> nodelist;
    int N, index, st[3], time, btime, rtime=100, idx, bidx;
    char buf;

    input>>N;
    for(int i=0; i<3; ++i){
        input>>buf;
        st[i] = buf - 97;
    }

    for(int i=0; i<N; ++i){
        input>>buf;
        index = buf-97;
        nodelist.push_back(index);
        while(buf != '$'){
            arr[index].push_back(buf-97);
            input>>buf;
        }
    }
    sort(nodelist.begin(), nodelist.end());


    for(int i=0; i<N; ++i){
        time = 0;
        for(int j=0; j<3; ++j){
			vector<int> visit(26,0);
            btime = BFS(arr,visit,nodelist[i], st[j]);
            if(btime>1)
                btime = 3*btime - 2;
            if(time<btime){
                time = btime;
                bidx = nodelist[i];
            }
        }
        if(rtime > time){
            rtime = time;
            idx = bidx;
        }
    }
    output<<(char)(idx+97)<<'\n'<<rtime<<'\n';
    return 0;
}

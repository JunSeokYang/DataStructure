#include <bits/stdc++.h>

using namespace std;

int M,N;

int BFS(vector<vector<int> > &arr, int p, int q){
    queue<int> bfsx;
    int i,j,x[] = {-1,0,1,0}, y[] = {0,1,0,-1}, mbuf=0;
    bfsx.push(p*1000 + q);
    while(!bfsx.empty()){
        i = bfsx.front() / 1000;
        j = bfsx.front() % 1000;
        bfsx.pop();
        if(arr[i][j]){
			arr[i][j] = 0;
            mbuf++;
            for(int k=0; k<4; k++)
                if( (i+x[k] >=0) && (i+x[k] < M) && (j+y[k] >=0) && (j+y[k] < N) )
                    if(arr[i+x[k]][j+y[k]]){
                        bfsx.push((i+x[k])*1000 + j+y[k]);
                    }
        }
    }
    return mbuf;
}

int main(void){
    ifstream input("micro.inp");
    ofstream output("micro.out");
    int k,w=0,msize=0,mbuf=0;
    char buf;
    input>>N>>M>>k;
    vector<vector<int> > arr(M,vector<int>(N,0));
    for(int i=0; i<M; i++)
        for(int j=0; j<N; j++){
            input>>buf;
            if(buf == '#')
                arr[i][j] = 1;
        }
    for(int i=0; i<M; i++)
        for(int j=0; j<N; j++){
                mbuf = BFS(arr, i, j);
                if(mbuf >= k)
                    w++;
                if(mbuf >= msize)
                    msize = mbuf;
        }
    output<<w<<' '<<msize;
    return 0;
}

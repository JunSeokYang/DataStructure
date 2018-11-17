#include <bits/stdc++.h>

using namespace std;

int main(void){
    ifstream input("shopping.inp");
    ofstream output("shopping.out");
    int N,k,id,w,mn,idx;
    input>>N>>k;
    vector<queue<int>> shopper_id(k);
    vector<queue<int>> shopper_w(k);
    vector<int> weight(k,0);
    for(int i=0; i<N; i++){
        input>>id;
        input>>w;
        mn=2000;
        idx = -1;
        for(int j=0; j<k; j++)
            if(mn>weight[j]){
                mn = weight[j];
                idx = j;
            }
        shopper_id[idx].push(id);
        shopper_w[idx].push(w);
        weight[idx] += w;
    }
    while(true){
        mn = 2000;
        for(int j=0; j<k; j++)
            if(!(shopper_w[j].empty()) && (shopper_w[j].front()<mn))
                mn = shopper_w[j].front();
        if(mn == 2000)
            break;
        for(int j=k-1; j>-1; j--)
            if(!shopper_w[j].empty()){
                shopper_w[j].front() -= mn;
                if(!shopper_w[j].front()){
                    output<<shopper_id[j].front()<<'\n';
                    shopper_id[j].pop();
                    shopper_w[j].pop();
                }
            }
    }

    return 0;
}

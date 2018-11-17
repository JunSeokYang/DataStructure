#include <bits/stdc++.h>

using namespace std;

struct TUP{
    int i;
    long long ts,te;
};

bool cmpTUP(TUP a, TUP b){
    return a.ts < b.ts;
}

int main(void){
    ifstream input("log.inp");
    ofstream output("log.out");
    list<TUP> lst;
    set<int> ilst;
    TUP in;
    int N,K,id;
    long long ts, te, buf;
    input>>N>>K;
    for(int i=0; i<N; i++){
        input>>id>>ts>>te;
        in.i = id;
        in.ts = ts;
        in.te = te;
        lst.push_back(in);
    }
    lst.sort(cmpTUP);
    for(int j = 0; j<K; j++){
        N=0;
        ilst.clear();
        input>>buf;
        for(auto k=lst.begin(); k != lst.end(); k++){
            if((*k).ts<= buf && buf<=(*k).te){
                ilst.insert((*k).i);
                N=1;
            }
            else if((*k).ts > buf)
                break;
        }
        for(auto i=ilst.begin(); i != ilst.end(); i++)
            output<<*i<<' ';
        if(!N)
            output<<'0';
        output<<'\n';
    }
    input.close();
    output.close();
    return 0;
}

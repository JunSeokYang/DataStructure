#include <bits/stdc++.h>
#define G std::vector
#define T for(int j=0;j<N;j++)
#define K s[j]

int main(){
    std::ifstream i;
    std::ofstream o;
    int N,b;
    i.open("rank.inp");
    o.open("rank.out");
    i>>N;
    G<G<int>> s(N);
    T{
        b=0;
        while(b!=-1){
            i>>b;
            K.push_back(b);
        }
        sort(K.begin(),K.end());
        K[0]=K.size();
        K.push_back(-j-1);
    }
    sort(s.begin(),s.end());
    T o<<-K.back()<<'\n';
}

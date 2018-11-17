#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>

using namespace std;

class mine;

class mine{
public:
    mine(int a=5);
    inline void SetSize(int a){elemn = a; delete slot; slot = new int[a];}
    void push(int a);
    void pop(int a);
    void finish(ofstream *input);
private:
    int *slot;
    int sz;
    int elemn;
    set<int> av;
};

mine::mine(int a):
    slot{new int[a]}, sz{0}, elemn{a}{}

void mine::push(int a){
    int idx = sz;
    if(!av.empty()){
        idx = *(av.begin());
        av.erase(av.begin());
    }
    else
        if(sz == elemn ){
            int *buf = new int[elemn*2];
            copy(slot,slot+elemn,buf);
            delete[] slot;
            slot = buf;
            elemn *= 2;
        }
    slot[idx] = a;
    sz++;
}

void mine::pop(int a){
    int k=av.size();
    for(int i=0; i<sz+k; i++){
        if(slot[i] == a){
            av.insert(i);
            slot[i] = 0;
            k++;
            break;
        }
    }
    sz--;
    if((elemn/3)>=sz){
        int *buf = new int[elemn/2];
        if(av.empty())
            copy(slot,slot+sz,buf);
        else{
            int it=0;
            for(int i=0; i<sz+k; i++)
                if(!slot[i])
                    continue;
                else
                    buf[it++] = slot[i];
            av.clear();
        }
        delete slot;
        slot = buf;
        elemn /= 2;
    }
}

void mine::finish(ofstream *input){
    for(int i=0; i<sz+(int)av.size(); i++){
        if(!slot[i])
            continue;
        else
            *input<<i+1<<' '<<slot[i]<<'\n';
    }
}

int main(void){
    ifstream input;
    ofstream output;

    input.open("parking.inp");
    output.open("parking.out");
    int K, N, buf;
    mine slot;
    input>>K;
    slot.SetSize(K);
    input>>N;
    for(int i=0; i<N; i++){
        input>>buf;
        if(buf>0)
            slot.push(buf);
        else
            slot.pop(-buf);
    }
    slot.finish(&output);
    input.close();
    output.close();
    return 0;
}

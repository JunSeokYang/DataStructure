#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(void){
    ifstream log,syslog;
    ofstream output;
    log.open("log.inp");
    syslog.open("syslog.txt");
    output.open("log.out");

    vector<int> elem;
    int N, k, buf, *lst, *idx, cnt, now=1, fst,fsti, scn,scni, elemn;

    log >> N;
    syslog >> k;
    lst = new int[k+2];
    idx = new int[k+2];
    lst[0] = 0;
    idx[0] = 0;
    lst[k+1] = 100000;
    idx[k+1] = 0;
    while(!syslog.eof()){
            cnt = 0;
            syslog >> buf;
            lst[now] = buf;
            while(1){
                syslog>>buf;
                if(!buf)
                    break;
                cnt++;
                elem.push_back(buf);
            }
            idx[now] = idx[now-1] + cnt;
            now++;
    }
    for(int m=0; m<N; m++){
        log>>fst;
        log>>fsti;
        log>>scn;
        log>>scni;
        elemn = 0;
        now = 0;
        cnt = 0;
        for(int i=0; i<k+1; i++)
            if(lst[i+1]>=fst){
                now = i;
                break;
            }
        for(int i=now; i<k+1; i++)
            if(lst[i+1]>scn){
                cnt = i;
                break;
            }

        if(lst[now+1] == fst)
            for(int i=idx[now]; i<idx[now+1]; i++)
                if(fsti>elem[i])
                    elemn--;
                else
                    break;
        if(lst[cnt] == scn)
            for(int i=idx[cnt-1]; i<idx[cnt]; i++)
                if(scni<elem[i])
                    elemn--;

        elemn += idx[cnt]-idx[now];
        output<<elemn<<'\n';
    }
    log.close();
    syslog.close();
    output.close();
    return 0;
}

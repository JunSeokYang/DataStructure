#include <bits/stdc++.h>

#define Deck list<int> // 카드 덱(Deck)의 자료구조는 list<int>

using namespace std;

void Shuffle(Deck &x);           // Shuffle 모듈화, 입력받은 덱 x를 셔플한다
void Cut(Deck &x, int i, int j); // Cut 모듈화, 입력받은 덱 x의 [i,j]구간을 자른 후 맨 뒤에 삽입한다
void finish(Deck x);             // 파일 입출력 모듈화, 덱 x를 파일 출력으로 저장한다

int main(void){
    ifstream   input("card.inp"); // 입력 파일
    Deck               User_deck; // 유저의 카드 덱
    string                   buf; // input으로부터 입력받는 버퍼
    int                  N,K,i,j; // N == 덱의 카드 수  ,  k == 명령어 횟수  ,  i,j == Cut i,j의 index


    input>>N>>K;
    for(int p=0; p<N; p++)
        User_deck.push_back(p+1);
    // 유저 덱 초기화


    for(int p=0; p<K; p++){
        input>>buf;                 // 명령어 확인
        if(!buf.compare("Shuffle"))
            Shuffle(User_deck);     // 입력받은 명령어가 "Shuffle"일 경우 유저 덱 Shuffle
        else{
            input>>i>>j;            // 입력받은 명령어가 "Shuffle"이 아닐 경우 "Cut"이므로 index i,j를 입력받은 후
            Cut(User_deck,i,j);     // 유저 덱 Cut
        }
    } // 명령 수행


    finish(User_deck); // output에 결과 저장
    input.close();
    return 0;          // 프로그램 종료
}

void Shuffle(Deck &x){
    Deck::iterator   it_DeckA, it_DeckB; // Shuffle 할 때 A,B 두 덱으로 나누므로 각각의 덱의 iterator를 it_DeckA, it_DeckB라 함
    Deck                            buf; // 두 덱 A,B를 교대로 섞은 결과를 buf에 저장후 기존의 덱과 swap할 에정
    int                odd = x.size()%2; // 홀수 플래그
    int            N = x.size()/2 + odd; // for loop 마다 size 함수를 콜 하는 오버헤드를 줄이기 위해


    it_DeckA = x.begin(); // it_DeckA 초기화

    it_DeckB = it_DeckA;
    for(int i=0; i<N; i++)
        it_DeckB++;
    // if_DeckB 초기화


    for(int i=0; i<N-odd; i++){
        buf.push_back(*it_DeckA++);
        buf.push_back(*it_DeckB++);
    }
    // 두 묶음을 교대로 buf 덱에 삽입


    if(odd)
        buf.push_back(*it_DeckA); // 카드 갯수가 홀수일 경우 첫 묶음 마지막 원소가 남으므로 삽입


    x = buf; // Swap
}

void Cut(Deck &x, int i, int j){
    Deck::iterator  it_i, it_j; // Cut 할 때 i,j번 째의 iterator

    it_i = x.begin();
    for(int q=1; q<i; q++)
        it_i++;
    // it_i 초기화


    it_j = it_i;
    for(int q=0; q<j-i+1; q++)
        it_j++;
    // it_j 초기화


    x.splice(x.end(),x,it_i,it_j); // Cut(i,j);
}

void finish(Deck x){
    ofstream           output("card.out"); // 출력 파일
    Deck::iterator                     it; // [N/2]번째 iterator
    int                   sz = x.size()/2; // for loop마다 size함수가 call되는 오버헤드를 줄이기 위해


    it = x.begin();
    for(int p=1; p<sz; p++)
        it++;
    // [N/2]번째 이터레이터 초기화


    output<<*x.begin()<<' '<<*it<<' '<<*--x.end()<<'\n'; // 정답 출력
    output.close(); // 함수 종료
}

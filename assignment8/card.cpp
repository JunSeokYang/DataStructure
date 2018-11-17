#include <bits/stdc++.h>

#define Deck list<int> // ī�� ��(Deck)�� �ڷᱸ���� list<int>

using namespace std;

void Shuffle(Deck &x);           // Shuffle ���ȭ, �Է¹��� �� x�� �����Ѵ�
void Cut(Deck &x, int i, int j); // Cut ���ȭ, �Է¹��� �� x�� [i,j]������ �ڸ� �� �� �ڿ� �����Ѵ�
void finish(Deck x);             // ���� ����� ���ȭ, �� x�� ���� ������� �����Ѵ�

int main(void){
    ifstream   input("card.inp"); // �Է� ����
    Deck               User_deck; // ������ ī�� ��
    string                   buf; // input���κ��� �Է¹޴� ����
    int                  N,K,i,j; // N == ���� ī�� ��  ,  k == ��ɾ� Ƚ��  ,  i,j == Cut i,j�� index


    input>>N>>K;
    for(int p=0; p<N; p++)
        User_deck.push_back(p+1);
    // ���� �� �ʱ�ȭ


    for(int p=0; p<K; p++){
        input>>buf;                 // ��ɾ� Ȯ��
        if(!buf.compare("Shuffle"))
            Shuffle(User_deck);     // �Է¹��� ��ɾ "Shuffle"�� ��� ���� �� Shuffle
        else{
            input>>i>>j;            // �Է¹��� ��ɾ "Shuffle"�� �ƴ� ��� "Cut"�̹Ƿ� index i,j�� �Է¹��� ��
            Cut(User_deck,i,j);     // ���� �� Cut
        }
    } // ��� ����


    finish(User_deck); // output�� ��� ����
    input.close();
    return 0;          // ���α׷� ����
}

void Shuffle(Deck &x){
    Deck::iterator   it_DeckA, it_DeckB; // Shuffle �� �� A,B �� ������ �����Ƿ� ������ ���� iterator�� it_DeckA, it_DeckB�� ��
    Deck                            buf; // �� �� A,B�� ����� ���� ����� buf�� ������ ������ ���� swap�� ����
    int                odd = x.size()%2; // Ȧ�� �÷���
    int            N = x.size()/2 + odd; // for loop ���� size �Լ��� �� �ϴ� ������带 ���̱� ����


    it_DeckA = x.begin(); // it_DeckA �ʱ�ȭ

    it_DeckB = it_DeckA;
    for(int i=0; i<N; i++)
        it_DeckB++;
    // if_DeckB �ʱ�ȭ


    for(int i=0; i<N-odd; i++){
        buf.push_back(*it_DeckA++);
        buf.push_back(*it_DeckB++);
    }
    // �� ������ ����� buf ���� ����


    if(odd)
        buf.push_back(*it_DeckA); // ī�� ������ Ȧ���� ��� ù ���� ������ ���Ұ� �����Ƿ� ����


    x = buf; // Swap
}

void Cut(Deck &x, int i, int j){
    Deck::iterator  it_i, it_j; // Cut �� �� i,j�� °�� iterator

    it_i = x.begin();
    for(int q=1; q<i; q++)
        it_i++;
    // it_i �ʱ�ȭ


    it_j = it_i;
    for(int q=0; q<j-i+1; q++)
        it_j++;
    // it_j �ʱ�ȭ


    x.splice(x.end(),x,it_i,it_j); // Cut(i,j);
}

void finish(Deck x){
    ofstream           output("card.out"); // ��� ����
    Deck::iterator                     it; // [N/2]��° iterator
    int                   sz = x.size()/2; // for loop���� size�Լ��� call�Ǵ� ������带 ���̱� ����


    it = x.begin();
    for(int p=1; p<sz; p++)
        it++;
    // [N/2]��° ���ͷ����� �ʱ�ȭ


    output<<*x.begin()<<' '<<*it<<' '<<*--x.end()<<'\n'; // ���� ���
    output.close(); // �Լ� ����
}

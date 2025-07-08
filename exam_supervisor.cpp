#include<iostream>
using namespace std;
int main(){ //13458
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int examination[N];
    for(int i=0; i<N; ++i){
        cin>>examination[i];
    }
    int B,C;
    cin>>B>>C;
    long long int mainspv=N, subspv=0;
    for(int i=0; i<N; ++i){
        if(examination[i]>B){
            int tmp=examination[i]-B;
            if(tmp%C==0) subspv+=tmp/C;
            else subspv+=1+(tmp/C);
        }
    }
    cout<<mainspv+subspv<<'\n';
}
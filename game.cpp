#include<iostream>
using namespace std;
int main(){ //21623
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k,n;
    cin>>k>>n;
    int numb[k];
    for(int i=0; i<k; ++i){
        cin>>numb[i];
    }
    int round=0, score=n;
    for(int i=0; i<k; ++i){
        if(score-numb[i]<0) continue;
        
        score-=numb[i];
        if(score==0){
            if(i!=k-1) score=n;
            ++round;
        }
    }
    cout<<round<<'\n';
    cout<<score<<'\n';
}
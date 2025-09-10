#include<iostream>
#include<unordered_map>
using namespace std;
int main(){ //32172
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,t;
    cin>>N;
    int value=0;
    unordered_map<int,bool> check;
    check[0]=true;
    for(int i=1; i<=N; ++i){
        if(value-i<=0 || check[value-i]) value+=i;
        else value-=i;
        check[value]=true;
    }
    cout<<value<<'\n';
} 
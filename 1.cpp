#include<iostream>
using namespace std;
int main(){ //4375
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    while(cin>>N){
    // for(int i=1; i<=10000; ++i){N=i;
    //     if(N==0) break;
    //     if(i%2==0 || i%5==0) continue;
        string st="1";
        int cnt=1;
        while(stoi(st)!=0){
            if(stoi(st)<N){
                st+="1";
                ++cnt;
            }
            else{
                int tmp=stoi(st)%N;
                st=to_string(tmp);
            }
        }
        cout<<cnt<<'\n';
    }
}
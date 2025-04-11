#include<iostream>
using namespace std;
int main(){//5292
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    for(int i=1; i<=N; ++i){
        if(i%3 == 0){
            if(i%5 == 0){
                cout<<"DeadMan"<<'\n';
            }
            else cout<<"Dead"<<'\n';
        }
        else if(i%5 == 0){
            cout<<"Man"<<'\n';
        }
        else cout<<i<<' ';
    }
}
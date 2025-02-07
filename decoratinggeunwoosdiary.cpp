#include<iostream>
using namespace std;
int main(){//32761
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int tmp=N,cnt=0;
    for(int i=0; i<9; ++i){
        if(tmp==10){
            ++cnt;
            break;
        }
        tmp/=10;
        ++cnt;
        if(tmp==0) break;
    }
    cout<<cnt<<'\n';
}
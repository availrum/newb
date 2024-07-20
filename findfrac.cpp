#include<iostream>
using namespace std;
int main(){//1193
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,tmp,st=1;
    cin>>N;
    tmp=N;
    for(int i=1; i<=N; ++i){
        tmp-=i;
        if(tmp<=0){
            st=i;
            tmp+=i;
            break;
        }
    }
    if(st%2==1) cout<<st-tmp+1<<"/"<<tmp<<'\n';
    else cout<<tmp<<"/"<<st-tmp+1<<'\n';
}
#include<iostream>
using namespace std;
int main(){//1244
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,sx,num,tmp;
    cin>>tmp;
    const int N=tmp; //안쓰면 첫 for문 마지막에서 1이 된다(?????????)
    // cout<<N;
    int swt[N];
    for(int i=1; i<=N; ++i){
        cin>>tmp;
        if(tmp==1) swt[i]=tmp;
        else if(tmp==0) swt[i]=-1;
    }
    cin>>t;
    // cout<<N;
    for(int i=0; i<t; ++i){
        cin>>sx>>num;
        if(sx==1){
            for(int j=1; j<=N/num; ++j) swt[j*num]*=-1;
        }
        else if(sx==2){
            swt[num]*=-1;
            int k=1;
            if(num-k<1 || num+k>N) continue;
            while(swt[num+k]==swt[num-k]){
                swt[num+k]*=-1;
                swt[num-k]*=-1;
                ++k;
            }
            continue;
        }
    }
    // for(int i=1; i<=N; ++i) cout<<swt[i]<<' ';
    // cout<<N<<'\n';
    for(int i=1; i<=N; ++i){
        if(swt[i]==-1) cout<<"0";
        else cout<<"1";
        if(i%20==0) cout<<'\n';
        else if(i!=N) cout<<' '; //elif가 아니면 공백 두번으로 인식한다.
    }
    cout<<'\n';
}
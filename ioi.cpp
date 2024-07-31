#include<iostream>
using namespace std;
int main(){//5525
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M,cnt=0;
    cin>>N>>M;
    string S,ioi="";
    cin>>S;
    for(int i=0; i<N; ++i) ioi+="IO";
    ioi+="I";
    int tmp=ioi.length();
    for(int i=0; i<=M-tmp; ++i){
        int check=S.find(ioi,i);
        // cout<<"check="<<check<<'\n';
        if(check!=-1){
            ++cnt;
            i=check+tmp;
            while(i<=M-2){
                if(S[i]=='O' && S[i+1]=='I'){
                    ++cnt;
                    i+=2;
                    // cout<<i<<'\n';
                }
                else{
                    i-=2;
                    break;
                }
            }
        }
        else break;
    }
    cout<<cnt<<'\n';
}
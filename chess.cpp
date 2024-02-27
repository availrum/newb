#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int N,M,par,parm,num;
    cin>>N>>M;
    int S[N][M],L[(N-7)*(M-7)];
    string c;
    for(int i=0; i<N; i++){//입력
        int j=0;
        cin>>c;
        // cout<<c[i];
        for(int j=0; j<M; j++){
            if(c[j]=='B') {
                S[i][j]=1;
                // cout<<"크악"<<'\n';
            }
            else if(c[j]=='W'){
                S[i][j]=0;
                // cout<<"으악"<<'\n';
            }
            // cin>>S[i][j];
        }
    }
    // cout<<"??"<<'\n';
    // for(int i=0; i<N; i++){//입력
    //     for(int j=0; j<M; j++){
    //         cout<<S[i][j];
    //     }
    //     cout<<'\n';
    // }
    num=0;
    for(int l=0; l<N-7; l++){//전체 행세트
        for(int k=0; k<M-7; k++){//열 확인
        par=0;
        parm=0;
            for(int i=l; i<l+8; i++){//행 확인
                for(int j=k; j<k+8; j++){//8*8배열

                    if((i+j)%2==0){//짝수칸
                        if(S[i][j]==1){
                            par+=1;
                        }
                        else{
                            parm+=1;
                        }
                    }

                    if((i+j)%2!=0){//홀수칸
                        if(S[i][j]==0){
                            par+=1;
                        }
                        else{
                            parm+=1;
                        }
                    }
                }
            }
        // cout<<parm<<'\n';
        if(par>parm) L[num]=par;
        else L[num]=parm;
        num++;
        }
        if(par==64){
            cout<<64-par<<'\n';
            return 0;
        }
        else if(parm==64){
            cout<<64-parm<<'\n';
            return 0;
        }
        }
        sort(L,L+(N-7)*(M-7));
    // cout<<T*(T-1)<<'\n';
    cout<<64-L[(N-7)*(M-7)-1]<<'\n';
    return 0;
}

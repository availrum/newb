#include<iostream>
using namespace std;
int main(){//25682
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M,K;
    cin>>N>>M>>K;
    string st;
    bool arr[N][M];
    int asb[N][M], asw[N][M];
    //B->0 , W->1

    for(int i=0; i<N; ++i){
        cin>>st;
        for(int j=0; j<st.length(); ++j){
            if(st[j]=='B') arr[i][j]=0;
            else arr[i][j]=1;
            asb[i][j]=0;
            asw[i][j]=0;
        }
    }
    for(int i=0; i<N; ++i){
        if(i==0){
            if(arr[i][0]==0){
                // asb[i][0]=0;
                asw[i][0]=1;
            }
            else{
                asb[i][0]=1;
                // asw[i][0]=0;
            }
        }
        else{
            if(arr[i][0]==0){
            //현재 칸이 B
                if(i%2==0){
                    asb[i][0]=asb[i-1][M-1];
                    asw[i][0]=asw[i-1][M-1]+1;
                }
                else{
                    asb[i][0]=asb[i-1][M-1]+1;
                    asw[i][0]=asw[i-1][M-1];
                }
            }
            else{
            //현재 칸이 W
                if(i%2==1){
                    asb[i][0]=asb[i-1][M-1];
                    asw[i][0]=asw[i-1][M-1]+1;
                }
                else{
                    asb[i][0]=asb[i-1][M-1]+1;
                    asw[i][0]=asw[i-1][M-1];
                }
            }
        }
        for(int j=1; j<M; ++j){
            if(arr[i][j]==0){
                if((i+j)%2==1){
                    asb[i][j]=asb[i][j-1]+1;
                    asw[i][j]=asw[i][j-1];
                }
                else{
                    asb[i][j]=asb[i][j-1];
                    asw[i][j]=asw[i][j-1]+1;
                }
            }
            else{
                if((i+j)%2==0){
                    asb[i][j]=asb[i][j-1]+1;
                    asw[i][j]=asw[i][j-1];
                }
                else{
                    asb[i][j]=asb[i][j-1];
                    asw[i][j]=asw[i][j-1]+1;
                }
            }
        }
    }
    /////////////////////////////////////////////////////////
    int sol=2147483647;
    int sbarr[N][M-K+1], swarr[N][M-K+1];
    for(int i=0; i<N; ++i){
        int tmp=0;
        for(int j=0; j<=M-K; ++j){
            if(j==0){
                if(i==0){
                    sbarr[i][j]=asb[i][K-1];
                    swarr[i][j]=asw[i][K-1];
                }
                else{
                    sbarr[i][j]=asb[i][j+K-1]-asb[i-1][M-1];
                    swarr[i][j]=asw[i][j+K-1]-asw[i-1][M-1];
                }
            }
            else{
                sbarr[i][j]=asb[i][j+K-1]-asb[i][j-1];
                swarr[i][j]=asw[i][j+K-1]-asw[i][j-1];
            }
        }
    }
    // for(int i=0; i<N; ++i){
    //     for(int j=0; j<=M-K; ++j){
    //         cout<<sbarr[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    /////////////////////////////////////////////////////////////
    for(int j=0; j<=M-K; ++j){
        int tmp=0;
        for(int i=0; i<N; ++i){
            tmp+=sbarr[i][j];
            if(i>=K){
                tmp-=sbarr[i-K][j];
            }
            if(i>=K-1 && sol>tmp) sol=tmp;
            // cout<<tmp<<'\n';
        }
        // cout<<'\n';
    }
    for(int j=0; j<=M-K; ++j){
        int tmp=0;
        for(int i=0; i<N; ++i){
            tmp+=swarr[i][j];
            if(i>=K){
                tmp-=swarr[i-K][j];
            }
            if(i>=K-1 && sol>tmp) sol=tmp;
        }
    }
    cout<<sol<<'\n';

    // for(int i=0; i<N; ++i){
    //     for(int j=0; j<M; ++j){
    //         cout<<asb[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
}
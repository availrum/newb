#include<iostream>
#include<vector>
using namespace std;
int main(){ //2240
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T,W,tmp;
    cin>>T>>W;
    vector<vector<vector<int>>> get(T,vector<vector<int>>(W+1,vector<int>(3,0)));
    int max_plum=0;
    for(int i=0; i<T; ++i){
        cin>>tmp;
        if(i==0){
            if(tmp==1){
                get[i][0][1]=1;
                max_plum=1;
            }
            else{
                get[i][1][2]=1;
                if(W>0) max_plum=1;
            }
        }
        else{
            for(int j=0; j<=W; ++j){
                for(int k=1; k<=2; ++k){
                    if(k==tmp){
                        if(j!=0){
                            if(get[i-1][j][k] || get[i-1][j-1][abs(tmp-2)+1]) get[i][j][k]=1+max(get[i-1][j][k],get[i-1][j-1][abs(tmp-2)+1]);
                        }
                        else if(tmp==1) get[i][j][k]=1+get[i-1][j][k]; // 1번에서 시작이므로 2번이면 무조건 1번 이동
                    }
                    else get[i][j][k]=get[i-1][j][k];
                    
                    max_plum=max(max_plum,get[i][j][k]);
                }
            }
        }
    }
    // for(int i=0; i<T; ++i){
    //     for(int j=0; j<=W; ++j){
    //         for(int k=1; k<=2; ++k){
    //             cout<<get[i][j][k]<<' ';
    //         }
    //         cout<<'\n';
    //     }
    //     cout<<'\n';
    // }
    cout<<max_plum<<'\n';
}
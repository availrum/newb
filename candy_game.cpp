#include<iostream>
using namespace std;
int dirx[4]={0,1,0,-1};
int diry[4]={1,0,-1,0};
int main(){ //3085
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    char arr[N][N];
    for(int i=0; i<N; ++i){
        string st;
        cin>>st;
        for(int j=0; j<N; ++j){
            arr[i][j]=st[j];
        }
    }
    int max_cnt=0;
    for(int i=0; i<N; ++i){
        int cnt=1;
        for(int j=1; j<N; ++j){
            if(arr[i][j]==arr[i][j-1]) ++cnt;
            else cnt=1;
            max_cnt=max(max_cnt,cnt);
        }
    }
    for(int j=0; j<N; ++j){
        int cnt=1;
        for(int i=1; i<N; ++i){
            if(arr[i][j]==arr[i-1][j]) ++cnt;
            else cnt=1;
            max_cnt=max(max_cnt,cnt);
        }
    }
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            for(int k=0; k<4; ++k){
                int x=i+dirx[k];
                int y=j+diry[k];
                if(x<0 || x>=N) continue;
                if(y<0 || y>=N) continue;
                if(dirx[k]!=0){
                    swap(arr[i][j],arr[x][y]);
                    for(int m=0; m<N; ++m){
                        int cnt=1;
                        for(int l=1; l<N; ++l){
                            if(arr[m][l]==arr[m][l-1]) ++cnt;
                            else cnt=1;
                            max_cnt=max(max_cnt,cnt);
                        }
                    }
                    for(int m=0; m<N; ++m){
                        int cnt=1;
                        for(int l=1; l<N; ++l){
                            if(arr[l][m]==arr[l-1][m]) ++cnt;
                            else cnt=1;
                            max_cnt=max(max_cnt,cnt);
                        }
                    }
                    swap(arr[i][j],arr[x][y]);
                }
                else{
                    swap(arr[i][j],arr[x][y]);
                    for(int m=0; m<N; ++m){
                        int cnt=1;
                        for(int l=1; l<N; ++l){
                            if(arr[l][m]==arr[l-1][m]) ++cnt;
                            else cnt=1;
                            max_cnt=max(max_cnt,cnt);
                        }
                    }
                    for(int m=0; m<N; ++m){
                        int cnt=1;
                        for(int l=1; l<N; ++l){
                            if(arr[m][l]==arr[m][l-1]) ++cnt;
                            else cnt=1;
                            max_cnt=max(max_cnt,cnt);
                        }
                    }
                    swap(arr[i][j],arr[x][y]);
                }
            }
        }
    }
    cout<<max_cnt<<'\n';
}
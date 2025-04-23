#include<iostream>
#include<queue>
using namespace std;
int dirx[4]={10,-10,0,0};
int diry[4]={0,0,10,-10};
struct pos{
    int x;
    int y;
    int cnt;
};
int main(){//13460
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    int arr[N][M];
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            arr[i][j]=0;
        }
    }
    queue<pos> qur,qub;
    for(int i=0; i<N; ++i){
        string st;
        cin>>st;
        for(int j=0; j<st.length(); ++j){
            if(st[j]=='#'){
                arr[i][j]=-1;
            }
            else if(st[j]=='O'){
                arr[i][j]=0;
            }
            else if(st[j]=='.'){
                arr[i][j]=1;
            }
            else if(st[j]=='R'){
                arr[i][j]=1;
                qur.push({i,j,0});
            }
            else if(st[j]=='B'){
                arr[i][j]=1;
                qub.push({i,j,0});
            }
        }
    }
    int sol=11;
    while(!qur.empty()){
        int xr=qur.front().x;
        int yr=qur.front().y;
        int cnt=qur.front().cnt;
        
        int xb=qub.front().x;
        int yb=qub.front().y;

        qur.pop();
        qub.pop();
        if(cnt>=10) break;

        for(int j=0; j<4; ++j){
            int nxr=xr;
            int nyr=yr;

            int nxb=xb;
            int nyb=yb;

            int flagr=false;
            int flagb=false;
            for(int k=1; k<=dirx[j]; ++k){
                if(arr[nxr+1][nyr] != -1 && arr[nxb+1][nyb] != -1){
                    ++nxr;
                    ++nxb;
                }
                else if(arr[nxr+1][nyr]==-1 && arr[nxb+1][nyb] != -1){
                    if(nyr==nyb && nxr==nxb+1) continue;
                    else ++nxb;
                }
                else if(arr[nxr+1][nyr]!=-1 && arr[nxb+1][nyb] == -1){
                    if(nyr==nyb && nxb==nxr+1) continue;
                    else ++nxr;
                }
                if(arr[nxr][nyr]==0){
                    flagr=true;
                    nxr=0, nyr=0;
                }
                if(arr[nxb][nyb]==0){
                    flagb=true;
                    break;
                }
            }
            for(int k=-1; k>=dirx[j]; --k){
                if(arr[nxr-1][nyr] != -1 && arr[nxb-1][nyb] != -1){
                    --nxr;
                    --nxb;
                }
                else if(arr[nxr-1][nyr]==-1 && arr[nxb-1][nyb] != -1){
                    if(nyr==nyb && nxr==nxb-1) continue;
                    else --nxb;
                }
                else if(arr[nxr-1][nyr]!=-1 && arr[nxb-1][nyb] == -1){
                    if(nyr==nyb && nxb==nxr-1) continue;
                    else --nxr;
                }
                if(arr[nxr][nyr]==0){
                    flagr=true;
                    nxr=0, nyr=0;
                }
                if(arr[nxb][nyb]==0){
                    flagb=true;
                    break;
                }
            }

            for(int k=1; k<=diry[j]; ++k){
                if(arr[nxr][nyr+1] != -1 && arr[nxb][nyb+1] != -1){
                    ++nyr;
                    ++nyb;
                }
                else if(arr[nxr][nyr+1]==-1 && arr[nxb][nyb+1] != -1){
                    if(nxr==nxb && nyr==nyb+1) continue;
                    else ++nyb;
                }
                else if(arr[nxr][nyr+1]!=-1 && arr[nxb][nyb+1] == -1){
                    if(nxr==nxb && nyb==nyr+1) continue;
                    else ++nyr;
                }
                if(arr[nxr][nyr]==0){
                    flagr=true;
                    nxr=0, nyr=0;
                }
                if(arr[nxb][nyb]==0){
                    flagb=true;
                    break;
                }
            }
            for(int k=-1; k>=diry[j]; --k){
                if(arr[nxr][nyr-1] != -1 && arr[nxb][nyb-1] != -1){
                    --nyr;
                    --nyb;
                }
                else if(arr[nxr][nyr-1]==-1 && arr[nxb][nyb-1] != -1){
                    if(nxr==nxb && nyr==nyb-1) continue;
                    else --nyb;
                }
                else if(arr[nxr][nyr-1]!=-1 && arr[nxb][nyb-1] == -1){
                    if(nxr==nxb && nyb==nyr-1) continue;
                    else --nyr;
                }
                if(arr[nxr][nyr]==0){
                    flagr=true;
                    nxr=0, nyr=0;
                }
                if(arr[nxb][nyb]==0){
                    flagb=true;
                    break;
                }
            }
            if(flagb) continue;
            if(flagr){
                sol=min(sol,cnt+1);
            }
            else if(!flagr){
                qur.push({nxr,nyr,cnt+1});
                qub.push({nxb,nyb,cnt+1});
            }
        }
    }
    if(sol==11) cout<<"-1"<<'\n';
    else cout<<sol<<'\n';
    // for(int i=0;i<N;++i){
    //     for(int j=0;j<M;++j){
    //         cout<<arr[i][j];
    //     }
    //     cout<<'\n';
    // }
}
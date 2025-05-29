#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int maximum;
int dirx[4]={20,-20,0,0};
int diry[4]={0,0,20,-20};
void btr(const vector<vector<int>> vec, int cnt, int max_val){
    // for(int i=0; i<vec.size(); ++i){
    //     for(int j=0; j<vec[i].size(); ++j){
    //         cout<<vec[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    // cout<<'\n';
    if(cnt>=5){
        maximum=max(maximum,max_val);
        return;
    }
    for(int idx=0; idx<4; ++idx){// 상하좌우
        vector<vector<int>> newvec=vec;
        // , nvec;
        // for(int i=0; i<vec.size(); ++i){
        //     for(int j=0; j<vec.size(); ++j){
        //         nvec[i].push_back(0);
        //     }
        // }
        if(idx==0){ // 위
            for(int j=0; j<vec.size(); ++j){
                queue<int> qu;
                for(int i=0; i<vec.size(); ++i){
                    qu.push(vec[i][j]);
                }
                int tmpidx=0;
                bool summed=false;
                for(int i=0; i<vec.size(); ++i){
                    if(qu.front()!=0){
                        if(tmpidx==0){
                            newvec[tmpidx][j]=qu.front();
                            ++tmpidx;
                        }
                        else if(!summed && newvec[tmpidx-1][j]==qu.front()){
                            newvec[tmpidx-1][j]+=qu.front();
                            max_val=max(max_val,newvec[tmpidx-1][j]);
                            summed=true;
                        }
                        else{
                            newvec[tmpidx][j]=qu.front();
                            summed=false;
                            ++tmpidx;
                        }
                    }
                    qu.pop();
                }
                for(int i=tmpidx; i<vec.size(); ++i){
                    newvec[i][j]=0;
                }
            }
            btr(newvec, cnt+1, max_val);
        }
        else if(idx==1){ // 아래
            for(int j=0; j<vec.size(); ++j){
                queue<int> qu;
                for(int i=vec.size()-1; i>=0; --i){
                    qu.push(vec[i][j]);
                }
                int tmpidx=vec.size()-1;
                bool summed=false;
                for(int i=vec.size()-1; i>=0; --i){
                    if(qu.front()!=0){
                        if(tmpidx==vec.size()-1){
                            newvec[tmpidx][j]=qu.front();
                            --tmpidx;
                        }
                        else if(!summed && newvec[tmpidx+1][j]==qu.front()){
                            newvec[tmpidx+1][j]+=qu.front();
                            max_val=max(max_val,newvec[tmpidx+1][j]);
                            summed=true;
                        }
                        else{
                            newvec[tmpidx][j]=qu.front();
                            summed=false;
                            --tmpidx;
                        }
                    }
                    qu.pop();
                }
                for(int i=tmpidx; i>=0; --i){
                    newvec[i][j]=0;
                }
            }
            btr(newvec, cnt+1, max_val);
        }
        else if(idx==2){ // 왼
            for(int i=0; i<vec.size(); ++i){
                queue<int> qu;
                for(int j=0; j<vec.size(); ++j){
                    qu.push(vec[i][j]);
                }
                int tmpidx=0;
                bool summed=false;
                for(int j=0; j<vec.size(); ++j){
                    if(qu.front()!=0){
                        if(tmpidx==0){
                            newvec[i][tmpidx]=qu.front(); //혹시문제생기면 j->tmpidx
                            ++tmpidx;
                        }
                        else if(!summed && newvec[i][tmpidx-1]==qu.front()){
                            newvec[i][tmpidx-1]+=qu.front();
                            max_val=max(max_val,newvec[i][tmpidx-1]);
                            summed=true;
                        }
                        else{
                            newvec[i][tmpidx]=qu.front();
                            summed=false;
                            ++tmpidx;
                        }
                    }
                    qu.pop();
                }
                for(int j=tmpidx; j<vec.size(); ++j){
                    newvec[i][j]=0;
                }
            }
            btr(newvec, cnt+1, max_val);
        }
        else if(idx==3){ // 오
            for(int i=0; i<vec.size(); ++i){
                queue<int> qu;
                for(int j=vec.size()-1; j>=0; --j){
                    qu.push(vec[i][j]);
                }
                int tmpidx=vec.size()-1;
                bool summed=false;
                for(int j=vec.size()-1; j>=0; --j){
                    if(qu.front()!=0){
                        if(tmpidx==vec.size()-1){
                            newvec[i][tmpidx]=qu.front(); //혹시문제생기면 j->tmpidx
                            --tmpidx;
                        }
                        else if(!summed && newvec[i][tmpidx+1]==qu.front()){
                            newvec[i][tmpidx+1]+=qu.front();
                            max_val=max(max_val,newvec[i][tmpidx+1]);
                            summed=true;
                        }
                        else{
                            newvec[i][tmpidx]=qu.front();
                            summed=false;
                            --tmpidx;
                        }
                    }
                    qu.pop();
                }
                for(int j=tmpidx; j>=0; --j){
                    newvec[i][j]=0;
                }
            }
            btr(newvec, cnt+1, max_val);
        }
    }
}
int main(){//12100
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    vector<vector<int>> board(N);
    int tmp;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin>>tmp;
            board[i].push_back(tmp);
            maximum=max(maximum,tmp);
        }
    }
    // cout<<'\n';
    btr(board,0,0);
    cout<<maximum<<'\n';
}
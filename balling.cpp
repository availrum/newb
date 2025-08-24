#include<iostream>
using namespace std;
int game(int a, int& ballcount, bool* runner){
    int cnt=0;
    if((a==1 && ballcount==3) || a==2){
        for(int i=3; i>0; --i){
            if(runner[i]){
                if(i==3 && runner[i-1] && runner[i-2]){
                    runner[i]=false;
                    ++cnt;
                }
                else if(i==2 && runner[i-1]){
                    runner[i]=false;
                    runner[i+1]=true;
                }
                else if(i==1) runner[i+1]=true;
            }
        }
        runner[1]=true;
        ballcount=0;
        return cnt;
    }
    ++ballcount;
    if(a==3){
        for(int i=3; i>0; --i){
            if(runner[i]){
                runner[i]=false;
                if(i==3) ++cnt;
                else runner[i+1]=true;
            }
        }
        if(ballcount==4){
            ballcount=0;
            runner[1]=true;
        }
    }
    return cnt;
}
int main(){ //11916
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,t;
    cin>>N;
    int ballcount=0, score=0;
    bool runner[4]={true,};
    for(int i=0; i<N; ++i){
        cin>>t;
        score+=game(t, ballcount, runner);
        // for(int i=1; i<=3; ++i){
        //     cout<<runner[i]<<' ';
        // } cout<<"ballcount="<<ballcount<<", score="<<score<<'\n';
    }
    cout<<score<<'\n';
}
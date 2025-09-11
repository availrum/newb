#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct val{
    int get_score;
    int sol_cnt;
    int id;
};
bool cmp(val a, val b){
    if(a.get_score!=b.get_score) return a.get_score>b.get_score;
    else if(a.sol_cnt!=b.sol_cnt) return a.sol_cnt>b.sol_cnt;
    else return a.id<b.id;
}
int main(){ //5462
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,T,P;
    cin>>N>>T>>P;
    vector<vector<bool>> solve(N+1);
    int score[T]={0,};
    for(int i=1; i<=N; ++i){
        for(int j=0; j<T; ++j){
            bool tmp;
            cin>>tmp;
            solve[i].push_back(tmp);
            if(tmp==0) ++score[j];
        }
    }
    val total_score[N+1]={0,};
    for(int i=1; i<=N; ++i){
        total_score[i].id=i;
        for(int j=0; j<T; ++j){;
            if(solve[i][j]==true){
                total_score[i].get_score+=score[j];
                ++total_score[i].sol_cnt;
            }
        }
    }
    sort(total_score,total_score+N+1,cmp);
    int final_score, final_rank;
    for(int i=0; i<N; ++i){
        if(total_score[i].id==P){
            final_score=total_score[i].get_score;
            final_rank=i+1;
        }
    }
    cout<<final_score<<' '<<final_rank<<'\n';
} 
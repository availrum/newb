#include<iostream>
using namespace std;
int main(){ //2852
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int score[3]={0,}, game_min=0, game_sec=0, winning=0;
    int win[3]={0,};
    pair<int,string> score_time[N];
    for(int i=0; i<N; ++i){
        cin>>score_time[i].first>>score_time[i].second;

        int cur_min, cur_sec;
        string tmp="";
        for(int j=0; j<5; ++j){
            if(j<2) tmp+=score_time[i].second[j];
            else if(j==2){
                cur_min=stoi(tmp);
                tmp="";
            }
            else tmp+=score_time[i].second[j];
        }
        cur_sec=stoi(tmp);

        ++score[score_time[i].first];

        if(winning==score_time[i].first){
            win[winning]+=(60*(cur_min-game_min)+(cur_sec-game_sec));
            game_min=cur_min;
            game_sec=cur_sec;
        }
        else if(winning==0){
            game_min=cur_min;
            game_sec=cur_sec;
            winning=score_time[i].first;
        }
        else{
            win[winning]+=(60*(cur_min-game_min)+(cur_sec-game_sec));
            game_min=cur_min;
            game_sec=cur_sec;
            if(score[1]==score[2]) winning=0;
            else winning=3-score_time[i].first;
        }
    }
    if(winning!=0){
        win[winning]+=(60*(48-game_min)+(0-game_sec));
    }
    if(win[1]/60 < 10) cout<<"0";
    cout<<win[1]/60<<":";
    if(win[1]%60 < 10) cout<<"0";
    cout<<win[1]%60<<'\n';
    if(win[2]/60 < 10) cout<<"0";
    cout<<win[2]/60<<":";
    if(win[2]%60 < 10) cout<<"0";
    cout<<win[2]%60<<'\n';
}
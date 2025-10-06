#include<iostream>
#include<unordered_map>
using namespace std;
int main(){ //2766
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    while(cin>>N){
        if(N==0) break;
        int student[N];
        for(int i=0; i<N; ++i){
            cin>>student[i];
        }
        int game_round=0;
        while(true){
            // cout<<game_round<<" round"<<'\n';
            ++game_round;

            unordered_map<int,int> cnt;
            int addcandy[N];
            for(int i=0; i<N; ++i){
                if(i!=0) addcandy[i]=student[i-1]/2;
                else addcandy[i]=student[N-1]/2;
            }
            for(int i=0; i<N; ++i){
                student[i]/=2;
                student[i]+=addcandy[i];
                if(student[i]%2==1) ++student[i];
                ++cnt[student[i]];
            }
            if(cnt[student[0]]==N){
                cout<<game_round<<' '<<student[0]<<'\n';
                break;
            }
        }
    }
}
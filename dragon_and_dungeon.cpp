#include<iostream>
#include<vector>
#define ll long long int
using namespace std;
struct stage{
    ll type;
    ll power;
    ll life;
};
int main(){ //16434
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N,Hatk;
    cin>>N>>Hatk;
    vector<stage> vec(N);
    ll t,a,h;
    for(int i=0; i<N; ++i){
        cin>>t>>a>>h;
        vec[i]={t,a,h};
    }
    // N개방*한장소당 공격 최대 999,999번 * 최대몬스터공격력 1,000,000 > log(10^17)
    ll min_life=123455876544000001;
    ll st=1, ed=123455876544000001;
    while(st<=ed){
        ll atk=Hatk;
        ll max_life=(st+ed)/2;
        ll life=max_life;

        bool flag=false;
        for(int i=0; i<N; ++i){
            if(vec[i].type==1){
                ll monster_life=vec[i].life;
                ll monster_power=vec[i].power;
                
                ll alive;
                ll need_turn;
                if(life%monster_power!=0) alive=1+life/monster_power;
                else alive=1+life/monster_power;
                if(monster_life%atk!=0) need_turn=1+monster_life/atk;
                else need_turn=monster_life/atk;

                if(need_turn>alive+1){
                    life=0;
                    flag=true;
                }
                else{
                    life-=monster_power*(need_turn-1);
                }
                if(life<=0){
                    flag=true;
                    break;
                }
            }
            else if(vec[i].type==2){
                life+=vec[i].life;
                if(life>max_life) life=max_life;
                atk+=vec[i].power;
            }
        }
        if(flag){
            st=max_life+1;
        }
        else{
            ed=max_life-1;
            min_life=min(min_life,max_life);
        }
    }
    cout<<min_life<<'\n';
}
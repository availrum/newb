#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<unordered_map>
using namespace std;
struct scv{
    int unit1=0;
    int unit2=0;
    int unit3=0;
    int cnt=0;
};
int main(){ //12869
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,t;
    cin>>N;
    // 대강 최대 21일쯤(777)
    // vector<vector<int>> arr(21,vector<int>(N,0));
    scv data;
    cin>>data.unit1;
    if(N>1) cin>>data.unit2;
    if(N>2) cin>>data.unit3;
    queue<scv> qu;
    qu.push(data);
    int sol=-1;
    unordered_map<int,int> check;
    while(!qu.empty()){
        int hp[N]={0,},cur;
        hp[0]=qu.front().unit1;
        if(N>1) hp[1]=qu.front().unit2;
        if(N>2) hp[2]=qu.front().unit3;
        cur=qu.front().cnt;
        qu.pop();

        bool flag0=false;
        for(int i=0; i<N; ++i){
            if(hp[i]<=0) continue;
            flag0=true;
        }
        if(!flag0){
            sol=cur;
            break;
        }
        for(int i=0; i<N; ++i){
            int atk=9;
            scv tmp;
            tmp.cnt=cur+1;
            if(hp[i]<=0) continue;
            tmp.unit1=hp[i]-atk;

            bool flag1=false;
            for(int j=0; j<N; ++j){
                if(i==j) continue;
                if(hp[j]>0) flag1=true;
            }
            if(!flag1){
                int thp[3]={tmp.unit1,tmp.unit2,tmp.unit3};
                sort(thp,thp+3);
                int idx=thp[0]+thp[1]*61+thp[2]*61*61;
                if(check[idx]) continue;
                check[idx]=1;
                qu.push(tmp);
                continue;
            }

            for(int j=0; j<N; ++j){
                if(i==j) continue;
                if(hp[j]<=0) continue;
                atk=3;
                tmp.unit2=hp[j]-atk;
                bool flag2=false;
                for(int k=0; k<N; ++k){
                    if(i==k || j==k) continue;
                    if(hp[k]>0) flag2=true;
                }
                if(!flag2){
                    int thp[3]={tmp.unit1,tmp.unit2,tmp.unit3};
                    sort(thp,thp+3);
                    int idx=thp[0]+thp[1]*61+thp[2]*61*61;
                    if(check[idx]) continue;
                    check[idx]=1;
                    qu.push(tmp);
                    continue;
                }

                for(int k=0; k<N; ++k){
                    if(i==k || j==k) continue;
                    atk=1;
                    tmp.unit3=hp[k]-atk;
                    int thp[3]={tmp.unit1,tmp.unit2,tmp.unit3};
                    sort(thp,thp+3);
                    int idx=thp[0]+thp[1]*61+thp[2]*61*61;
                    if(check[idx]) continue;
                    check[idx]=1;
                    qu.push(tmp);
                }
            }
        }
    }
    cout<<sol<<'\n';
}
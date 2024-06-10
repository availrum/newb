#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;
int main(){//7662
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T,mm,ini,cnt;
    char ins;
    cin>>T;
    for(long int i=0; i<T; i++){
        cnt=0;
        priority_queue<long int> prq;
        priority_queue<long int,vector<long int>,greater<long int>> priq;
        unordered_map<int,int> ma;
        cin>>mm;
        for(long int j=0; j<mm; j++){
            cin>>ins>>ini;
            if(ins=='I') {
                prq.push(ini);
                priq.push(ini);
                cnt++;
                ma[ini]++;
            }
            else if(ins=='D'){
                if(cnt==0){
                    while(!prq.empty()) prq.pop();
                    while(!priq.empty()) priq.pop();
                    unordered_map<int,int> ma;
                }
                else if(cnt>0){
                    if(ini==1) {
                        while(ma[prq.top()]==0){
                            prq.pop();
                        }
                        ma[prq.top()]--;
                        prq.pop();
                    }
                    else if(ini==-1) {
                        while(ma[priq.top()]==0){
                            priq.pop();
                        }
                        ma[priq.top()]--;
                        priq.pop();
                    }
                    cnt--;
                }
            }
            if(cnt==0) {
                while(!prq.empty()) prq.pop();
                while(!priq.empty()) priq.pop();
                unordered_map<int,int> ma;
            }
        }
        // for(int ew=0; ew<priq.size(); ew++){
        //     cout<<prq.top()<<' '<<ma[prq.top()]<<'\n';
        //     prq.pop();
        // }
        if(cnt==0) cout<<"EMPTY"<<'\n';
        else if(cnt==1) {
            if(ma[prq.top()]) cout<<prq.top()<<' '<<prq.top()<<'\n';
            else cout<<priq.top()<<' '<<priq.top()<<'\n';
        }
        else {
            while(ma[prq.top()]==0) prq.pop();
            while(ma[priq.top()]==0) priq.pop(); 
            cout<<prq.top()<<' '<<priq.top()<<'\n';
        }
    }
}
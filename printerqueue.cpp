#include<iostream>
#include<queue>
#include<map>
using namespace std;
int main(){//1966
    int test,N,M,tmp,lo;
    cin>>test;
    for(int i=0; i<test; i++){//test set
        queue<int> pri;
        cin>>N>>M;
        map<int, int> a;
        int cnt=0,j=0;
        for(int j=0; j<N; j++){//input stack
            cin>>tmp;
            a[tmp]++;   // check the number of priority
            pri.push(tmp);
        }
        lo=pri.size();  //to check numbering
        while(test>0){ // need to escape condition 
            if(j>=lo) j-=lo;    //0 1 2 3 4 (5-5)>0 (6-5)>1 (7-5)>2 (8-5)>3 (9-5)>4
            // cout<<pri.front()<<'\n';
            // cout<<j<<'\n';
            for(int k=9; k>0; k--){ // to check other high priority
                if(a[k]!=0){
                    tmp=k;  //current highest priority
                    break;
                }
            }
            // cout<<tmp<<'\n';
            // if(pri.empty()==1) break;   //but theoretically do not need
            if(pri.front()<tmp){    //if other higher priority  - continue
                pri.push(pri.front());
                pri.pop();
                j++;    //numbering add
                continue;
            }
            if(j==M) {
                cnt++;
                // cout<<"kkk"<<'\n';
                break;
            }
            cnt++;
            // cout<<pri.front()<<'\n';
            // cout<<j<<"dd"<<'\n';
            pri.push(0); // maintain current numbering
            pri.pop();
            a[tmp]--;
            j++;
        }
        cout<<cnt<<'\n';
    }
    return 0;
}
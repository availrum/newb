#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>
using namespace std;

int solution(vector<string> friends, vector<string> gifts) {//programers 
    int answer = 0;
    string tmp,tmpr;
    map<string, int>given, get, state, sol;
    
    for(int i=0; i<gifts.size(); i++){
        state[gifts[i]]++;
        stringstream ss(gifts[i]);
        int j=0;
        while(getline(ss,tmp,' ')){
            if(j%2==1)
                get[tmp]++;
            else{
                given[tmp]++;
            }
            j++;
        }
    }
    
    for(int i=0; i<friends.size(); i++){
        for(int j=0; j<friends.size(); j++){
            if(i==j) continue;
            tmp=friends[i]+" "+friends[j];
            tmpr=friends[j]+" "+friends[i];
            if(state[tmp]==state[tmpr] ){
                if(given[friends[j]]-get[friends[j]]==given[friends[i]]-get[friends[i]]) continue;
                if(given[friends[j]]-get[friends[j]]>given[friends[i]]-get[friends[i]]) continue;
                if(given[friends[j]]-get[friends[j]]<given[friends[i]]-get[friends[i]]) {
                    sol[friends[i]]++;
                    continue;
                }
            }
            if(state[tmp]>state[tmpr]){  
                sol[friends[i]]++;
            if(state[tmp]<state[tmpr]) continue;
            cout<<state[tmp]<<' '<<state[tmpr]<<' '<<given[friends[i]]-get[friends[i]] <<' '<<given[friends[j]]-get[friends[j]]<<'\n';
            cout<<"##"<<friends[i]<<' ' <<friends[j]<<'\n';
                continue;
            }
            else continue;
            if(given[friends[j]]-get[friends[j]]>given[friends[i]]-get[friends[i]]) continue;
            if(given[friends[j]]-get[friends[j]]<given[friends[i]]-get[friends[i]]) {
                sol[friends[i]]++;
            cout<<state[tmp]<<' '<<state[tmpr]<<' '<<given[friends[i]]-get[friends[i]] <<' '<<given[friends[j]]-get[friends[j]]<<'\n';
            cout<<friends[i]<<' ' <<friends[j]<<'\n';
            }
            
            
        }
    }
    for(int i=0; i<friends.size(); i++){
        if(sol[friends[i]]>answer) answer=sol[friends[i]];
    }
    // answer=state[friends[1]+" "+friends[0]];
    return answer;
}
int main(){
    int k;
    vector<string> a,b;
    a.push_back("muzi");
    a.push_back("ryan");
    a.push_back("frodo");
    a.push_back("neo");
    b.push_back("muzi frodo");
    b.push_back("muzi frodo");
    b.push_back("ryan muzi");
    b.push_back("ryan muzi");
    b.push_back("ryan muzi");
    b.push_back("frodo muzi");
    b.push_back("frodo ryan");
    b.push_back("neo muzi");
    k=solution(a,b);
    cout<<"answer is "<<k<<'\n';
    // return 0;
}
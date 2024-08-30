#include<iostream>
#include<unordered_map>
using namespace std;
int main(){//26069
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,cnt=1;
    cin>>N;
    unordered_map<string,int> ma;
    ma["ChongChong"]=1;
    string st1,st2;
    for(int i=0; i<N; ++i){
        cin>>st1>>st2;
        if(ma[st1] && !ma[st2]){
            ma[st2]=1;
            ++cnt;
        }
        else if(!ma[st1] && ma[st2]){
            ma[st1]=1; 
            ++cnt;
        }
    }
    cout<<cnt<<'\n';
}
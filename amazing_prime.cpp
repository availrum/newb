#include<iostream>
#include<vector>
using namespace std;
bool isprime(int n){
    if(n<=1) return false;
    for(int i=2; i*i<=n; ++i){
        if(n%i==0) return false;
    }
    return true;
}
void rec(int n, vector<int> num){
    bool flag=false;
    string tmp="";
    for(int idx=0; idx<num.size(); ++idx){
        tmp+=(char)(num[idx]+'0');
        // cout<<tmp<<'\n';
        if(!isprime(stoi(tmp))) return;
    }
    if(num.size()==n){
        cout<<tmp<<'\n';
        return;
    }
    for(int i=0; i<10; ++i){
        if(i==0 && tmp=="") continue;
        num.push_back(i);
        rec(n,num);
        num.pop_back();
    }
}
int main(){ //2023
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    vector<int> num;
    rec(N,num);
}
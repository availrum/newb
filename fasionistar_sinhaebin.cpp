#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int main(){//9375
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,t;
    cin>>t;
    for(int i=0; i<t; ++i){
        cin>>N;
        string tmp1,tmp2;
        if(N==1){
            cin>>tmp1>>tmp2;
            cout<<"1"<<'\n';
            continue;
        }
        unordered_map<string,int> ma;
        vector<string> vec;
        for(int j=0; j<N; ++j){
            cin>>tmp1>>tmp2;
            if(ma[tmp2]==0) vec.push_back(tmp2);
            ++ma[tmp2];
        }
        int sol=1;
        for(int j=0; j<vec.size(); ++j) sol*=(ma[vec[j]]+1);
        --sol;
        cout<<sol<<'\n';
    }
}
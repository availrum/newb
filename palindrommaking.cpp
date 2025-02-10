#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
int main(){//1213
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string st;
    cin>>st;
    unordered_map<char, int> check, checkdouble;
    for(int i=0; i<st.size(); ++i){
        ++check[st[i]];
    }
    bool flag=false;
    vector<char> vec;
    for(int i=0; i<st.size(); ++i){
        if(!checkdouble[st[i]]){
            checkdouble[st[i]]=check[st[i]];
            vec.push_back(st[i]);
            if(check[st[i]]%2==1){
                if(flag){
                    cout<<"I'm Sorry Hansoo"<<'\n';
                    return 0;
                }
                flag=true;
            }
        }
    }
    sort(vec.begin(), vec.end());
    string sol="";
    char center=0;
    stack<char> stac;
    for(int i=0; i<vec.size(); ++i){
        int x=check[vec[i]];
        if(x%2==0){
            for(int j=0; j<x/2; ++j){
                sol+=vec[i];
                stac.push(vec[i]);
            }
        }
        else{
            center=vec[i];
            for(int j=0; j<(x-1)/2; ++j){
                sol+=vec[i];
                stac.push(vec[i]);
            }
        }
    }
    if(center!=0) sol+=center;
    while(!stac.empty()){
        sol+=stac.top();
        stac.pop();
    }
    cout<<sol<<'\n';
}
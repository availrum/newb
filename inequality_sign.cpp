#include<iostream>
#include<vector>
#define ll long long int
using namespace std;
string min_value="10000000000",max_value="0";
bool check(vector<char>& ies, vector<int> vec){
    bool flag=true;
    // for(int i=0; i<vec.size(); ++i) cout<<vec[i];
    // cout<<'\n';
    for(int i=1; i<vec.size(); ++i){
        if(ies[i-1]=='<' && vec[i-1]>=vec[i]) flag=false;
        else if(ies[i-1]=='>' && vec[i-1]<=vec[i]) flag=false;
    }
    if(flag) return true;
    else return false;
}
void rec(vector<char>& ies, vector<int> vec){
    if(vec.size()>ies.size()){
        if(!check(ies,vec)) return;
        string tmp="";
        for(int i=0; i<vec.size(); ++i) tmp+=to_string(vec[i]);
        if(stoll(min_value)>stoll(tmp)) min_value=tmp;
        if(stoll(max_value)<stoll(tmp)) max_value=tmp;
        // cout<<vec[i];
        // cout<<'\n';
        return;
    }
    if(!check(ies,vec)) return;
    bool used[10]={false,};
    for(int i=0; i<vec.size(); ++i){
        used[vec[i]]=true;
    }
    for(int i=0; i<10; ++i){
        if(used[i]) continue;
        vec.push_back(i);
        rec(ies,vec);
        vec.pop_back();
    }
}
int main(){ //2529
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k;
    cin>>k;
    vector<char> ies(k);
    vector<int> vec;
    for(int i=0; i<k; ++i){
        cin>>ies[i];
    }
    rec(ies,vec);
    cout<<max_value<<'\n';
    cout<<min_value<<'\n';
}
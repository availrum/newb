#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
unordered_map<string,int> ma;
bool order(string a, string b){
    if(ma[a] > ma[b]) return true;
    else if(ma[a] < ma[b]) return false;
    else if(a.length() > b.length()) return true;
    else if(a.length() < b.length()) return false;
    else if(a < b) return true;
    else return false;
}
int main(){//20920
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    string st;
    vector<string> vec;
    for(int i=0; i<N; ++i){
        cin>>st;
        if(st.length() < M) continue;
        if(ma[st]==0) vec.push_back(st);
        ++ma[st];
    }
    sort(vec.begin(), vec.end(), order);
    // cout<<'\n';
    for(int i=0; i<vec.size(); ++i) cout<<vec[i]<<'\n';
}
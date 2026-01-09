#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int N,M;
set<vector<int>> check;
vector<vector<int>> sol;
void rec(vector<int>& arr, vector<int> seq){
    if(seq.size()==M){
        if(check.find(seq)!= check.end()) return;
        check.insert(seq);
        sol.push_back(seq);
        return;
    }
    for(int i=0; i<arr.size(); ++i){
        seq.push_back(arr[i]);
        rec(arr,seq);
        seq.pop_back();
    }
}
int main(){ //15665
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    vector<int> arr;
    int t;
    set<int> check_tmp;
    for(int i=0; i<N; ++i){
        cin>>t;
        if(check_tmp.find(t)!=check_tmp.end()) continue;
        arr.push_back(t);
        check_tmp.insert(t);
    }
    vector<int> seq;
    rec(arr,seq);
    sort(sol.begin(), sol.end());
    for(int i=0; i<sol.size(); ++i){
        for(int j=0; j<sol[i].size(); ++j){
            if(j!=0) cout<<' ';
            cout<<sol[i][j];
        }
        cout<<'\n';
    }
}
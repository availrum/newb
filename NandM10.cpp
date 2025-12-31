#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int N,M;
set<string> check;
void rec(vector<int>& arr, int n, vector<int> seq){
    if(seq.size()==M){
        string tmp="";
        for(int i=0; i<M; ++i) tmp+=to_string(seq[i]);
        if(check.find(tmp)!= check.end()) return;
        check.insert(tmp);
        for(int i=0; i<M; ++i){
            cout<<seq[i];
            if(i!=M-1) cout<<' ';
            else cout<<'\n';
        }
        return;
    }
    for(int i=n; i<N; ++i){
        seq.push_back(arr[i]);
        rec(arr,i+1,seq);
        seq.pop_back();
    }
}
int main(){ //15664
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    vector<int> arr(N);
    for(int i=0; i<N; ++i){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());

    vector<int> seq;
    rec(arr,0,seq);
    // for(int i=0; i<N; ++i) cout<<arr[i]<<' ';
    // cout<<'\n';
}
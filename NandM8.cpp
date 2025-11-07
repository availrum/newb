#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
int N,M;
unordered_map<string,int> check; //범위가 작아서 가라로 될듯? 문자열 글자수 40(5글자*8)
void btr(int* arr, int cur, vector<int> vec){
    if(vec.size()==M){
        string tmp="";
        for(int i=0; i<M; ++i) tmp+=to_string(vec[i]);
        if(check[tmp]) return;
        // cout<<tmp<<'\n';
        for(int i=0; i<M; ++i){
            cout<<vec[i];
            if(i!=M-1) cout<<' ';
            else cout<<'\n';
        }
        ++check[tmp];
        return;
    }
    for(int i=cur; i<N; ++i){
        vec.push_back(arr[cur]);
        btr(arr,i,vec);
        vec.pop_back();
    }
}
int main(){ //15657
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    int arr[N];
    for(int i=0; i<N; ++i){
        cin>>arr[i];
    }
    vector<int> vec;
    sort(arr,arr+N);
    for(int i=0; i<N; ++i) btr(arr,i,vec);
}
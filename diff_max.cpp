#include<iostream>
#include<vector>
using namespace std;
int N,max_val;
void btr(int* origin, vector<int> arr, vector<bool> check){
    if(arr.size()==N){
        int val=0;
        for(int i=1; i<N; ++i){
            val+=abs(arr[i]-arr[i-1]);
        }
        max_val=max(max_val,val);
        return;
    }
    for(int i=0; i<N; ++i){
        if(check[i]) continue;
        arr.push_back(origin[i]);
        check[i]=true;
        btr(origin, arr, check);
        arr.pop_back();
        check[i]=false;
    }
}
int main(){ //10819
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    int origin[N];
    vector<int> arr;
    vector<bool> check(N,false);
    for(int i=0; i<N; ++i){
        cin>>origin[i];
    }
    btr(origin, arr, check);
    cout<<max_val<<'\n';
} 
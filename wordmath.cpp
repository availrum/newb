#include<iostream>
#include<unordered_map>
#include<cmath>
#include<algorithm>
using namespace std;
unordered_map<char,int> cnt;
int cmp(int a, int b){
    return cnt[a]>=cnt[b];
}
int main(){//1339
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,t;
    cin>>N;
    int idx=0;
    int arr[10]={0,};
    string input_arr[N];
    for(int i=0; i<N; ++i){
        cin>>input_arr[i];
        for(int j=0; j<input_arr[i].length(); ++j){
            if(!cnt[input_arr[i][j]]){
                arr[idx]=input_arr[i][j];
                ++idx;
            }
            cnt[input_arr[i][j]]+=pow(10,input_arr[i].length()-1-j);
        }
    }
    sort(arr,arr+10,cmp);
    unordered_map<char,int> number;
    int val=9;
    for(int i=0; i<10; ++i){
        if(!arr[i]) break;
        number[arr[i]]=val;
        --val;
    }
    int tot=0;
    for(int i=0; i<N; ++i){
        for(int j=0; j<input_arr[i].length(); ++j){
            tot+=number[input_arr[i][j]]*pow(10,input_arr[i].length()-1-j);
        }
    }
    cout<<tot<<'\n';
}
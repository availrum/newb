#include<iostream>
#include<vector>
using namespace std;
int main(){ //6219
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int A,B,D;
    cin>>A>>B>>D;
    vector<bool> arr(B+1,true);
    for(int i=2; i*i<=B; ++i){
        for(int j=2; i*j<=B; ++j){
            arr[i*j]=false;
        }
    }
    int cnt=0;
    for(int i=A; i<=B; ++i){
        if(arr[i]){
            string tmp=to_string(i);
            bool flag=false;
            for(int j=0; j<tmp.length(); ++j){
                if((tmp[j]-'0')==D) flag=true;
            }
            if(flag) ++cnt;
        }
    }
    cout<<cnt<<'\n';
}
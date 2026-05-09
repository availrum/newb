#include<iostream>
#include<vector>
using namespace std;
int rfib(int num, vector<int>& arr){
    if(arr[num]!=0) return arr[num];
    int tmp1=rfib(num-1,arr);
    int tmp2=rfib(num-2,arr);
    int tmp=tmp2-tmp1;
    return arr[num]=tmp;
}
int main(){ //2502
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int D,K,A,B;
    cin>>D>>K;
    for(int i=2*K; i>=K; --i){
        vector<int> arr(D+1,0);
        bool flag=true;
        arr[1]=K;
        arr[0]=i;
        rfib(D,arr);
        for(int j=2; j<=D; ++j){
            if(arr[j]<=arr[j-1] && arr[j]>0) continue;
            flag=false;
        }
        if(flag){
            A=arr[D];
            B=arr[D-1];
            cout<<A<<'\n'<<B<<'\n';
            return 0;
        }
    }
}
#include<iostream>
#include<vector>
using namespace std;
int main(){//1644
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int check[N+1]={0,};
    for(int i=2; i*i<=N; ++i){
        if(check[i]) continue;
        for(int j=i; i*j<=N; ++j){
            if(check[i*j]) continue;
            check[i*j]=1;
        }
    }
    vector<int> vec;
    //판별과정에서 투포인터계산하면 단축가능
    for(int i=2; i<=N; ++i){
        // if(!check[i]) cout<<i<<' ';
        if(!check[i]) vec.push_back(i);
    }
    // cout<<'\n';
    if(N==1){
        cout<<"0"<<'\n';
        return 0;
    }
    int st=0, ed=0, sum=vec[0], cnt=0;
    while(ed<vec.size()){
        if(sum==N){
            ++cnt;
            sum-=vec[st];
            ++st;
            ++ed;
            sum+=vec[ed];
        }
        else if(sum<N){
            ++ed;
            sum+=vec[ed];
        }
        else if(sum>N){
            sum-=vec[st];
            ++st;
        }
        // cout<<sum<<'\n';
    }
    cout<<cnt<<'\n';
}
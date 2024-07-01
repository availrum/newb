#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){//14002
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    vector<int> pos(N+1,0);
    vector<int> trace(N+1,0);
    int arr[N+1], val[N+1]={0,}, idx=0;
    for(int i=1; i<=N; ++i) cin>>arr[i];
    arr[0]=-1000000001;
    val[0]=-1000000001;
    for(int i=1; i<=N; ++i){
        if(arr[i]>val[idx]){    //이번에 넣는 값이 개수 최대의 값보다 크면
            ++idx;
            val[idx]=arr[i];
            pos[idx]=i;
            trace[i]=pos[idx-1];
            continue;
        }
        int st=1,ed=idx,mid=(st+ed)/2;
        while(st<=ed){
            mid=(st+ed)/2;
            if(arr[i]<=val[mid]) ed=mid-1;
            else st=mid+1;
        }
        val[st]=arr[i];
        pos[st]=i;
        trace[i]=pos[st-1];
    }
    cout<<idx<<'\n';
    vector<int> lis;
    for (int i=pos[idx]; i!=0; i=trace[i]) lis.push_back(arr[i]);
    reverse(lis.begin(), lis.end());
    for (int i=0; i<lis.size(); ++i) {
        cout<<lis[i];
        if (i != lis.size()-1) cout<<' ';
    }
    cout<<'\n';
}
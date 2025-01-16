#include<iostream>
#include<algorithm>
using namespace std;
int main(){//2110
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, C;
    cin>>N>>C;
    int house[N];
    for(int i=0; i<N; ++i){
        cin>>house[i];
    }
    sort(house,house+N);
    
    int maxdist=0;
    int st=1, ed=house[N-1]-house[0];
    while(st<=ed){
        int cnt=1, cur=house[0];
        int mid=(st+ed)/2;
        for(int i=1; i<N; ++i){
            if(house[i]>=cur+mid){
                ++cnt;
                cur=house[i];
            }
        }
        if(cnt>=C){
            st=mid+1;
            maxdist=max(maxdist,mid);
        }
        else{
            ed=mid-1;
        }
    }
    cout<<maxdist<<'\n';
}
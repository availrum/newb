#include<iostream>
using namespace std;
int main(){//2096
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int arr[3],maxi[3],mini[3],tmax[3],tmin[3];
    for(int i=0; i<N; ++i){
        cin>>arr[0]>>arr[1]>>arr[2];
        if(i==0){
            for(int j=0; j<3; ++j){
                maxi[j]=arr[j];
                mini[j]=arr[j];
            }
        }
        else if(i>0){
            for(int j=0; j<3; ++j){
                tmax[j]=maxi[j];
                tmin[j]=mini[j];
            }
            mini[0]=min(tmin[0],tmin[1])+arr[0];
            mini[1]=min(min(tmin[0],tmin[1]),tmin[2])+arr[1];
            mini[2]=min(tmin[1],tmin[2])+arr[2];

            maxi[0]=max(tmax[0],tmax[1])+arr[0];
            maxi[1]=max(max(tmax[0],tmax[1]),tmax[2])+arr[1];
            maxi[2]=max(tmax[1],tmax[2])+arr[2];
        }
    }
    // for(int i=0; i<3; ++i) cout<<maxi[i]<<' ';
    // cout<<'\n';
    int maximum=max(max(maxi[0],maxi[1]),maxi[2]);
    int minimum=min(min(mini[0],mini[1]),mini[2]);
    cout<<maximum<<' '<<minimum<<'\n';
}
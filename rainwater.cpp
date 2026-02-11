#include<iostream>
using namespace std;
int main(){ //14719
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int H,W;
    cin>>H>>W;
    int arr[W];
    pair<int,int> highest={0,-1};
    for(int i=0; i<W; ++i){
        cin>>arr[i];
        if(arr[i]>highest.first || highest.second==-1) highest={arr[i],i};
    }
    int left=-1,right=-1, total_water1=0, total_water2=0, cur_water=0;
    for(int i=0; i<W; ++i){
        if(left==highest.second) break;
        if(left==-1){
            if(arr[i]==0) continue;
            else left=i;
        }
        else if(arr[i]<arr[left]){ //left>arr[i]
            cur_water+=(arr[left]-arr[i]);
        }
        else{
            total_water1+=cur_water;
            cur_water=0;
            left=i;
        }
    }
    cur_water=0;
    for(int i=W-1; i>=0; --i){
        if(right==highest.second) break;
        if(right==-1){
            if(arr[i]==0) continue;
            else right=i;
        }
        else if(arr[i]<arr[right]){ //arr[i]<right
            cur_water+=(arr[right]-arr[i]);
        }
        else{
            total_water2+=cur_water;
            cur_water=0;
            right=i;
        }
    }
    // cout<<total_water1<<' '<<total_water2<<'\n';
    cout<<total_water1+total_water2<<'\n';
}
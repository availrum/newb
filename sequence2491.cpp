#include<iostream>
#include<vector>
using namespace std;
int main(){ //2491
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,t;
    cin>>N;
    vector<int> arr(N);
    for(int i=0; i<N; ++i){
        cin>>arr[i];
    }
    int max_leng=1;
    int st=0,ed=1;
    while(ed<N){
        if(arr[ed-1]<=arr[ed]){
            max_leng=max(max_leng,(ed-st+1));
            ++ed;
        }
        else{
            st=ed;
            ++ed;
        }
    }
    st=0,ed=1;
    while(ed<N){
        if(arr[ed-1]>=arr[ed]){
            max_leng=max(max_leng,(ed-st+1));
            ++ed;
        }
        else{
            st=ed;
            ++ed;
        }
    }
    cout<<max_leng<<'\n';
}
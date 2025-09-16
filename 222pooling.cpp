#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int rec(vector<vector<int>>& arr, int x, int y, int n){
    if(n==1){
        return arr[x][y];
    }
    int value[4];
    value[0]=rec(arr, x, y, n/2);
    value[1]=rec(arr, x, y+n/2, n/2);
    value[2]=rec(arr, x+n/2, y, n/2);
    value[3]=rec(arr, x+n/2, y+n/2, n/2);
    sort(value,value+4);
    return value[2];
}
int main(){ // 17829
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    vector<vector<int>> arr(N);
    int tmp;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin>>tmp;
            arr[i].push_back(tmp);
        }
    }
    int sol=rec(arr,0,0,N);
    cout<<sol<<'\n';
}
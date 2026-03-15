#include<iostream>
#include<vector>
using namespace std;
int main(){ //16395
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,k;
    cin>>N>>k;
    vector<vector<int>> triangle(N+1,vector<int>(N+1,1));
    for(int i=2; i<=N; ++i){
        for(int j=1; j<i; ++j){
            triangle[i][j]=triangle[i-1][j-1]+triangle[i-1][j];
        }
    }
    cout<<triangle[N-1][k-1]<<'\n';
}
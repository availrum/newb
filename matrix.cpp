#include<iostream>
#include<vector>
using namespace std;
int main(){ //1080
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    vector<vector<int>> arr1(N,vector<int>(M)),arr2(N,vector<int>(M));
    for(int i=0; i<2*N; ++i){
        string st;
        cin>>st;
        if(i<N){
            for(int j=0; j<st.length(); ++j){
                arr1[i][j]=(st[j]-'0');
            }
        }
        else{
            for(int j=0; j<st.length(); ++j){
                arr2[i-N][j]=(st[j]-'0');
            }
        }
    }
    int cnt=0;
    for(int i=0; i<N-2; ++i){
        for(int j=0; j<M-2; ++j){
            if(arr1[i][j]==arr2[i][j]) continue;
            for(int k=0; k<3; ++k){
                for(int l=0; l<3; ++l){
                    arr1[i+k][j+l]=1-arr1[i+k][j+l];
                }
            }
            ++cnt;
        }
    }
    bool flag=false;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(arr1[i][j]!=arr2[i][j]){
                flag=true;
                break;
            }
        }
        if(flag) break;
    }
    if(flag) cout<<"-1\n";
    else cout<<cnt<<'\n';
    // for(int i=0; i<N; ++i) {
    //     for(int j=0; j<M; ++j)cout<<arr2[i][j];
    //     cout<<'\n';
    // }
}
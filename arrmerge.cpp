#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){//11728
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    vector<int> vec;
    // int arr1[N]={0,}, arr2[M]={0,};
    int tmp;
    for(int i=0; i<N; ++i){
        cin>>tmp;
        vec.push_back(tmp);
    }
    for(int i=0; i<M; ++i){
        cin>>tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end());
    for(int i=0; i<N+M; ++i){
        cout<<vec[i];
        if(i!=N+M-1) cout<<' ';
        else cout<<'\n';
    }
    
}
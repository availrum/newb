#include<iostream>
#include<vector>
using namespace std;
int main(){ //29759
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,t;
    cin>>N;
    int max_value=1000000; 
    N*=N;
    vector<bool> check(max_value+1, false);
    vector<int> used;

    int arr[N][N];
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin>>t;
            arr[i][j]=t;
            if(t!=0) used.push_back(t); // 이미 사용된 숫자
        }
    }

    //O(NlogN - N~=10000)
    for(int i=0; i<used.size(); ++i){ // 사용된 숫자가 특정 소수의 배수일때
        int x=used[i];
        for(int j=2; j*j<=x; ++j){
            while(x%j==0){
                x/=j;
                check[x]=true;
                check[j]=true;
            }
        }
        check[x]=true;
    }
    for(int i=2; i*i<=max_value; ++i){ // 소수가 아닌것 제외
        for(int j=i*i; j<=max_value; j+=i){
            check[j]=true;
        }
    }
    vector<int> prime;
    for(int i=2; i<=max_value; ++i){ // 서로소인 소수만
        if(!check[i]) prime.push_back(i);
    }

    int idx=0;
    // 그냥 0인 부분 전부 서로소인 소수를 넣으면 문제 해결?
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(arr[i][j]==0){
                arr[i][j]=prime[idx];
                ++idx;
            }
        }
    }

    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cout<<arr[i][j];
            if(j!=N-1) cout<<' ';
            else cout<<'\n';
        }
    }
}
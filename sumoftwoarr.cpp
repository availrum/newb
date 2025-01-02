#include<iostream>
#include<unordered_map>
using namespace std;
int main(){//2143
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin>>T;

    int n;
    cin>>n;
    int arr1[n];
    for(int i=0; i<n; ++i){
        cin>>arr1[i];
    }
    unordered_map<int,int> check;
    for(int i=0; i<n; ++i){
        int tmp=0;
        for(int j=i; j<n; ++j){
            tmp+=arr1[j];
            ++check[tmp];
        }
    }

    int m;
    cin>>m;
    int arr2[m];
    for(int i=0; i<m; ++i){
        cin>>arr2[i];
    }
    long long int sol=0;
    for(int i=0; i<m; ++i){
        int tmp=0;
        for(int j=i; j<m; ++j){
            tmp+=arr2[j];
            if(check[T-tmp]){
                sol+=check[T-tmp];
                // cout<<T-tmp<<" , num="<<check[T-tmp]<<'\n';
            }
        }
    }
    cout<<sol<<'\n';
}
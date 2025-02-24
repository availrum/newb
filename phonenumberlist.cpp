#include<iostream>
#include<unordered_map>
using namespace std;
int main(){//5052
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    for(int tcase=0; tcase<t; ++tcase){
        unordered_map<string, int> check;
        int n;
        cin>>n;
        string arr[n];
        for(int i=0; i<n; ++i){
            cin>>arr[i];
            ++check[arr[i]];
        }
        bool flag=false;
        for(int i=0; i<n; ++i){
            string tmp="";
            for(int j=0; j<arr[i].length()-1; ++j){
                tmp+=arr[i][j];
                if(check[tmp]){
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag) cout<<"NO"<<'\n';
        else cout<<"YES"<<'\n';
    }
}
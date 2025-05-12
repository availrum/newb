#include<iostream>
#include<vector>
using namespace std;
void rec(int* arr, vector<int>& sol, int idx, int k){
    if(sol.size()==6){
        for(int i=0; i<sol.size(); ++i){
            cout<<sol[i];
            if(i!=sol.size()-1) cout<<' ';
            else cout<<'\n';
        }
        return;
    }
    if(6-sol.size()>k-idx) return;
    for(int i=idx; i<k; ++i){
        sol.push_back(arr[i]);
        rec(arr, sol, i+1, k);
        sol.pop_back();
    }
}
int main(){//6603
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k;
    bool flag=false;
    while(cin>>k){
        if(k==0) break;
        if(flag) cout<<'\n';
        int arr[k];
        for(int i=0; i<k; ++i){
            cin>>arr[i];
        }
        vector<int> vec;
        rec(arr, vec, 0, k);
        flag=true;
    }
}
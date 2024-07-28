#include<iostream>
#include<unordered_map>
using namespace std;
int main(){//30804
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int arr[N]={0,};
    for(int i=0; i<N; ++i) cin>>arr[i];
    int li=0, ri=0, maxi=0;
    unordered_map<int, int> check;
    while(ri<N){
        ++check[arr[ri]];
        while(check.size()>2){
            --check[arr[li]];
            if(check[arr[li]]==0) check.erase(arr[li]);
            ++li;
        }
        maxi=max(maxi, ri-li+1);
        ++ri;
    }
    cout<<maxi<<'\n';
}
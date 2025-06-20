#include<iostream>
#include<algorithm>
using namespace std;
int main(){ //2512
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int budget[N],max_value=0;
    for(int i=0; i<N; ++i){
        cin>>budget[i];
        max_value=max(max_value,budget[i]);
    }
    int total_budget;
    cin>>total_budget;

    sort(budget,budget+N);

    int st=1, ed=max_value;
    int max_budget=0;
    while(st<=ed){
        int mid=(st+ed)/2;
        int cur_budget=0;
        for(int i=0; i<N; ++i){
            if(mid>=budget[i]){
                cur_budget+=budget[i];
            }
            else cur_budget+=mid;
        }
        // cout<<"curmax="<<mid<<" cur="<<cur_budget<<'\n';

        if(total_budget<cur_budget){
            ed=mid-1;
        }
        else{
            st=mid+1;
            max_budget=max(max_budget,mid);
        }
    }
    cout<<max_budget<<'\n';
}
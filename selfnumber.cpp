#include<iostream>
#include<vector>
using namespace std;
bool non_self_num[10001];
int main(){//4673
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N=10000;
    for(int i=1; i<=N; ++i){
        int j=1000;
        int tmp=i, cal=i;
        while(j>=1){
            tmp+=cal/j;
            cal=cal%j;
            j/=10;
        }
        if(tmp>10000) continue;
        non_self_num[tmp]=true;
    }
    for(int i=1; i<=N; ++i){
        if(!non_self_num[i]){
            cout<<i<<'\n';
        }
    }
}
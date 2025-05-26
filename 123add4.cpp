#include<iostream>
using namespace std;
int main(){//15989
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int tcase=0; tcase<T; ++tcase){
        int n;
        cin>>n;
        //  1+3과 3+1이 같음 
        //  10>>6(3안쓸때 22222,222211,2221111,22111111,211111111,1111111111)
        //  현재 수의 2의 개수(k/2)+1번
        //  + 7>>4(3한번쓸때) + 4>>3(3두번쓸때) + 1>>1(3세번쓸때)  
        int cnt=0;
        for(int i=0; 3*i<=n; ++i){
            int remain=n-3*i;
            cnt+=(remain/2+1);
        }
        cout<<cnt<<'\n';
    }
} 
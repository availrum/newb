#include<iostream>
#include<cmath>
#define ll long long int
using namespace std;
int main(){ //11815
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    for(int tcase=0; tcase<N; ++tcase){
        ll X;
        cin>>X;
        ll root_value=pow(X,0.5);
        // 결국 2개 쌍의 곱으로 표현하게 된다.
        // 홀수가 되는 경우는 제곱근이 정수인경우 (2*2=4(1-4,2-2), 7*7=49(1-49,7-7))

        if(root_value*root_value==X) cout<<"1";
        else cout<<"0";
        if(tcase!=N-1) cout<<' ';
        else cout<<'\n';
    }
}
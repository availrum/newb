#include<iostream>
#include<cmath>
using namespace std;
int main(){ //1011
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int tcase=0; tcase<T; ++tcase){
        int x,y;
        cin>>x>>y;
        // 1 2 3 4 5 6 7 8 9 10 9 8 7 6 5 4 3 2 1 >> 45+10+45>100
        // (n+1)n/2 + n(n-1)/2 = n^2
        // 110 > 110-100, 10에서 1회
        // 120 > 120-100, 10에서 2회
        // 121 > 10-(11-10) 경로 추가 2회
        // 132 > 121에서 11한번더 경유(+1)
        // 최고점 아래를 몇번 더 경유하냐로 나눌수있음
        // 1*1< ... <=2*2< ... <=3*3< ... <=n*n
        // [1(1)] [2(1+1)] [3(1+1+1) 4(1+2+1)] [5(1+2+1+1) 6(1+2+2+1)] 
        // [7(1+2+2+1+1) 8(1+2+2+2+1) 9(1+2+3+2+1)]
        // 
        int dif=y-x;
        int n=pow(dif,0.5);
        dif-=n*n;

        int warp_cnt=2*n-1;

        warp_cnt+=(dif+n-1)/n;
        
        cout<<warp_cnt<<'\n';
    }
}
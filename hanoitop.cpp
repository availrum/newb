#include<iostream>
#include<cmath>
using namespace std;
void rec(int n, int a, int b, int c){//n-1층을 쌓고 n-2층을 쌓고 -> 0층까지 반복한다- 짝/홀 단위로 포함(목적지에 두는 루트가 다르기때문)
    if(n==0) return; //
    else {
        rec(n-1,a,c,b); //이전과는 다른 기둥에 옮긴다. -n이 짝수일땐 홀수는 중간기둥 / 홀수일땐 마지막기둥
        //ex>>(2- 1번 3번 2번)-1번 2번 출력 -1(1- 1번 2번 3번>1,3) -2(1- 3번 1번 2번>3,2)
        cout<<a<<' '<<c<<'\n'; 
        //ex>>1번 3번 출력
        rec(n-1,b,a,c);//최종이 아니면 다른 기둥에 정리한다
        //ex>>(2번 1번 3번)-2번 3번 출력
    }
}
int main(){//11729
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int cal=pow(2,n)-1;//최단횟수는 2^n -1이다
    cout<<cal<<'\n';
    rec(n,1,2,3);//기둥번호를 123으로
}
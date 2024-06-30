#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
void rec(int n, int a, int b, int c){//n-1층을 쌓고 n-2층을 쌓고 -> 0층까지 반복한다- 짝/홀 단위로 포함(목적지에 두는 루트가 다르기때문)
    if(n==0) return;
    else {
        rec(n-1,a,c,b); //이전과는 다른 기둥에 옮긴다. -n이 짝수일땐 홀수는 중간기둥 / 홀수일땐 마지막기둥
        //ex>>(2- 1번 3번 2번)-1번 2번 출력 -1(1- 1번 2번 3번>1,3) -2(1- 3번 1번 2번>3,2)
        cout<<a<<' '<<c<<'\n'; 
        //ex>>1번 3번 출력
        rec(n-1,b,a,c);//최종이 아니면 다른 기둥에 정리한다
        //ex>>(2번 1번 3번)-2번 3번 출력
    }
}
int main(){//1914
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,tmpi;
    long long int cal, a;
    char ch;
    string tmp;
    cin>>n;
    if (n>20 && n<=60) {
        cal=pow(2,n);//최단횟수는 2^n -1이다
        --cal;
        cout<<cal<<'\n';
    }
    else if (n>60) {
        a=pow(2,60);
        int b=n-60;
        string tmp=to_string(a);
        // cout<<tmp<<'\n';
        for(int i=0; i<b; ++i){
            string tmp_st="";
            int up=0;
            // cout<<tmp[tmp.length()-1];
            for(int j=tmp.length()-1; j>=0; --j){
                int tmp_num=2*(tmp[j]-48)+up;
                // cout<<' '<<tmp_num<<' ';
                up=0;

                //2의 배수는 (2) 4 8 16 3 (2) 주기로 1을 빼도 앞 자리가 변하지 않는다.
                if(i==b-1 && j==tmp.length()-1) --tmp_num;

                if(tmp_num >= 10){
                    // cout<<"ddd"<<'\n';
                    tmp_num-=10;
                    tmp_st+=char(tmp_num+48);
                    ++up;
                }
                else tmp_st+=char(tmp_num+48);
                
            }
            if(up!=0) tmp_st+=char(up+48);
            tmp=tmp_st;
            // cout<<tmp<<'\n';
            reverse(tmp.begin(), tmp.end());
        }
        cout<<tmp<<'\n';
    }
    else if(n<=20){
        cal=pow(2,n);
        --cal;
        cout<<cal<<'\n';
        rec(n,1,2,3);//기둥번호를 123으로
    }
}
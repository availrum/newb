#include<iostream>
#define ll long long int
using namespace std;
ll gcd(ll num1, ll num2){
    if(num1<num2) swap(num1,num2);
    while(num1%num2!=0){
        ll tmp=num1%num2;
        num1=num2;
        num2=tmp;
    }
    return num2;
}
ll getinv(ll A, ll divid , ll& x, ll& y){
    if(A==0){
        x=0;
        y=1;
        return y;
    }
    ll tmpx, tmpy;
    ll gcd=getinv(divid%A, A, tmpx, tmpy);
    x=tmpy-(divid/A)*tmpx;
    y=tmpx;
    return gcd;

    //18 %  7 =4
    //4=18-7*2
    //7  % 4 =3
    //3= (-18+7*3)*1
    //4 % 3 =1
    //(18-7*2)*1 - 3*1=1
    
    // ll cur=(divid/A);

    // ll remain=divid%A;
    // ll cur_div=A;

    // while(remain!=1){
    //     // if(cur_div<remain) swap(cur_div,remain);
    //     cout<<cur_div<<' '<<remain<<'\n';
    //     cur*=cur_div/remain;
    //     tmp=remain;
    //     remain=cur_div%remain;
    //     cur_div=tmp;
    // }걍재귀로하는게정신건강에
    // return cur;
}
int main(){ //14565
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N,A;
    cin>>N>>A;
    ll p_i=N-A;
    // ll m_i=;
    ll tmp=gcd(N,A);
    // cout<<tmp<<'\n';
    cout<<p_i<<' ';
    // cout<<'\n';
    if(tmp!=1) cout<<"-1\n";
    else{
        ll x, y;
        getinv(A,N,x,y);
        ll sol=(x%N+N)%N;
        cout<<sol<<'\n';
        // for(int i=0; i<=N; ++i){
        //     if((A*i)%N==tmp){
        //         cout<<i<<'\n';
        //         // return 0;
        //     }
        // }
    }
    //Ax+By  =gcd(A,B);
    //(A*x)%B=gcd(A,B)%B;
    //(A*x)%B=1 %B
    //1이아니면 여러개나오므로 역원아님
    //(A*x)=By+1
    // 기본적으로 A<B,
}
#include<iostream>
using namespace std;
int main(){ //9656
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    // 1(상근) 1(창영) 1(상근)
    // 3(상근) -> 결국 홀수냐 짝수냐
    if(N%2==0) cout<<"SK\n";
    else cout<<"CY";

}
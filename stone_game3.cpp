#include<iostream>
using namespace std;
int main(){ //9657
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    // 1(상근) 1(창영) 1(상근)
    // 3(상근) -> 결국 홀수냐 짝수냐

    // 4개 아래로 남았을때 홀수/짝수로 승패가 갈림
    // 완벽하게 한다고 쳤을때 상대한테 잡으면 필패가 되는 수로 줘야함/ -1,-3,-4개중 한개라도
    char cnt[1001]={"",};
    cnt[1]='W';
    cnt[2]='L';
    cnt[3]='W';
    cnt[4]='W';
    cnt[5]='W';
    cnt[6]='W';
    cnt[7]='L';//6,4,3
    cnt[8]='W';
    for(int i=9; i<=1000; ++i){
        if(cnt[i-4]=='W' && cnt[i-3]=='W' && cnt[i-1]=='W') cnt[i]='L';
        else cnt[i]='W';
    }
    if(cnt[N]=='W') cout<<"SK\n";
    else cout<<"CY";

}
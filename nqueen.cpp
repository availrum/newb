#include<iostream>
using namespace std;
bool checksame[15]; //한 줄에 하나씩 넣었을때
bool checkleftwall[30]; // 왼쪽벽까지 대각선을 쳤을때 닿는 위치 (0,N-1)이면 (N-1,N-1) x+y
bool checkrightwall[30]; // 오른쪽 벽까지 대각선을 쳤을때 닿는 위치 
// ex) N=4 (0,0)이면 벽의 오른쪽 N-1까지 3칸이므로 (N-1,3) x + N-1-y
int cnt;
void rec(int N, int x){
    if(x==N){
        ++cnt;
        return;
    }
    for(int i=0; i<N; ++i){
        if(checksame[i] || checkleftwall[x+i] || checkrightwall[x+N-1-i]) continue;
        checksame[i]=true;
        checkleftwall[x+i]=true;
        checkrightwall[x+N-1-i]=true;
        rec(N,x+1);
        checksame[i]=false;
        checkleftwall[x+i]=false;
        checkrightwall[x+N-1-i]=false;
    }
}
int main(){//9663
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    rec(N,0);
    cout<<cnt<<'\n';
}
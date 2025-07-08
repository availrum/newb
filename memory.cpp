#include<iostream>
using namespace std;
int main(){ //14557
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int R,C;
    cin>>R>>C;

    // 카드를 2장 제외하고 전부 여는동안 한번도 같은조합이 안열림 -> 위치 파악끝 (R*C/2-1)
    // 카드를 확정으로 집어가기 (R*C/2)
    cout<<max(R*C/2,1)<<' '<<max(R*C-1,1)<<'\n';
}
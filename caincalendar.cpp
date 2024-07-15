#include<iostream>
using namespace std;
int main(){//6064
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int i=0; i<T; ++i){
        int M,N,x,y;
        bool flag=0;
        cin>>M>>N>>x>>y;
        //x,y -> M,N까지 
// **나머지연산을 사용하므로 인덱스에 주의할것...
        --x;
        --y;
// 매번 M-N만큼의 차이가 생김 
// 10 12 >> 1 1-> 13(3) 1 -> 25(5) 1 -> 37(7) 1 -> 49(9) 1 -> 61(1) 1...
// 10 12 >> 7 1->3 1->5 1->7 1 
// x,y 둘 중 하나를 고정 후 돌려보면 될것같다.
        for(int cnt=x; cnt<=M*N; cnt+=M){
            if(cnt%N==y){
                cout<<cnt+1<<'\n';
                flag=1;
                break;
            }
        }
        if(flag==0) cout<<"-1"<<'\n';
    }
}
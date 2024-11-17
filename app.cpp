#include<iostream>
using namespace std;
int main(){//7579
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    int W[N+1]={0,}, V[N+1]={0,};

    int bag=0;
    for(int i=1; i<=N; ++i){
        cin>>W[i];
        bag+=W[i];
    }

    //M바이트 이상의 메모리를 확보 == 가방의 크기가 전체메모리-M이다
    //사실상 가방에 담는 비용을 최대로 하는, [전체메모리-M]크기 배낭의 knapsack문제
    //로 해결 할 수 있을줄 알았다 (M이 너무 크다)

    int cost=0;
    for(int i=1; i<=N; ++i){
        cin>>V[i];
        cost+=V[i];
    }
    // M=bag-M;
    //M을 가방사이즈로 맞춰줌 >> 이었으나 M이 큰값이 들어가서 폐기

    int mval[cost+1]={0,};

    for(int i=1; i<=N; ++i){
        for(int j=cost; j>=0; --j){
        //W[i]가 중복으로 더해지지 않도록 최대부터 
            if(j>=V[i]) mval[j]=max(mval[j],mval[j-V[i]]+W[i]);
            //V[i]로 knapsack 구성 -> 최대한 작은 코스트에 최대한의 memory
            else break;
        }
    }

    int maxi;
    //가장 작은 코스트가 필요 > 작은값부터
    for(int i=0; i<=cost; ++i){
        if(mval[i]>=M){
            maxi=i;
            break;
        }
    }
    cout<<maxi<<'\n';
}
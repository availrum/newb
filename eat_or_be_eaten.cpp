#include<iostream>
#include<algorithm>
using namespace std;
int main(){ //7795
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int tcase=0; tcase<T; ++tcase){
        int N, M;
        cin>>N>>M;
        int A[N], B[M];
        for(int i=0; i<N; ++i){
            cin>>A[i];
        }
        for(int i=0; i<M; ++i){
            cin>>B[i];
        }
        sort(A,A+N);
        sort(B,B+M);
        int idxA=0, idxB=0;
        int cnt[N+1]={0,};
        int sol=0;
        while(idxA<N){
            if(A[idxA]>B[idxB]){
                ++cnt[idxA];
                if(idxB<M-1) ++idxB;
                else{
                    for(int i=idxA; i<N; ++i){
                        cnt[i]=M;
                        sol+=M;
                    }
                    break;
                }
            }
            else{
                cnt[idxA+1]=cnt[idxA];
                sol+=cnt[idxA];
                ++idxA;
            }
        }
        cout<<sol<<'\n';
    }
}
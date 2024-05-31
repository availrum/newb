#include<iostream>
#include<map>
using namespace std;
int main(){
    int N,M,tmp,cnt=0;
    map<int, int> ma;
    cin>>N>>M;
    int A[N],B[M];
    for(int i=0; i<N; ++i){
        cin>>A[i];
        ma[A[i]]++;
    }
    for(int i=0; i<M; i++){
        cin>>B[i];
        ma[B[i]]++;
    }
    for(int i=0; i<N; i++) if(ma[A[i]]==1) cnt++;
    for(int i=0; i<M; i++) if(ma[B[i]]==1) cnt++;
    cout<<cnt<<'\n';
}
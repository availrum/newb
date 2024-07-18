#include<iostream>
#include<unordered_map>
using namespace std;
int main(){//2776
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int i=0; i<T; ++i){
        int N,M,tmp,tmpc;
        cin>>N;
        unordered_map<int,int> ma;
        for(int j=0; j<N; ++j){
            cin>>tmp;
            ma[tmp]=1;
        }
        cin>>M;
        for(int j=0; j<M; ++j){
            cin>>tmpc;// 변수명을 안새로 안쓰면 틀리더라
            if(ma[tmpc]!=0) cout<<"1"<<'\n';
            else cout<<"0"<<'\n';
        }
    }
}
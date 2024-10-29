#include<iostream>
#include<vector>
using namespace std;
int find(int n, int *arr){
    if(n==arr[n]) return n;
    return find(arr[n], arr);
}
void merge(int a, int b, int *arr){
    int x=find(a,arr);
    int y=find(b,arr);
    if(x==y) return;
    if(x>y) swap(x,y);
    arr[x]=y;
}
int main(){//1197
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    int known[N+2];
    for(int i=0; i<=N+1; ++i){
        known[i]=i;
    }
    int X, real;
    cin>>X;
    for(int i=0; i<X; ++i){
        cin>>real;
        merge(N+1, real, known);
    }
    int participant, cnt=0;
    vector<int> vec[M+1];
    for(int i=0; i<M; ++i){
        cin>>participant;
        bool flag=false;
        int tmp;
        for(int j=0; j<participant; ++j){
            cin>>tmp;
            vec[i].push_back(tmp);
            if(tmp != find(tmp,known)){
                flag=true;
            }
        }
        if(flag){
            for(int j=0; j<participant; ++j){
                merge(N+1, vec[i][j], known);
            }
        }
    }
    for(int k=0; k<N; ++k){
    //한줄씩 역으로 가도 N번이면 성립
        for(int i=0; i<M; ++i){
            bool flag=false;
            for(int j=0; j<vec[i].size(); ++j){
                if(vec[i][j] != find(vec[i][j],known)){
                    flag=true;
                }
            }
            if(flag){
                for(int j=0; j<vec[i].size(); ++j){
                    merge(N+1, vec[i][j], known);
                }
            }
        }
    }
    for(int i=0; i<M; ++i){
        bool flag=false;
        for(int j=0; j<vec[i].size(); ++j){
            if(find(vec[i][j],known) != vec[i][j]) flag=true;
        }
        if(flag) continue;
        // for(int j=0; j<vec[i].size(); ++j) cout<<vec[i][j]<<' ';
        // cout<<'\n';
        ++cnt;
    }
    cout<<cnt<<'\n';
}
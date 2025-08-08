#include<iostream>
using namespace std;
int find(int n, int* arr){
    if(arr[n]==n) return n;
    return arr[n]=find(arr[n],arr);
}
void merge(int a, int b, int* arr){
    int x=find(a,arr);
    int y=find(b,arr);
    if(x==y) return;
    if(x<y) swap(x,y);
    arr[x]=y;
}
struct pos{
    int x1;
    int y1;
    int x2;
    int y2;
};
bool overlab(pos p1, pos p2){
    return (p1.x2<p2.x1 || p1.x1>p2.x2 || p1.y2<p2.y1 || p1.y1>p2.y2);
}
int main(){//9001
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int tcase=0; tcase<T; ++tcase){
        int N;
        cin>>N;
        int group[N+1];
        for(int i=0; i<=N; ++i){
            group[i]=i;
        }
        pos coordinate[N];

        int x1,y1,x2,y2;
        for(int i=0; i<N; ++i){
            cin>>coordinate[i].x1>>coordinate[i].y1>>coordinate[i].x2>>coordinate[i].y2;
        }
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                if(overlab(coordinate[i],coordinate[j])) continue;
                merge(i,j, group);
            }
        }
        bool check[N+1]={false,};
        int cnt=0;
        for(int i=0; i<N; ++i){
            if(check[find(i,group)]) continue;
            ++cnt;
            // cout<<find(i,group)<<'\n';
            check[find(i,group)]=true;
        }
        cout<<cnt<<'\n';
    }
}
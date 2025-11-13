#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<unordered_map>
#define ll long long int
using namespace std;

struct pos{
    int x;
    int y;
    ll dist;
    bool operator< (const pos& other) const{
        return dist<other.dist;
    }
};
int find(int n, int* arr){
    if(arr[n]==n) return n;
    return arr[n]=find(arr[n], arr);
}
void merge(int a, int b, int* arr){
    int x = find(a,arr);
    int y = find(b,arr);
    if(x==y) return;
    if(x>y) swap(x,y);
    arr[x]=y;
}
int main(){ //1774
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;

    int x,y;
    pair<ll,ll> space[N];
    for(int i=0; i<N; ++i){
        cin>>x>>y;
        space[i]={x,y};
    }
    vector<pos> vec;
    unordered_map<int,int> check;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(i==j) continue;
            if(check[1001*i+j] || check[i+1001*j]) continue;
            pos tmp;
            tmp.x=i, tmp.y=j, tmp.dist=(space[i].first-space[j].first)*(space[i].first-space[j].first)+(space[i].second-space[j].second)*(space[i].second-space[j].second); 
            vec.push_back(tmp);
            ++check[i+1001*j];
        }
    }
    sort(vec.begin(), vec.end());
    // for(int i=0; i<vec.size(); ++i){
    //     cout<<vec[i].dist<<' ';
    // }
    // cout<<'\n';

    int road[N+1];
    for(int i=0; i<=N; ++i){
        road[i]=i;
    }

    int idxa, idxb;
    for(int i=0; i<M; ++i){
        cin>>idxa>>idxb;
        merge(idxa-1, idxb-1, road);
    }

    double minpath=0;
    for(int i=0; i<vec.size(); ++i){
        if(find(vec[i].x,road)==find(vec[i].y,road)) continue;
        merge(vec[i].x, vec[i].y, road);
        minpath+=pow(vec[i].dist,0.5);
    }
    cout.precision(2);
    cout<<fixed;
    cout<<minpath<<'\n';
}
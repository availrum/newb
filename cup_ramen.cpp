#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct problem{
    int deadline;
    int ramen;
    bool operator< (const problem other) const{
        if(ramen!=other.ramen) return ramen<other.ramen;
        // if(deadline!=other.deadline) 
        return deadline<other.deadline;
    }
};
int find(int n, vector<int>& arr){
    if(arr[n]==n) return n;
    return arr[n]=find(arr[n],arr);
}
void merge(int a, int b, vector<int>& arr){
    int x=find(a,arr);
    int y=find(b,arr);
    if(x==y) return;
    if(x<y) swap(x,y);
    arr[x]=y;
}
int main(){ //1781
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    vector<int> vec(N+1,0);
    priority_queue<problem> qu;
    for(int i=0; i<N; ++i){
        problem tmp;
        cin>>tmp.deadline>>tmp.ramen;
        qu.push(tmp);
    }
    vector<int> arr(N+1);
    for(int i=0; i<=N; ++i){
        arr[i]=i;
    }
    // cout<<'\n';
    int total_ramen=0;
    while(!qu.empty()){
        int dl=qu.top().deadline;
        int rm=qu.top().ramen;
        qu.pop();
        int cur=find(dl,arr);
        if(cur){
            merge(cur,cur-1,arr);
            total_ramen+=rm;
        }
        // cout<<dl<<' '<<rm<<'\n';
    }
    cout<<total_ramen<<'\n';
}
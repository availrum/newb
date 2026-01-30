#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct node_data{
    int root;
    int evenodd;
    int groupsize;
    bool operator== (const node_data& other) const{
        if(root==other.root && evenodd==other.evenodd && groupsize==other.groupsize) return true;
        return false;
    }
    bool operator!= (const node_data& other) const{
        if(root!=other.root || evenodd!=other.evenodd || groupsize!=other.groupsize) return true;
        return false;
    }
};
node_data find(vector<node_data>& arr, int n){
    if(arr[n].root==n) return arr[n];
    int p=arr[n].root;
    node_data tmp=find(arr,p);
    arr[n].root=tmp.root;
    arr[n].evenodd=(arr[n].evenodd+arr[p].evenodd)%2;
    return tmp;
}
bool merge(vector<node_data>& arr, int a, int b){
    int x=find(arr,a).root;
    int y=find(arr,b).root;
    if(x!=y){
        if(x<y) swap(x,y);
        arr[y].groupsize+=arr[x].groupsize;
        arr[x]={y,(arr[a].evenodd+arr[b].evenodd+1)%2,arr[y].groupsize};
        return true;
    }
    else if(x==0) return true;
    if(arr[a].evenodd==arr[b].evenodd) return false;
    return true;
}
int main(){ //28121
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,Q;
    cin>>N>>Q;
    vector<node_data> connect(N+1);
    for(int i=0; i<=N; ++i){
        connect[i].root=i;
        connect[i].evenodd=0;
        connect[i].groupsize=1;
    }
    //홀수사이클판별필요
    for(int i=0; i<Q; ++i){
        int a,b;
        cin>>a>>b;
        if(!merge(connect,a,b)){
            merge(connect,a,0);
        }
        cout<<connect[0].groupsize-1<<'\n';
    }
    // for(int i=1; i<=N; ++i){
    //     cout<<find(connect,i).root<<' ';
    // } cout<<'\n';
} 
#include<iostream>
using namespace std;
int find_friend(int n, int* pnode){
    if(pnode[n]==n) return n;
    return pnode[n]=find_friend(pnode[n], pnode);
}
void merge(int a, int b, int* pnode, int* height){
    int x=find_friend(a,pnode);
    int y=find_friend(b,pnode);
    if(x==y) return;
    if(height[x]>height[y]) swap(x,y);
    pnode[x]=y;
    if(height[x]==height[y]) ++height[y];
}
int main(){//7511
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    for(int i=0; i<t; ++i){
        int n,k;
        cin>>n>>k;
        int pnode[n],height[n];
        for(int j=0; j<n; ++j){
            pnode[j]=j;
            height[j]=1;
        }
        int a,b;
        for(int j=0; j<k; ++j){
            cin>>a>>b;
            merge(a,b,pnode,height);
        }
        cin>>k;
        cout<<"Scenario "<<i+1<<":\n";
        for(int j=0; j<k; ++j){
            cin>>a>>b;
            if(find_friend(a,pnode)==find_friend(b,pnode)){
                cout<<"1"<<'\n';
            }
            else cout<<"0"<<'\n';
        }
        if(i!=t-1) cout<<'\n';
    }
}
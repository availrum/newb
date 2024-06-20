#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
int main(){//7785
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string name,cur;
    unordered_map<string,int> status;
    int N;
    cin>>N;
    string clist[N];
    for(int i=0; i<N; ++i){
        cin>>name>>cur;
        if(cur=="enter") status[name]=1;
        else status[name]=0;
        clist[i]=name;
    }
    sort(clist,clist+N);
    for(int i=N-1; i>=0; --i) if(status[clist[i]]==1){
        status[clist[i]]=0;
        cout<<clist[i]<<'\n';
    }
}
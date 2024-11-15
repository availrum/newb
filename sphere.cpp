#include<iostream>
using namespace std;
int main(){//1547
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int M;
    cin>>M;
    int x,y,table[3];
    table[0]=1;
    table[1]=0;
    table[2]=0;
    for(int i=0; i<M; ++i){
        cin>>x>>y;
        swap(table[x-1],table[y-1]);
    }
    for(int i=0; i<3; ++i){
        if(table[i]==1) cout<<i+1<<'\n';
    }
}
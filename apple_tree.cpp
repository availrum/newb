#include<iostream>
using namespace std;
int main(){ //19539
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int tree[N], num[3]={0,}, total=0;
    for(int i=0; i<N; ++i){
        cin>>tree[i];
        if(tree[i]%2==0) num[2]+=(tree[i]/2);
        else{
            num[2]+=(tree[i]/2);
            ++num[1];
        }
        total+=tree[i];
    }
    if(total%3!=0){
        cout<<"NO\n";
        return 0;
    }
    if(num[2]-num[1]>=0 && (num[2]-num[1])%3==0){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    //1 2 2 2 2 -> 1개(+2), 4개(-1) -> 3, 3
}
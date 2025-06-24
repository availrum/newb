#include<iostream>
#include<algorithm>
using namespace std;
int main(){ //1940
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    int material[N];
    for(int i=0; i<N; ++i){
        cin>>material[i];
    }
    sort(material,material+N);
    int lft=0, rgt=N-1;
    int cnt=0;
    while(lft<rgt){
        //같은재료 2개 불가능
        if(material[lft]+material[rgt]<M){
            ++lft;
        }
        else if(material[lft]+material[rgt]>M){
            --rgt;
        }
        else{
            ++lft;
            --rgt;
            ++cnt;
        }
    }
    cout<<cnt<<'\n';
} 
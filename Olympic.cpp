#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
struct score{
    int id;
    int G;
    int S;
    int B;
    bool operator< (const score& other) const{
        if(G!=other.G) return G>other.G;
        else if(S!=other.S) return S>other.S;
        else return B>other.B;
    }
    bool operator== (const score& other) const{
        if(G==other.G && S==other.S  && B==other.B) return true;
        else return false;
    }
};
int main(){ //8979
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,K;
    cin>>N>>K;
    score ctr[N],tmp[N];
    for(int i=0; i<N; ++i){
        int id,g,s,b;
        cin>>id>>g>>s>>b;
        ctr[id-1]={id-1, g,s,b};
        tmp[id-1]={id-1, g,s,b};
    }
    sort(tmp,tmp+N);
    unordered_map<int,int> ranking;
    int idx=1;
    for(int i=0; i<N; ++i){
        if(i>0 && tmp[i]==tmp[i-1]){
            ranking[tmp[i].id]=ranking[tmp[i-1].id];
        }
        else{
            ranking[tmp[i].id]=i+1;
        }
    }
    // for(int i=0; i<N; ++i) cout<<ranking[i]<<'\n';
    cout<<ranking[K-1]<<'\n';
} 
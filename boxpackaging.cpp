#include<iostream>
using namespace std;
int main(){ //14231
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int box[N], overpack[N];
    for(int i=0; i<N; ++i){
        cin>>box[i];
        overpack[i]=1;
    }
    int maxbox=1;
    for(int i=1; i<N; ++i){
        for(int j=i-1; j>=0; --j){
            if(box[i]<=box[j]) continue;
            overpack[i]=max(overpack[i], overpack[j]+1);
            maxbox=max(maxbox,overpack[i]);
        }
    }
    cout<<maxbox<<'\n';
}
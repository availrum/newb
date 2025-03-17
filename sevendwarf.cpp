#include<iostream>
#include<algorithm>
using namespace std;
int main(){//2309
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int shortleg[9], sum=0;
    for(int i=0; i<9; ++i){
        cin>>shortleg[i];
        sum+=shortleg[i];
    }
    int spy1=-1, spy2=-1;
    sort(shortleg,shortleg+9);
    for(int i=0; i<9; ++i){
        for(int j=i+1; j<9; ++j){
            if(sum-(shortleg[i]+shortleg[j])==100){
                spy1=i;
                spy2=j;
            }
        }
    }
    for(int i=0; i<9; ++i){
        if(i!=spy1 && i!=spy2) cout<<shortleg[i]<<'\n';
    }
}
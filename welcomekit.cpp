#include<iostream>
using namespace std;
int main(){//30802
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,size[7],sum=0;
    cin>>N;
    for(int i=0; i<6; ++i) cin>>size[i];
    int T,P;
    cin>>T>>P;
    for(int i=0; i<6; ++i){
        if(size[i]%T==0) sum+=size[i]/T;
        else sum+=(size[i]/T)+1;
    }
    cout<<sum<<'\n';
    cout<<N/P<<' '<<N%P<<'\n';
}
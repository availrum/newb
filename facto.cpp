#include<iostream>
#include<algorithm>
using namespace std;
int main(){//1037
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,t,num=0,sol;
    bool flag=true;
    cin>>t;
    int facto[t];
    for(int i=0; i<t; ++i) cin>>facto[i];
    sort(facto,facto+t);
    sol=facto[num]*facto[t-1];
    while(true){
        if(facto[t-1]%facto[num]!=0) sol=facto[num]*facto[t-1];
        for(int i=t-2; i>=0; --i){
            if(sol%facto[i]!=0){
                flag=false;
                break;
            }
        }
        if(flag) break;
        ++num;
    }
    cout<<sol<<'\n';
}
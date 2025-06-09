#include<iostream>
#include<cmath>
using namespace std;
int main(){//16888
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;

    int N=1000000;
    bool arr[N+1]={false,};

    int curmax=1;
    for(int tcase=0; tcase<T; ++tcase){
        int value;
        cin>>value;
        if(value>=curmax){
            for(int i=curmax; i<=value; ++i){
                for(int j=1; j*j<=i; ++j){
                    if(!arr[i-j*j]){
                        arr[i]=true;
                        break;
                    }
                }
            }
            curmax=value+1;
        }
        if(arr[value]) cout<<"koosaga"<<'\n';
        else cout<<"cubelover"<<'\n';
    }
}
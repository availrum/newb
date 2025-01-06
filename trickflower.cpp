#include<iostream>
#include<unordered_map>
using namespace std;
int main(){//30648
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a,b,R;
    cin>>a>>b;
    cin>>R;
    unordered_map<int,int> check;
    int time=0;
    while(true){
        ++check[1001*a+b];
        if(check[1001*a+b]>1) break;
        ++time;
        if(a+b+2 < R){
            a+=1;
            b+=1;
        }
        else{
            a/=2;
            b/=2;
        }
    }
    cout<<time<<'\n';
}
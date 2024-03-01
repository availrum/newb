#include<iostream>
#include<map>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,con5,cal,tmp;
    cin>>N;
    con5=N/5;
    cal=0;
    for(int i=con5; i>=0; i--){
        tmp=N-5*i;
        cal=i;
        if(tmp==0){
            cout<<cal<<'\n';
            return 0;
        }
        if(tmp%3==0 ){
            cal+=tmp/3;
            cout<<cal<<'\n';
            return 0;
        }
    }
    cout<<"-1"<<'\n';
    return 0;
}
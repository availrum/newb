#include<iostream>
using namespace std;
int main(){//8958
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string st;
    int test,sum,num=1;
    cin>>test;
    for(int i=0; i<test; i++){
        cin>>st;
        sum=0,num=1;
        for(int j=0; j<st.length(); j++){
            if(st[j]=='O'){
                sum+=num;
                num++;
            }
            else num=1;
        }
        cout<<sum<<'\n';

    }
}
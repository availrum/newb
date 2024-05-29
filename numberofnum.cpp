#include<iostream>
using namespace std;
int main(){//2577
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int A,B,C,cal,sum;
    cin>>A>>B>>C;
    cal=A*B*C;
    string st=to_string(cal),tmp="";
    for(int i=0; i<=9; i++){
        sum=0;
        for(int j=0; j<st.size(); j++){
            tmp+=st[j];
            if(tmp==to_string(i)) sum++;
            tmp="";
        }
        cout<<sum<<'\n';
    }
}
#include<iostream>
using namespace std;
int main(){ //11104
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int tcase=0; tcase<T; ++tcase){
        string st;
        cin>>st;
        int decimal_number=0;
        int idx=1;
        for(int i=st.length()-1; i>=0; --i){
            if(st[i]-'0') decimal_number+=idx;
            idx*=2;
        }
        cout<<decimal_number<<'\n';
    }
}
#include<iostream>
using namespace std;
void st(int n){
    for(int i=1; i<=n ; ++i){
        string tmp="";
        int idx=i;
        while(idx>26){
            if(idx%26!=0) tmp+=('A'-1+idx%26);
            else tmp+=('A'+25);
            idx/=26;
        }
        if(i!=0){
            if(idx%26!=0) tmp+=('A'-1+idx%26);
            else tmp+=('A'+25);
        }
        cout<<tmp;
        if(i!=n) cout<<' ';
    }
    cout<<'\n';
}
int main(){ //11773
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int A,B;
    cin>>A>>B;
    st(B);
}
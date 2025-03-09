#include<iostream>
using namespace std;
int main(){//12904
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string S,T;
    cin>>S;
    cin>>T;
    int Tleng=T.length()-1, Sleng=S.length();
    for(int i=Tleng; i>=Sleng; --i){
        if(T[i]=='A'){
            T.pop_back();
        }
        else if(T[i]=='B'){
            T.pop_back();
            string tmp="";
            for(int j=T.length()-1; j>=0; --j){
                tmp+=T[j];
            }
            T=tmp;
        }
    }
    // cout<<S<<"  "<<T<<'\n';
    if(S==T) cout<<"1"<<'\n';
    else cout<<"0"<<'\n';

}
#include<iostream>
using namespace std;
int main(){//3613
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string st,sol="";
    cin>>st;
    int flag=0;
    bool checkj=false, checkc=false;
    for(int i=0; i<st.length(); ++i){
        if(st[i]=='_'){
            flag=1;
            if(i==0 || st[i-1]=='_' || i==st.length()-1){
                cout<<"Error!"<<'\n';
                return 0;
            }
            else if(checkj){
                cout<<"Error!"<<'\n';
                return 0;
            }
            checkc=true;
            continue;
        }
        else if(st[i]>='A' && st[i]<='Z'){
            if(i==0){
                cout<<"Error!"<<'\n';
                return 0;
            }
            flag=2;
            sol+='_';
            if(checkc){
                cout<<"Error!"<<'\n';
                return 0;
            }
            checkj=true;
        }
        if(!flag){
            sol+=st[i];
        }
        else if(flag==1){
            sol+=(st[i]-32);
            flag=0;
        }
        else if(flag==2){
            sol+=(st[i]+32);
            flag=0;
        }
    }
    cout<<sol<<'\n';
}
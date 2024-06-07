#include<iostream>
using namespace std;
int main(){//2941
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string st;
    cin>>st;
    int sum=0;
    for(int i=0; i<st.length(); ++i){
        if(!isalpha(st[i])) continue;
        if(st[i]=='c') sum++;
        else if(st[i]=='d') {
            if(st[i+1]=='-') sum++;
            else if(st[i+1]!='z') sum++;
            else if(i+2 >= st.length()) {
                sum+=2;
                break;
            }
            else {
                if(st[i+2]=='=') {
                    sum++;
                    i+=2;
                }
                else sum++;
            }
        }
        else if(st[i]=='l'){
            if(st[i+1]=='j') {
                sum++;
                i++;
            }
            else sum++;
        }
        else if(st[i]=='n') {
            if(st[i+1]=='j'){
                sum++;
                i++;
            }
            else sum++;
        }
        else if(st[i]=='s') sum++;
        else if(st[i]=='z') sum++;
        else sum++;
    }
    cout<<sum<<'\n';
}
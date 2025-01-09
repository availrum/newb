#include<iostream>
#include<unordered_map>
#include<cmath>
using namespace std;
int main(){//6495
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int p,g;
    cin>>p>>g;
    unordered_map<string, int> number;
    string st;
    double tmp;
    for(int i=0; i<p; ++i){
        cin>>st>>tmp;
        number[st]=tmp*10;
    }
    string oper;
    for(int i=1; i<=g; ++i){
        int sum=0;
        while(cin>>st){
            if(st=="+") continue;
            else if(st=="<" || st==">" || st=="<=" || st==">=" || st=="="){
                oper=st;
                continue;
            }
            bool isnumb=true;
            for(int j=0; j<st.size(); ++j){
                if(!isdigit(st[j])){
                    isnumb=false;
                    break;
                }
            }

            if(!isnumb){
                sum+=number[st];
                // cout<<sum<<' ';
            }
            else{
                // cout<<'\n';
                int cal=stoi(st)*10;
                // cout<<sum<<' '<<cal<<' '<<abs(sum-cal)<<'\n';
                // if(abs(sum-cal)<0.001) sum=cal;
                cout<<"Guess #"<<i<<" was ";
                if(oper=="<"){
                    if(sum<cal) cout<<"correct."<<'\n';
                    else cout<<"incorrect."<<'\n';
                }
                else if(oper==">"){
                    if(sum>cal) cout<<"correct."<<'\n';
                    else cout<<"incorrect."<<'\n';
                }
                else if(oper=="<="){
                    if(sum<=cal) cout<<"correct."<<'\n';
                    else cout<<"incorrect."<<'\n';
                }
                else if(oper==">="){
                    if(sum>=cal) cout<<"correct."<<'\n';
                    else cout<<"incorrect."<<'\n';
                }
                else if(oper=="="){
                    if(sum==cal) cout<<"correct."<<'\n';
                    else cout<<"incorrect."<<'\n';
                }
                break;
            }
            
        }
    }
}
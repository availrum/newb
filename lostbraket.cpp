#include<iostream>
using namespace std;
int main(){//1541
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int sum=0;
    string tmp,tmps;
    cin>>tmp;
    tmps="";
    bool minus=false;
    for(int j=0; j<=tmp.length(); j++){
        if(j==tmp.length()){
            if(minus==false) sum+=stoi(tmps);
            else sum-=stoi(tmps);
            break;
        }
        if(isdigit(tmp[j])) tmps+=tmp[j];
        else{
            if(tmps.length()){//없으면 에러
                if(minus==false){
                    if(tmp[j]=='+') {
                        sum+=stoi(tmps);
                        tmps="";
                    }
                    else if(tmp[j]=='-'){
                        sum+=stoi(tmps);
                        minus=true;
                        tmps="";
                    }
                }
                else{
                    sum-=stoi(tmps);
                    tmps="";
                }
            }
        }
    }
    cout<<sum<<'\n';
}
#include<iostream>
#include<stack>
using namespace std;
int main(){//17413
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string sol="";
    stack<int> stac;
    string st;

    bool flag=false;
    getline(cin,st);
    for(int i=0; i<st.size(); ++i){
        if(st[i]==' ' || st[i]=='\n'){
            while(!stac.empty()){
                sol+=stac.top();
                stac.pop();
            }
            if(st[i]==' ') sol+=st[i];
        }
        else if(st[i]=='<'){
            while(!stac.empty()){
                sol+=stac.top();
                stac.pop();
            }
            flag=true;
            sol+=st[i];
        }
        else if(st[i]=='>'){
            flag=false;
            sol+=st[i];
        }
        else if(flag) sol+=st[i];
        else stac.push(st[i]);
        // cout<<st[i]<<' ';
    }
    while(!stac.empty()){
        sol+=stac.top();
        stac.pop();
    }
    
    cout<<sol<<'\n';
}

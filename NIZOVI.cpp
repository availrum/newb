#include<iostream>
#include<queue>
using namespace std;
int main(){ //11954
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string st;
    getline(cin,st);
    int numofbra=0;
    queue<char> qu;
    for(int i=0; i<st.length(); ++i){
        if(st[i]==','){
            for(int j=0; j<numofbra; ++j){
                cout<<' ';
            }
            while(!qu.empty()){
                cout<<qu.front();
                qu.pop();
            }
            cout<<st[i]<<'\n';
            continue;
        }
        if(i!=st.length()-1){
            if(st[i]=='{'){
                for(int j=0; j<numofbra; ++j){
                    cout<<' ';
                }
                cout<<st[i]<<'\n';
                if(st[i+1]=='}'){
                    for(int j=0; j<numofbra; ++j){
                        cout<<' ';
                    }
                    if(i+2<st.length() && st[i+2]==','){
                        cout<<st[i+1]<<st[i+2]<<'\n';
                        i+=2;
                    }
                    else{
                        cout<<st[i+1]<<'\n';
                        ++i;
                    }
                }
                else numofbra+=2;
            }
            else if(st[i]=='}'){
                if(!qu.empty()){
                    for(int j=0; j<numofbra; ++j){
                        cout<<' ';
                    }
                    while(!qu.empty()){
                        cout<<qu.front();
                        qu.pop();
                    }
                    cout<<'\n';
                }
                numofbra-=2;
                for(int j=0; j<numofbra; ++j){
                    cout<<' ';
                }
                cout<<st[i];
                if(st[i+1]==','){
                    cout<<st[i+1]<<'\n';
                    ++i;
                }
                else{
                    cout<<'\n';
                }
            }
            else if(st[i]==' '){
                continue;
            }
            else{
                qu.push(st[i]);
            }
        }
        else if(i==st.length()-1){
            if(!qu.empty()){
                for(int j=0; j<numofbra; ++j){
                    cout<<' ';
                }
                while(!qu.empty()){
                    cout<<qu.front();
                    qu.pop();
                }
                cout<<'\n';
            }
            cout<<st[i]<<'\n';
        }
    }
}
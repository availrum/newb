#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
string to_lower(string st){
    for(int i=0; i<st.length(); ++i){
        if(st[i]>64 && st[i]<91) st[i]+=32;
    }
    return st;
}
int main(){ //9512
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,t;
    cin>>N;
    cin.ignore();
    unordered_map<string,string> languages;
    for(int i=0; i<N; ++i){
        string st, tmp;
        getline(cin,st);

        string language="",str="";
        for(int j=0; j<st.length(); ++j){
            if(st[j]!=' ') str+=st[j];
            else if(language==""){
                language=str;
                str="";
            }
            else{
                // cout<<str<<' '<<language<<'\n';
                languages[to_lower(str)]=language;
                str="";
            }
        }
        // cout<<str<<' '<<language<<'\n';
        languages[to_lower(str)]=language;
        str="";
    }
    string st;
    while(getline(cin,st)){
        // if(st=="ss") break;
        if(st=="") continue;
        // cout<<st<<'\n';
        string cur_language="", str="";
        for(int j=0; j<st.length(); ++j){
            if(st[j]!=' ' && st[j]!=',' && st[j]!='.' && st[j]!=';' 
                && st[j]!='?' && st[j]!='!' && st[j]!=')' && st[j]!='(') str+=st[j];
            else if(languages.find(to_lower(str)) != languages.end()){
                // cout<<languages[str]<<'\n';
                cur_language=languages[to_lower(str)];
                str="";
                break;
            }
            else{
                // cout<<to_lower(str)<<'\n';
                str="";
            }
        }
        if(languages.find(to_lower(str))!=languages.end()){
            cur_language=languages[to_lower(str)];
            // cout<<str<<'\n';
        }
        cout<<cur_language<<'\n';
    }

} 
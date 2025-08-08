#include<iostream>
#include<unordered_map>
using namespace std;
unordered_map<string,string> check;
string find(string st){
    if(check[st]==st) return st;
    return check[st]=find(check[st]);
}
void merge(string st1, string st2){
    string s1=find(st1);
    string s2=find(st2);
    if(s1==s2) return;
    if(s1.length()>s2.length()) swap(s1,s2);
    check[s1]=s2;
}
int main(){ //26551
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    for(int i=0; i<n; ++i){
        string st1, rel, st2;
        cin>>st1>>rel>>st2;
        if(check[st1]==""){
            check[st1]=st1;
        }
        if(check[st2]==""){
            check[st2]=st2;
        }
        merge(st1,st2);
    }
    int m;
    cin>>m;
    for(int i=0; i<m; ++i){
        string a,b;
        cin>>a>>b;
        if(find(a)!=find(b)) cout<<"Not Related"<<'\n';
        else cout<<"Related"<<'\n';
    }
} 
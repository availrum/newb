#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

string add(string& st1, string& st2){
    int tmp=0;
    string sol="";
    for(int i=0; i<max(st1.length(), st2.length()); ++i){
        if(st1.length()>i){
            tmp+=st1[st1.length()-1-i]-'0';
        }
        if(st2.length()>i){
            tmp+=st2[st2.length()-1-i]-'0';
        }
        // cout<<tmp<<'\n';
        sol+=to_string(tmp%10);
        tmp/=10;
    }
    if(tmp!=0) sol+=to_string(tmp);
    reverse(sol.begin(), sol.end());
    return sol;
}
string fib(vector<string>& arr, int n){
    if(arr[n]!="") return arr[n];
    string tmp1=fib(arr,n-2);
    string tmp2=fib(arr,n-1);
    arr[n]=add(tmp1,tmp2); 
    return arr[n];
}
int main(){ //10826
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    vector<string> arr(N+2,"");
    arr[0]="0";
    arr[1]="1";
    cout<<fib(arr,N)<<'\n';
}
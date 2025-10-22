#include<iostream>
using namespace std;
int main(){ //1475
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string N;
    cin>>N;
    int num[10]={0,},max_value=0;
    for(int i=0; i<N.length(); ++i){
        if(!(N[i]=='6' || N[i]=='9')){
            ++num[N[i]-'0'];
            max_value=max(max_value,num[N[i]-'0']);
        }
        else{
            ++num[6];
            max_value=max(max_value, (num[6]+num[9]+1)/2);
        }
    }
    cout<<max_value<<'\n';

}
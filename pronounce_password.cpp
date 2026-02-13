#include<iostream>
using namespace std;
int main(){ //4659
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string st;
    while(cin>>st){
        if(st=="end") break;
        bool aeiou=false;
        bool no3=true;
        bool nodouble=true;
        int cntvowel=0;
        int cntconsonant=0;
        for(int i=0; i<st.length(); ++i){
            if(st[i]=='a' || st[i]=='e' || st[i]=='i' || st[i]=='o' || st[i]=='u'){
                aeiou=true;
                ++cntvowel;
                cntconsonant=0;
            }
            else{
                ++cntconsonant;
                cntvowel=0;
            }
            if(cntconsonant>2 || cntvowel>2) no3=false;
            if((i>0 && st[i]==st[i-1]) && !(st[i]=='e' || st[i]=='o')) nodouble=false;
        }
        if(aeiou && no3 && nodouble) cout<<"<"<<st<<"> is acceptable.\n";
        else cout<<"<"<<st<<"> is not acceptable.\n";
    }
}
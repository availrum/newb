#include<iostream>
using namespace std;
//다하고 생각해보니 차라리 비트연산으로 구현했다면 훠어어얼씬 더 깔끔했을지도?
bool cmp(string a, string b){
    if(a.length()<b.length()) return false;
    else if(a.length()>b.length()) return true;
    for(int i=0; i<a.length(); ++i){
        if(a[i]>b[i]) return true;
        else if(a[i]<b[i]) return false;
    }
    return true;
}
string to_number(string& st){
    string tmp="";
    bool flag=false;
    for(int i=0; i<st.length(); ++i){
        if(!(!flag && st[i]=='0')){
            tmp+=st[i];
            flag=true;
        }
    }
    if(tmp=="") return "0";
    return tmp;
}
void string_operator_minus(string& a, string& b){
    // cout<<"a1="<<a<<' '<<b<<'\n';
    int tmp=0;
    for(int i=0; i<a.length(); ++i){
        if(b.length()-1>=i){
            tmp+=((a[a.length()-1 -i])-(b[b.length()-1 -i]));
            // cout<<"minus_tmp="<<tmp<<'\n';
            if(tmp>=0){
                a[a.length()-1 -i]=tmp+'0';
                tmp=0;
            }
            else{
                a[a.length()-1 -i]='0'+abs(10+tmp);
                tmp=-1;
            }
        }
        else if(tmp!=0){ // b의 자리수는 넘어간 경우
            if((a[a.length()-1 -i]-'0')+tmp>=0){
                a[a.length()-1 -i]=(a[a.length()-1 -i]-'0')+tmp+'0';
                tmp=0;
            }
            else{
                tmp=-1;
                a[a.length()-1 -i]='9';
            }
        }
        else break;
    }
    a=to_number(a);
    // cout<<"a2="<<a<<' '<<b<<'\n';
}
int divide_factor(string& a, string& b){
    string tmp=b;
    int num=0;
    for(int factor=1; factor<=10; ++factor){
            // cout<<"a= "<<a<<", b="<<b<<'\n';
        a=to_number(a);
        b=to_number(b);
        if(!cmp(a,b)){
            return num;
        }
        num=factor;
        string_operator_minus(a,b);
    }
    return num;
}
string cal(string& st1, string& st2){
    string tmp="", div="", val="", remain="";
    for(int i=0; i<st1.length(); ++i){
        tmp+=st1[i];
        if(st2.length()>i){
            div+=st2[i];
        }
        if(st2.length()-1<=i){
                    // cout<<"tmp="<<tmp<<", div="<<div<<'\n';
            if(tmp.length()>div.length()){
                val+=to_string(divide_factor(tmp,div));
            }
            else if(tmp.length()==div.length()){
                if(cmp(tmp,div)){
                    val+=to_string(divide_factor(tmp,div));
                }
                else val+='0';
            }
            else val+='0';
                    // cout<<"tmp="<<tmp<<", div="<<div<<'\n';
        }
        // cout<<"val="<<val<<'\n';
    }
    st1=to_number(tmp);
    return val;
}
int main(){ //10757
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string st1,st2;
    cin>>st1>>st2;
    string sol=cal(st1,st2);
    cout<<to_number(sol)<<'\n';
    cout<<to_number(st1)<<'\n';
}
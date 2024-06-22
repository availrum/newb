#include<iostream>
using namespace std;
int main(){//6890
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string forb,st;
    // cin>>forb;
    // cin.ignore();
    getline(cin,forb,'\n');
    // cin.ignore();   //버퍼비워주기
    getline(cin,st,'\n');
    // cout<<' '<<st<<' '<<"??"<<' '<<forb<<'\n';
    int k=0;
    while(k<st.length()){
        for(int j=0; j<forb.length(); ++j){
            if(k>=st.length()){
                cout<<'\n';
                return 0;    //문자열의 순서가 문자길이를 넘어가면 끝내기
            }
            else if(!isalpha(st[k])){   //알파벳이 아니라면 문자열순서+1 헤더순서유지
                --j;
            }
            // else if(st[k]==forb[j]){    //문자열이 헤더와 같으면 그대로 출력(아  이런거 없었구나)
            //     cout<<char(st[k]);
            // }
            else{//헤더와 다르고 알파벳
                char forbid=(forb[j]-'A'), cur=st[k];
                if(cur+forbid<=90){
                    // cout<<"("<<int(forbid)<<' '<<char(cur)<<")";
                    cout<<char(cur+forbid);
                }
                else{
                    // cout<<"("<<int(forbid)<<' '<<char(cur)<<")";
                    cout<<char(cur+forbid-26);
                }
                // cout<<'\n';
            }
            ++k;
        }
        if(k>=st.length()) cout<<'\n';
    }
    // cout<<'\n';
}
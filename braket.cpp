#include<iostream>
#include<stack>//But do not use
using namespace std;
int main(){//9012
    int N,cnt;
    string st;
    stack<char> yosi;
    cin>>N;
    string sol[N];
    for(int i=0; i<N; i++){
        cin>>st;
        cnt=0;
        if(st.length()%2==1){
            // cout<<"NO"<<'\n';
            sol[i]="NO";
            continue;
        }
        for(int j=0; j<st.length(); j++){
            // if(yosi.top()==')' && st[j]=='(') {
            //     cout<<"NO"<<'\n';
            //     break;
            // }
            if(st[j]=='('){
                cnt++;
            }
            else{
                // yosi.push(st[j]);
                cnt--;
            }
            if(cnt<0){
                sol[i]="NO";
                break;
            }
        }
        if(cnt!=0){
            // cout<<"NO"<<'\n';
            sol[i]="NO";
            continue;
        }
        // cout<<"YES"<<'\n';
        sol[i]="YES";
    }
    for(int i=0; i<N; i++){
        cout<<sol[i]<<'\n';
    }
    return 0;
}
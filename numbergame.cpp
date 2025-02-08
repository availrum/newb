#include<iostream>
#include<algorithm>
using namespace std;
int main(){//1755
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int M,N;
    cin>>M>>N;
    pair<string,int> arr[N-M+2];
    int idx=0;
    for(int i=M; i<=N; ++i){
        string st=to_string(i), tmp="";
        for(int j=0; j<st.length(); ++j){
            if(st[j]=='0') tmp+="zero";
            if(st[j]=='1') tmp+="one";
            if(st[j]=='2') tmp+="two";
            if(st[j]=='3') tmp+="three";
            if(st[j]=='4') tmp+="four";
            if(st[j]=='5') tmp+="five";
            if(st[j]=='6') tmp+="six";
            if(st[j]=='7') tmp+="seven";
            if(st[j]=='8') tmp+="eight";
            if(st[j]=='9') tmp+="nine";
            tmp+=" ";
        }
        arr[idx].first=tmp;
        arr[idx].second=i;
        ++idx;
    }
    sort(arr,arr+(N-M+2));
    for(int i=1; i<N-M+2; ++i){
        cout<<arr[i].second;
        if(i%10!=0) cout<<' ';
        else cout<<'\n';
    }
}
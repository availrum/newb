#include<iostream>
#include<map>
using namespace std;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N,M,k;
    string nam,stri;
    int div;
    map<string, int> a;
    map<int, string> b;
    cin>>N>>M;
    for(int i=0; i<N; i++){
        cin>>nam;
        a[nam]=i+1;
        b[i+1]=nam;
        // b[i+1]=i+1;
        // b.insert(pair<int,string>(i+1,nam));
    }
    for(int i=0; i<M; i++){
        cin.ignore();
        div=cin.peek();
        // cout<<div<<'\n';
        if(div>='0' && div<='9'){
            cin>>k;
            cout<<b[k]<<'\n';
            // cout<<"??"<<'\n';
            
        }
        else {
            cin>>stri;
            cout<<a[stri]<<'\n';
            // cout<<"yo"<<'\n';
        }
    }
    return 0;
}
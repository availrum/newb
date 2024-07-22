#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main(){//9935
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string st,burst;
    cin>>st>>burst;
    stack<char> stac;
    for(int i=0; i<st.length(); ++i){
        stac.push(st[i]);
        int j=burst.length()-1;
        if(st[i]!=burst[j]){
            continue;
        }
        int flag=0;
        vector<char> tmp;
        while(!stac.empty() && stac.top() == burst[j]){
            tmp.push_back(stac.top());
            stac.pop();
            --j;
            if(stac.empty() && j>=0){
                flag=1;
                break;
            }
            else if(j>=0 && stac.top() != burst[j]){
                flag=1;
                break;
            }
            else if(j<0){
                j=burst.length()-1;
                tmp.clear();
            }
        }
        if(flag==1){
            for(int k=tmp.size()-1; k>=0; --k) stac.push(tmp[k]);
        }
    }
    if(stac.empty()) cout<<"FRULA"<<'\n';
    else{
        string sol="";
        int rec=stac.size();
        for(int i=0; i<rec; ++i){
            sol+=stac.top();
            stac.pop();
        }
        for(int i=sol.length()-1; i>=0; --i) cout<<sol[i];
        cout<<'\n';
    }
}
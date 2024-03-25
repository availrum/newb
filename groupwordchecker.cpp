#include<iostream>
#include<map>
using namespace std;
int main(){//1316
    int N,sol=0;
    string st;
    cin>>N;
    for(int i=0; i<N; i++){
        map<char, int> a;
        cin>>st;
        if(st.size()==1 || st.size()==2){
            sol+=1;
            continue;
        }
        a[st[0]]++;
        for(int j=1; j<st.size()-1; j++){
            // cout<<st[j]<<'\n';
            if(a[st[j]] !=0){
                if((st[j]!=st[j-1])) break;
            }
            else{
                if(a[st[j+1]]!=0 && st[j]!=st[j+1]) break;
            }
            a[st[j]]++;
            // cout<<st[j]<<'\n';
            // if(j==st.size()-1) sol++;
            if(j==st.size()-2){
                // if(st[j+1]==st[j] && a[st[j+1]]==0){
                //     sol++;
                //     break;
                // }
                if(st[j+1]!=st[j] && a[st[j+1]]>0) break;
                sol++;
                // cout<<' '<<'\n';
                // cout<<st<<'\n';
                break;
            }
        }
    }
    cout<<sol<<'\n';
    return 0;
}
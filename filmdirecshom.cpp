#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){//1436
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,cnt=0,num;
    cin>>N;
    string st;
    vector<int> endN;
    // st=to_string(666);
    if(N==1){
        cout<<666<<'\n';
        return 0;
    }
    for(int i=1666; i<3000000; i++){//최대 7자리 숫자까지(2666799)
        // cout<<i.length()<<'\n';
        st=to_string(i);
        num=0;
        if(st[st.length()/2]!='6'){
            if(st.length()<6) continue;
            if(st[st.length()/2-1]!='6' && st[st.length()/2+1]!='6') continue;
        }
        int tmp=i;
        for(int j=0; j<st.length()-2; j++){
            if(tmp%1000!=666) {
                tmp/=10;
                if(tmp<100) break;
            } 
            else {
                num=3;
                break;
            }


            // if(st[j]=='6') num[i]++;
            // if(num[i]<3 && st[j]!='6') num[i]=0;
            // if(num[i]>=3) break;
            // if(3>num[i]+st.length()-j) break;
        }

        if(num>=3) {
            endN.push_back(i); 
            cnt++;
        }
        if(cnt>N-2) break;
    }
    cout<<endN[N-2]<<'\n';
}
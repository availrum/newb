#include<iostream>
using namespace std;
int main(){ //16472
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    string st;
    int alphabet[150]={0,};
    cin>>st;
    int lft=0, rgt=0, max_leng=1, alphabet_cnt=1;
    ++alphabet[st[lft]];
    int stl=st.length();
    while(lft<stl){
        if(rgt>=stl) break;

        if(alphabet_cnt>N){
            --alphabet[st[lft]];
            if(alphabet[st[lft]]==0) --alphabet_cnt;
            ++lft;
        }
        else{
            max_leng=max(max_leng, rgt-lft+1);
            ++rgt;
            if(rgt<stl){
                if(alphabet[st[rgt]]==0) ++alphabet_cnt;
                ++alphabet[st[rgt]];
            }
            else break;
        }
    }
    cout<<max_leng<<'\n';
}
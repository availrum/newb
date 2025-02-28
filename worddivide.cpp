#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
int main(){//1251
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string st;
    cin>>st;
    vector<string> vec;
    unordered_map<string, int> check;
    for(int i=1; i<st.length()-1; ++i){
        string st1="";
        for(int j=0; j<i; ++j){
            st1+=st[j];
        }
        string rvs="";
        for(int j=st1.length()-1; j>=0; --j) rvs+=st1[j];

        for(int j=i+1; j<st.length(); ++j){
            string st2="", st3="";
            string tmp=rvs;
            for(int k=i; k<j; ++k){
                st2+=st[k];
            }
            for(int k=j; k<st.length(); ++k){
                st3+=st[k];
            }

            for(int k=st2.length()-1; k>=0; --k) tmp+=st2[k];
            for(int k=st3.length()-1; k>=0; --k) tmp+=st3[k];
            if(!check[tmp]){
                vec.push_back(tmp);
                ++check[tmp];
            }
        }
    }
    sort(vec.begin(),vec.end());
    cout<<vec[0]<<'\n';
}
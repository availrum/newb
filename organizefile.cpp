#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
int main(){//20291
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    string st;
    unordered_map<string, int> check;
    vector<string> vec;
    for(int i=0; i<N; ++i){
        cin>>st;
        string tmp1="", tmp2="";
        bool flag=false;
        for(int j=0; j<st.length(); ++j){
            if(st[j]!='.'){
                if(flag){
                    tmp2+=st[j];
                }
            }
            else flag=true;
        }
        if(!check[tmp2]) vec.push_back(tmp2);
        ++check[tmp2];
    }
    sort(vec.begin(), vec.end());
    for(int i=0; i<vec.size(); ++i){
        cout<<vec[i]<<' '<<check[vec[i]]<<'\n';
    }
}
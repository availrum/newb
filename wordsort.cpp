#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main(){
    int N;
    cin>>N;
    pair<int, string> a;
    vector<pair<int, string>> sor;
    string st;
    map<string, int> b;
    for(int i=0; i<N; i++){
        cin>>st;
        if(b[st]==1) continue;
        a.first=st.length();
        a.second=st;
        sor.push_back(a);
        b[st]++;
    }
    stable_sort(sor.begin(),sor.end());
    // sort(sor.begin(),sor.end());
    for(int i=0; i<sor.size(); i++){
        cout<< sor.at(i).second <<'\n';
    }
    return 0;
}

#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
int main(){//11235
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    unordered_map<string, int> count, check;
    string name[N];
    int cnt=0;
    for(int i=0; i<N; ++i){
        cin>>name[i];
        ++count[name[i]];
        cnt=max(cnt,count[name[i]]);
    }
    vector<string> candi;
    for(int i=0; i<N; ++i){
        if(count[name[i]]==cnt && check[name[i]]==0){
            candi.push_back(name[i]);
            ++check[name[i]];
        }
    }
    sort(candi.begin(),candi.end());
    for(int i=0; i<candi.size(); ++i){
        cout<<candi[i]<<'\n';
    }
}
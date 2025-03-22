#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
struct tri{
    vector<string> vec;
    unordered_map<string,tri*> next;
    bool isend=false;
};
void insert_tri(tri* a, vector<string> vec, int idx){
    if(idx==vec.size()) return;
    string st=vec[idx];
    if(a->next[st]==nullptr){
        a->next[st] = new tri();
        a->vec.push_back(st);
    }
    insert_tri(a->next[st], vec, idx+1);
    return;
}
void search_tri(tri* a,int dep){
    sort(a->vec.begin(), a->vec.end());
    for(int idx=0; idx<a->vec.size(); ++idx){
        for(int i=0; i<dep; ++i) cout<<"--";
        cout<<a->vec[idx]<<'\n';
        search_tri(a->next[a->vec[idx]], dep+1);
    }
}
int main(){//14725
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int K;
    tri* anthill = new tri();
    for(int i=0; i<N; ++i){
        cin>>K;
        string feed;
        vector<string> inputvec;
        for(int j=0; j<K; ++j){
            cin>>feed;
            inputvec.push_back(feed);
        }
        insert_tri(anthill, inputvec, 0);
    }
    search_tri(anthill, 0);
}
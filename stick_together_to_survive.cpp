#include<iostream>
#include<set>
#include<vector>
using namespace std;
struct unio{
    set<int> check;
};
int main(){ //28277
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,Q,t;
    cin>>N>>Q;
    vector<unio> uni(N);
    for(int i=0; i<N; ++i){
        cin>>t;
        int cur;
        for(int j=0; j<t; ++j){
            cin>>cur;
            int usize=uni[i].check.size();
            uni[i].check.insert(cur);
        }
    }
    for(int i=0; i<Q; ++i){
        int order,num,mnum;
        cin>>order>>num;
        if(order==1){
            cin>>mnum;
            if(uni[num-1].check.size()<uni[mnum-1].check.size()) swap(uni[num-1],uni[mnum-1]);
            
            for(const auto& val:uni[mnum-1].check) uni[num-1].check.insert(val);
            uni[mnum-1].check.clear();
        }
        else{
            cout<<uni[num-1].check.size()<<'\n';
            // for(const auto& val:uni[num-1].check){
            //     cout<<val<<' ';
            // }cout<<'\n';
        }
    }
}
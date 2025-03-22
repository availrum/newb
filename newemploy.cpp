#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first){
        return a.second > b.second;
    }
    return a.first < b.first;
};
int main(){//1946
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int tcase=0; tcase<T; ++tcase){
        int N;
        cin>>N;
        pair<int,int> candi[N];
        for(int i=0; i<N; ++i){
            cin>>candi[i].first>>candi[i].second;
        }
        sort(candi, candi+N, cmp);
        int cnt=0, min_interview=100001;
        for(int i=0; i<N; ++i){
            // cout<<candi[i].first<<' '<<candi[i].second<<'\n';
            if(min_interview > candi[i].second){
                ++cnt;
                min_interview=candi[i].second;
            }
        }
        cout<<cnt<<'\n';
    }
}
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){//14003
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    // vector<int> lis_list;
    // vector<pair<int,int>> tmp_list;
    cin>>N;
    vector<int> pos(N+1,0);
    vector<int> trace(N+1,0);
    int arr[N+1], val[N+1]={0,}, idx=0;
    for(int i=1; i<=N; ++i) cin>>arr[i];
    arr[0]=-1000000001;
    val[0]=-1000000001;
    for(int i=1; i<=N; ++i){
        if(arr[i]>val[idx]){    //이번에 넣는 값이 개수 최대의 값보다 크면
            ++idx;
            val[idx]=arr[i];
            pos[idx]=i;
            trace[i]=pos[idx-1];
            // cout<<i<<"dsdgr\n";
            // lis_list.push_back(val[idx]);
            // for(int j=0; j<tmp_list.size(); ++j){
                // lis_list[tmp_list[j].first]=tmp_list[j].second;
                // cout<<tmp_list[j].first<<' '<<tmp_list[j].second<<'\n';
                // cout<<tmp_list[j].first<<' ';
            // }
            // tmp_list.clear();
            continue;
        }
        int st=1,ed=idx,mid=(st+ed)/2;
        while(st<=ed){
            mid=(st+ed)/2;
            if(arr[i]<=val[mid]) ed=mid-1;
            else st=mid+1;
        }
        val[st]=arr[i];
        pos[st]=i;
        trace[i]=pos[st-1];
        // pair<int,int> tmp;
        // tmp.first=st-1;
        // tmp.second=arr[i];
        // tmp_list.push_back(tmp);
    }
    cout<<idx<<'\n';
    // for(int i=0; i<lis_list.size(); ++i){
    //     cout<<lis_list[i];
    //     if(i!=lis_list.size()-1) cout<<' ';
    // }
    vector<int> lis;
    for (int i=pos[idx]; i!=0; i=trace[i]) lis.push_back(arr[i]);
    reverse(lis.begin(), lis.end());
    for (int i=0; i<lis.size(); ++i) {
        cout<<lis[i];
        if (i != lis.size()-1) cout<<' ';
    }
    cout<<'\n';
    // cout<<'\n';
}
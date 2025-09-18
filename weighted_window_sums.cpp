#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct val{
	long long asum;
	int aidx;
	bool operator< (const val& other) const{
		if(asum!=other.asum) return asum<other.asum;
		else return aidx<other.aidx;
	}
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,K;
    cin>>N>>K;
    long long arr[N], arrsum[N];
    for(int i=0; i<N; ++i){
        cin>>arr[N-i-1];
    }
    for(int i=0; i<N; ++i){
        if(i!=0) arrsum[i]=arrsum[i-1]+arr[i];
        else arrsum[i]=arr[i];
    }
    int st=0, ed=0;
    long long cur_sum=0;
    vector<val> tmp;
    for(ed=0; ed<K; ++ed){
        cur_sum+=arrsum[ed];
    }
    val valtmp={cur_sum,N-K+1};
    
    tmp.push_back(valtmp);
    while(ed<N){
        cur_sum+=(arrsum[ed]-arrsum[st]);
        cur_sum-=(K)*arr[st];
        ++st;
        // cout<<cur_sum<<'\n';
        int tmpidx=N-K-tmp.size()+1;
        valtmp={cur_sum,tmpidx};
        tmp.push_back(valtmp);
        ++ed;
    }
    sort(tmp.begin(), tmp.end());
    for(int i=0; i<tmp.size(); ++i){
        cout<<tmp[i].aidx<<' '<<tmp[i].asum<<'\n';
    }
}
#include<iostream>
#include<deque>
using namespace std;
int main(){//24511
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M,tmp;
    cin>>N;
    int arr[N],arrval[N];
    for(int i=0; i<N; ++i) cin>>arr[i];
    deque<int> deq;
    for(int i=0; i<N; ++i){
        cin>>tmp;
        if(arr[i]) continue;
        deq.push_front(tmp);
    }
    cin>>M;
    for(int i=0; i<M; ++i){
        cin>>tmp;
        deq.push_back(tmp);
        int x=deq.front();
        deq.pop_front();
        cout<<x;
        if(i!=M-1) cout<<' ';
    }
    cout<<'\n';
}
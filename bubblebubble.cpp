#include<iostream>
using namespace std;
int main(){//31870
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int arr[N], arrf[N], arrb[N];
    for(int i=0; i<N; ++i){
        cin>>arr[i];
        arrf[i]=arr[i];
        arrb[i]=arr[i];
    }
    int cntf=0, cntb=0;
    int idx=1;
    while(idx<N){
        int cur=idx;
        while(cur>0 && arrf[cur-1]>arrf[cur]){
            swap(arrf[cur],arrf[cur-1]);
            --cur;
            ++cntf;
        }
        ++idx;
    }
    // for(int i=0; i<N; ++i) cout<<arrf[i];
    idx=1;
    while(idx<N){
        int cur=idx;
        while(cur>0 && arrb[cur-1]<arrb[cur]){
            swap(arrb[cur],arrb[cur-1]);
            --cur;
            ++cntb;
        }
        ++idx;
    }
    // for(int i=0; i<N; ++i) cout<<arrb[i];
    // cout<<cntf<<' '<<cntb<<'\n';
    cout<<min(cntf,cntb+1)<<'\n';
}
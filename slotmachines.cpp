#include<iostream>
using namespace std;
void kmp(int* stat, int* arr, int n){
    int i=-1, j=0;
    stat[j]=i;
    while(j<n){
        if(i==-1 || arr[i]==arr[j]){
            ++i, ++j;
            stat[j]=i;
        }
        else{
            i=stat[i];
        }
    }
}
int main(){//14959
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int stat[N+1]={0,};
    int statinv[N+1]={0,};
    int arr[N];
    int arrinv[N];
    for(int i=0; i<N; ++i){
        cin>>arr[i];
        arrinv[N-1-i]=arr[i];
    }
    kmp(stat,arr,N);
    kmp(statinv,arrinv,N);
    int sol=1000001, ptl=1000001;
    for(int i=1; i<=N; ++i){
        // if(statinv[i]){
            int tmpsol=N-i;
            int tmpptl=i-statinv[i];
            if(tmpsol+tmpptl < sol+ptl){
                sol=tmpsol;
                ptl=tmpptl;
            }
            else if(tmpsol+tmpptl == sol+ptl && ptl > tmpptl){
                sol=tmpsol;
                ptl=tmpptl;
            }
        // }
    }
    cout<<sol<<' '<<ptl<<'\n';
}
#include<iostream>
using namespace std;
void kmp(int* stat, string arr, int n){
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
int main(){//3356
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int stat[N+1]={0,};
    string arr;
    cin>>arr;
    kmp(stat, arr, N);
    int sol=-1;
    sol=N-stat[N];
    cout<<sol<<'\n';
}
#include<iostream>
using namespace std;
int cnt;
void kmp(int* stat, char* pattern, int N){
    int i=-1, j=0;
    stat[j]=i;
    while(j<N){
        if(i==-1 || pattern[i]==pattern[j]){
            ++i, ++j;
            stat[j]=i;
        }
        else{
            i=stat[i];
        }
    }
}
void find_pattern(char* arr, char* pattern, int N){
    int stat[N+1]={0,};
    kmp(stat,pattern, N);
    int i=0, j=0;
    while(i<2*N-1){
        if(j==-1 || arr[i]==pattern[j]){
            ++i, ++j;
        }
        else j=stat[j];

        if(j==N){
            ++cnt;
            j=stat[j];
        }
    }
}
int main(){//11585
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    char rullet[2*N]={0,}, choice[N+1]={0,};
    char tmp;
    for(int i=0; i<N; ++i){
        cin>>tmp;
        rullet[i]=tmp;
    }
    for(int i=N; i<2*N; ++i){
        rullet[i]=rullet[i-N];
    }
    for(int i=0; i<N; ++i){
        cin>>tmp;
        choice[i]=tmp;
    }
    find_pattern(rullet,choice, N);
    for(int i=N-1; i>=2; --i){
        if(cnt%i==0 && N%i==0){
            cnt/=i, N/=i;
        }
    }
    cout<<cnt<<'/'<<N<<'\n';
}
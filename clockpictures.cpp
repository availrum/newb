#include<iostream>
using namespace std;
bool flag=false;
int time_defaul=360000;
void kmp(int* stat, bool* pattern){
    int i=-1, j=0;
    stat[j]=i;
    while(j<time_defaul){
        if(i==-1 || pattern[i]==pattern[j]){
            ++i, ++j;
            stat[j]=i;
        }
        else{
            i=stat[i];
        }
    }
}
void find_pattern(bool* arr, bool* pattern){
    int stat[time_defaul+1]={0,};
    kmp(stat,pattern);
    // cout<<'\n';
    int i=0, j=0;
    while(i<2*time_defaul){
        if(j==-1 || arr[i]==pattern[j]){
            ++i, ++j;
        }
        else j=stat[j];

        if(j==time_defaul){
            flag=true;
            return;
            j=stat[j];
        }
    }
}
int main(){//1786
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    bool clock1[2*time_defaul]={false,}, clock2[time_defaul+1]={false,};
    int tmp;
    // int maxi=-1;
    for(int i=0; i<N; ++i){
        cin>>tmp;
        clock1[tmp]=true;
        // if(maxi<tmp) maxi=tmp;
    }
    for(int i=time_defaul; i<2*time_defaul; ++i){
        clock1[i]=clock1[i-time_defaul];
    }
    for(int i=0; i<N; ++i){
        cin>>tmp;
        clock2[tmp]=1;
    }
    // for(int i=0; i<=maxi; ++i){
    //     cout<<clock1[i];
    // }
    //     cout<<'\n';
    // cout<<"    "<<'\n';
    find_pattern(clock1,clock2);
    if(flag) cout<<"possible"<<'\n';
    else cout<<"impossible"<<'\n';
}
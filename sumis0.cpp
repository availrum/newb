#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#define ll long long int
using namespace std;
ll cal(int n, int a){
    ll tmp=1;
    for(int i=max(a,n-a)+1; i<=n; ++i){
        tmp*=i;
    }
    for(int i=min(a,n-a); i>1; --i){
        tmp/=i;
    }
    return tmp;
}
int main(){ //3151
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int overlab[20001]={0,};
    vector<int> ability;
    for(int i=0; i<N; ++i){
        int tmp;
        cin>>tmp;
        if(!overlab[tmp+10000]) ability.push_back(tmp);
        ++overlab[tmp+10000];
    }
    sort(ability.begin(),ability.end());
    // for(int i=0; i<ability.size(); ++i){
    //     cout<<ability[i]<<' ';
    // }
    // cout<<'\n';
    // for(int i=0; i<ability.size(); ++i){
    //     cout<<overlab[ability[i]+10000]<<' ';
    // }
    // cout<<'\n';
    long long int cnt=0;
    int numb=ability.size();
    for(int i=0; i<numb; ++i){
        for(int j=i; j<numb; ++j){
            int st=j;
            if(i==j){
                if(overlab[ability[i]+10000]<2) continue;
                else if(overlab[ability[j]+10000]<3) st=j+1;
                else st=j;
            }
            else if(overlab[ability[j]+10000]<2) st=j+1;
            else st=j;
            int ed=numb-1;
            int mid;
            while(st<=ed){
                mid=(st+ed)/2;
                if(ability[i]+ability[j]+ability[mid]>0){
                    ed=mid-1;
                }
                else if(ability[i]+ability[j]+ability[mid]<0){
                    st=mid+1;
                }
                else{
                    if(ability[i]==ability[j]){
                        if(ability[j] == ability[mid]) cnt+=cal(overlab[ability[i]+10000],3);
                        else cnt+=cal(overlab[ability[i]+10000],2)*overlab[ability[mid]+10000];
                    }
                    else if(ability[j] == ability[mid]) cnt+=overlab[ability[i]+10000]*cal(overlab[ability[j]+10000],2);
                    else cnt+=overlab[ability[i]+10000]*overlab[ability[j]+10000]*overlab[ability[mid]+10000];
                    break;
                }
            }
        }
    }
    cout<<cnt<<'\n';
} 
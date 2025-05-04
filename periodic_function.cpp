#include<iostream>
using namespace std;
#define ll long long int
void kmp(ll* stat, ll* pattern, ll length){
    int i=-1, j=0;
    stat[j]=i;
    while(j<length){
        if(i==-1 || pattern[i]==pattern[j]){
            ++i;
            ++j;
            stat[j]=i;
        }
        else{
            i=stat[i];
        }
    }
}
int main(){//31807
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll L;
    cin>>L;
    ll stat[L+1], arr[L];
    for(int i=0; i<L; ++i){
        cin>>arr[i];
    }
    ll a,b;
    cin>>a>>b;
    kmp(stat,arr,L);
    ll pattern_length=L-stat[L];
    ll pattern_value=0;
    for(int i=0; i<pattern_length; ++i){
        pattern_value+=arr[i];
    }
    ll range=b-a;
    if(range%pattern_length==0){
        cout<<pattern_value*range/pattern_length<<'\n';
    }
    else{
        ll tmpleng=pattern_length-range%pattern_length;
        ll tmp=pattern_value*(range/pattern_length);
        if(a>=0){
            for(int i=0; i<range%pattern_length; ++i){
                tmp+=arr[a%pattern_length+i];
            }
        }
        else{
            a%=pattern_length;
            a+=pattern_length;
            for(int i=0; i<range%pattern_length; ++i){
                tmp+=arr[a%pattern_length+i];
            }
        }
        cout<<tmp<<'\n';
    }
}
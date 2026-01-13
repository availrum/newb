#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int gcd(int a, int b){
    if(a<b) swap(a,b);
    while(a%b!=0){
        int tmp=a%b;
        a=b;
        b=tmp;
    }
    return b;
}
string cal(string a, int factor){
    string sol="";
    int remain=0;
    for(int i=a.length()-1; i>=0; --i){
        int tmp=(a[i]-'0')*factor+remain;
        sol+=to_string(tmp%10);
        remain=tmp/10;
    }
    while(remain){
        sol+=to_string(remain%10);
        remain/=10;
    }
    reverse(sol.begin(),sol.end());
    // cout<<sol<<'\n';
    return sol;
}
int main(){ //2407
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    vector<int> vec;
    for(int i=max(M,N-M)+1; i<=N; ++i) vec.push_back(i);
    for(int i=2; i<=min(M,N-M); ++i){
        int tmp=i;
        for(int j=0; j<vec.size(); ++j){
            int gcdvalue=gcd(tmp,vec[j]);
            while(gcdvalue!=1){
                tmp/=gcdvalue;
                vec[j]/=gcdvalue;
                gcdvalue=gcd(tmp,vec[j]);
            }
            if(tmp==1) break;
        }
    }
    string sol="1";
    // int sol=1;
    for(int i=0; i<vec.size(); ++i){
        sol=cal(sol,vec[i]);
        // sol*=vec[i];
        // cout<<vec[i]<<' '<<sol<<'\n';
    }
    cout<<sol<<'\n';
}
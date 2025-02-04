#include<iostream>
#include<vector>
using namespace std;
long long int mdl=1000000007;
long long int ferma(long long int x, long long int num){
    if(num==0){
        return 1;
    }
    if(num==1){
        // save.push_back(x);
        return x;
    }
    if(num%2==0){
        long long int tmp=ferma(x,num/2);
        return ((tmp%mdl)*(tmp%mdl))%mdl;
    }
    else {
        long long int tmp=ferma(x,(num-1)/2);
        return ((((tmp%mdl)*(tmp%mdl))%mdl)*x)%mdl;
    }
}
int main(){//13172
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int M;
    cin>>M;
    long long int Nplane, dicesum;
    long long int expectval=0;
    for(int i=0; i<M; ++i){
        cin>>Nplane>>dicesum;
        // vector<long long int> saveval;
        long long int rvs = ferma(Nplane, mdl-2);
        expectval=(expectval+((dicesum*rvs)%mdl))%mdl;
    }
    cout<<expectval<<'\n';
}
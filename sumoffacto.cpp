#include<iostream>
#include<vector>
using namespace std;
int main(){//9506
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    while(true){
        cin>>N;
        if(N==-1) break;
        int sum=0;
        vector<int> vec;
        for(int i=1; i<=N/2; ++i){
            if(N%i==0){
                sum+=i;
                vec.push_back(i);
                // cout<<i<<'\n';
            }
        }
        cout<<N;
        if(sum==N){
            cout<<" = ";
            for(int i=0; i<vec.size(); ++i){
                if(i<vec.size()-1) cout<<vec[i]<<" + ";
                else  cout<<vec[i];
            }
            cout<<'\n';
        }
        else cout<<" is NOT perfect."<<'\n';
    }
}
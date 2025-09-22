#include<iostream>
#include<vector>
using namespace std;
void multi(vector<vector<int>>& a, vector<vector<int>>& b, vector<vector<int>>& sol){
    for(int i=0; i<sol.size(); ++i){
        for(int j=0; j<sol[0].size(); ++j){
            for(int k=0; k<b.size(); ++k){
                sol[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
}
int main(){ //15836
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int M,N,P,Q;
    int tcase=1;
    while(cin>>M>>N>>P>>Q){
        if(M==0) break;
        cout<<"Case #"<<tcase<<":"<<'\n';
        vector<vector<int>> arr1(M), arr2(P);
        int tmp;
        for(int i=0; i<M; ++i){
            for(int j=0; j<N; ++j){
                cin>>tmp;
                arr1[i].push_back(tmp);
            }
        }
        for(int i=0; i<P; ++i){
            for(int j=0; j<Q; ++j){
                cin>>tmp;
                arr2[i].push_back(tmp);
            }
        }
        if(N!=P){
            cout<<"undefined\n";
        }
        else{
            vector<vector<int>> arrC(M, vector<int>(Q,0));
            multi(arr1,arr2,arrC);
            for(int i=0; i<arrC.size(); ++i){
                cout<<"| ";
                for(int j=0; j<arrC[0].size(); ++j){
                    cout<<arrC[i][j];
                    if(j!=arrC[0].size()-1) cout<<' ';
                    else cout<<" |\n";
                }
            }
        }
        ++tcase;
    }
}
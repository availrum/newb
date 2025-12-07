#include<iostream>
#include<vector>
using namespace std;
const int divi=9901;
int main(){ //1309
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    vector<vector<int>> cage(N,vector<int>(3,0));
    cage[0][0]=1;
    cage[0][1]=1;
    cage[0][2]=1;
    for(int i=1; i<N; ++i){
        for(int j=0; j<3; ++j){
            // cage[i][j]=cage[i-1][1-j]*2;
            cage[i][0]=(cage[i][0]%divi)+(cage[i-1][j]%divi);
            if(j==0 || j==1) cage[i][2]=(cage[i][2]%divi)+(cage[i-1][j]%divi);
            if(j==0 || j==2) cage[i][1]=(cage[i][1]%divi)+(cage[i-1][j]%divi);
        }
    }
    cout<<(cage[N-1][0]+cage[N-1][1]+cage[N-1][2])%divi<<'\n';
}
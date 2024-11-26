#include<iostream>
#include<vector>
using namespace std;
vector<int> vec;
int dp[5][5][100001];
int dif(int a, int b){
    if(a==0 || b==0) return 2;
    else if(a==b) return 1;
    else if(abs(a-b)==2) return 4;
    else return 3;
}
int cal(int x, int y, int cur){
    if(cur==vec.size()) return 0;
    if(dp[x][y][cur]) return dp[x][y][cur];
    int rfoot=cal(vec[cur],y,cur+1)+dif(x,vec[cur]);
    int lfoot=cal(x,vec[cur],cur+1)+dif(y,vec[cur]);
    return dp[x][y][cur]=min(rfoot,lfoot);
}
int main(){//2342
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tmp;
    while(cin>>tmp){
        if(tmp==0) break;
        vec.push_back(tmp);
    }
    int sol=cal(0,0,0);
    cout<<sol<<'\n';
}
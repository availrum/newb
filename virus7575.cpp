#include<iostream>
#include<vector>
using namespace std;
void kmp(int* stat, vector<int> pattern, int left, int right){
    int n = right-left+1;
    int i=-1, j=0;
    stat[j]=i;
    while(j<n){
        if(i==-1 || pattern[i+left]==pattern[j+left]){
            ++i, ++j;
            stat[j]=i;
        }
        else{
            i=stat[i];
        }
    }
}
bool find_pattern(vector<int> whole, vector<int> pattern, int left, int right, int* stat){
    int n=whole.size();
    int m=right-left+1;
    int i=0, j=0;
    bool flag=false;
    while(i<n){
        if(j==-1 || whole[i]==pattern[j+left]){
            ++i, ++j;
        }
        else j=stat[j];

        if(j==m){
            flag=true;
            j=stat[j];
            return true;
        }
    }
    return false;
}
int main(){//7575
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, K, M, tmp;
    cin>>N>>K;
    vector<vector<int>> code(N);
    // vector<int> twoline;
    int firleng;
    for(int i=0; i<N; ++i){
        cin>>M;
        for(int j=0; j<M; ++j){
            cin>>tmp;
            code[i].push_back(tmp);
            // if(i<2) twoline.push_back(tmp);
        }
        if(i==0) firleng=M;
    }
    int left=0, right=K-1;
    bool flag=true;


    while(right<firleng){
        int stat[K+1]={0,};
        kmp(stat, code[0], left, right);
        for(int i=1; i<N; ++i){
            flag=find_pattern(code[i], code[0], left, right, stat);
            if(!flag){
                int statinv[K+1]={0,};
                vector<int> rcode;
                for(int j=right; j>=left; --j) rcode.push_back(code[0][j]);
                kmp(statinv,rcode,0,K-1);
                flag=find_pattern(code[i],rcode,0,K-1,statinv);
            }
            if(!flag) break;
        }
        if(flag) break;
        ++left;
        ++right;
    }
    if(flag) cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
}
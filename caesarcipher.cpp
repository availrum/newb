#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
void kmp(int* stat, vector<int>& pattern){
    int n=pattern.size();
    int i=-1, j=0;
    stat[j]=i;
    while(j<n){
        if(i==-1 || pattern[i]==pattern[j]){
            ++i;
            ++j;
            stat[j]=i;
        }
        else i=stat[i];
    }
} 
int find_pattern(vector<int>& arr, vector<int>& pattern){
    int n=arr.size();
    int m=pattern.size();
    int stat[m+1];
    kmp(stat,pattern);
    int i=0, j=0, cnt=0;
    while(i<n){
        if(j==-1 || arr[i]==pattern[j]){
            ++i;
            ++j;
        }
        else j=stat[j];
        if(j==m){
            j=stat[j];
            ++cnt;
        }
    }
    return cnt;
}
int main(){//1893
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    for(int tcase=0; tcase<N; ++tcase){
        string A,W,S;
        cin>>A>>W>>S;
        vector<int> sol, cipher;
        unordered_map<char,int> numb, alpha;
        for(int i=0; i<A.length(); ++i){ //원본 알파벳 순서
            numb[A[i]]=i;
            //W[0]~W[w]에서 numb[W[0]+trans] ~ numb[W[w]+trans]가 무슨 알파벳인지 찾아야함
            alpha[i]=A[i];
        }
        for(int i=0; i<S.length(); ++i){
            cipher.push_back(S[i]);
        }
        // for(int i=0; i<S.length(); ++i) cout<<cipher[i]<<' ';
        // cout<<'\n';

        // if(W.length()>1){
        for(int trans=0; trans<A.length(); ++trans){
            vector<int> origin;
            for(int i=0; i<W.length(); ++i){
                origin.push_back(alpha[(numb[W[i]]+trans)%A.length()]);
            }
            int cnt=find_pattern(cipher,origin);
            if(cnt==1){
                sol.push_back(trans);
            }
        }
        if(!sol.size()) cout<<"no solution"<<'\n';
        else if(sol.size()>1){
            cout<<"ambiguous: ";
            for(int i=0; i<sol.size(); ++i){
                cout<<sol[i];
                if(i!=sol.size()-1) cout<<' ';
                else cout<<'\n';
            }
        }
        else cout<<"unique: "<<sol[0]<<'\n';
    }
}
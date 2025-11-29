#include<iostream>
#include<vector>
using namespace std;
int N;
void btr(int num, vector<int> vec, bool* used){
    if(vec.size()==N){
        for(int i=0; i<N; ++i){
            cout<<vec[i];
            if(i!=N-1) cout<<' ';
            else cout<<'\n';
        }
        return;
    }
    for(int i=1; i<=N; ++i){
        if(used[i]) continue;
        used[i]=true;
        vec.push_back(i);
        btr(num+1,vec,used);
        vec.pop_back();
        used[i]=false;
    }
}
int main(){ //10974
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    vector<int> vec;
    bool used[N+1]={false,};
    btr(1,vec,used);
} 
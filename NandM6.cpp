#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,M;
void btr(int* arr, vector<int> candi, int idx){
    if(candi.size()==M){
        for(int i=0; i<candi.size(); ++i){
            cout<<candi[i];
            if(i!=candi.size()-1) cout<<' ';
            else cout<<'\n';
        }
        return;
    }
    for(int i=idx; i<N; ++i){
        candi.push_back(arr[i]);
        btr(arr,candi,i+1);
        candi.pop_back();
    }
}
int main(){ //15655
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    int arr[N];
    for(int i=0; i<N; ++i){
        cin>>arr[i];
    }
    vector<int> candi;
    sort(arr,arr+N);

    btr(arr, candi, 0);
} 
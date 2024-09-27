#include<iostream>
#include<stack>
#include<deque>
#include<vector>
using namespace std;
int main(){//30805
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N;
    int arr1[N+1];
    for(int i=0; i<N; ++i) cin>>arr1[i];
    cin>>M;
    int arr2[M+1];
    for(int i=0; i<M; ++i) cin>>arr2[i];

    deque<pair<int,int>> qu;
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=M; ++j){
            if(arr1[i-1]==arr2[j-1]){
                if(qu.empty()) qu.push_back({i-1,j-1});
                else if(arr1[qu.front().first] < arr1[i-1]){
                    qu.clear();
                    qu.push_back({i-1,j-1});
                }
                else if(arr1[qu.back().first] < arr1[i-1]){
                    stack<pair<int,int>> tmpst;
                    while(arr1[qu.back().first]<arr1[i-1]){
                        tmpst.push(qu.back());
                        qu.pop_back();
                    }
                    if(qu.back().first < i-1 && qu.back().second<j-1){
                        qu.push_back({i-1,j-1});
                    }
                    else{
                        while(!tmpst.empty()){
                            qu.push_back(tmpst.top());
                            tmpst.pop();
                        }
                    }
                }
                else if(qu.back().first < i-1 && qu.back().second<j-1){
                    qu.push_back({i-1,j-1});
                }
            }
        }
    }
    int leng=qu.size();
    cout<<leng<<'\n';
    if(leng){
        // while(!qu.empty()){
        for(int i=0; i<leng; ++i){
            cout<<arr1[qu.front().first];
            qu.pop_front();
            // if(!qu.empty()) cout<<' ';
            if(i!=leng-1) cout<<' ';
        }
        cout<<'\n';
    }
}
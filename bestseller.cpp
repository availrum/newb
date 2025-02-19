#include<iostream>
#include<unordered_map>
using namespace std;
int main(){//1302
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    unordered_map<string,int> check;
    string st;
    pair<string,int> bestseller;
    for(int i=0; i<N; ++i){
        cin>>st;
        ++check[st];
        if(bestseller.second < check[st]){
            bestseller.first=st;
            bestseller.second=check[st];
        }
        else if(bestseller.second == check[st]){
            if(bestseller.first > st){
                bestseller.first=st;
            }
        }
    }
    cout<<bestseller.first<<'\n';
}
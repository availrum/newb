#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool com(int a, int b){
    return a>b;
}
int main(){//10610
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string N;
    cin>>N;
    bool isten=false;
    int isthree=0;
    vector<int> vec;
    for(int i=0; i<N.length(); ++i){
        if(N[i]=='0'){
            isten=true;
        }
        isthree+=(N[i]-'0');
        vec.push_back(N[i]-'0');
        // cout<<N[i]-'0'<<'\n';
    }
    if(!isten || isthree%3 != 0){
        cout<<"-1"<<'\n';
        return 0;
    }
    else{
        sort(vec.begin(), vec.end(), com);
        string sol="";
        for(int i=0; i<vec.size(); ++i){
            sol+=to_string(vec[i]);
        }
        cout<<sol<<'\n';
    }
}
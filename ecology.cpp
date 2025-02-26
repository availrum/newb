#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
int main(){//4358
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    unordered_map<string, int> tree;
    vector<string> vec;
    string st;
    double n=0;
    while(getline(cin,st)){
        if(tree[st]==0){
            vec.push_back(st);
        }
        ++tree[st];
        n+=1;
        // if(st=="00") break;
    }
    cout<<fixed;
    cout.precision(4);
    sort(vec.begin(), vec.end());
    for(int i=0; i<vec.size(); ++i){
        // cout<<"vec[i]="<<vec[i]<<", percentile = "<<tree[vec[i]]/n * 100<<'\n';
        cout<<vec[i]<<' '<<tree[vec[i]]/n * 100<<'\n';
    }
}
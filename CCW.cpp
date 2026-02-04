#include<iostream>
using namespace std;
int main(){ //11758
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    pair<int,int> coord[3];
    for(int i=0; i<3; ++i){
        cin>>coord[i].first>>coord[i].second;
    }
    pair<int,int> l1={coord[1].first-coord[0].first, coord[1].second-coord[0].second};
    pair<int,int> l2={coord[2].first-coord[1].first, coord[2].second-coord[1].second};

    int cross=l1.first*l2.second-l1.second*l2.first;
    if(cross<0) cout<<"-1\n";
    else if(cross>0) cout<<"1\n";
    else cout<<"0\n";
}
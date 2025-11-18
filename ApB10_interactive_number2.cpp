#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){ //30924
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a=0,b=0;
    int tmp;
    vector<int> vec;
    for(int i=1; i<=10000; ++i) vec.push_back(i);
    random_shuffle(vec.begin(),vec.end());
    for(int i=0; i<vec.size()-1; ++i){
        cout<<"? A "<<vec[i]<<endl;
        cin>>tmp;
        if(tmp){
            a=vec[i];
            break;
        }
        if(i==vec.size()-2) a=vec[i+1];
    }
    for(int i=0; i<vec.size()-2; ++i){
        cout<<"? B "<<vec[i]<<endl;
        cin>>tmp;
        if(tmp){
            b=vec[i];
            break;
        }
        if(i==vec.size()-3) b=vec[i+1];
    }
    cout<<"! "<<a+b<<'\n';
}
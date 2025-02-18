#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int main(){//9536
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int tcase=0; tcase<T; ++tcase){
        string st, last="";
        unordered_map<string,int> check;
        vector<string> vec;
        bool flag=false, flagf=false;
        while(true){
            cin>>st;
            if(st=="goes"){
                flagf=true;
                flag=true;
                continue;
            }
            else if(!flagf){
                vec.push_back(st);
            }
            else if(flag){
                ++check[st];
                flag=false;
                last="";
            }
            else if(!flag){
                last+=st;
                if(last=="whatdoesthefoxsay?") break;
            }
        }
        for(int i=0; i<vec.size()-1; ++i){
            if(!check[vec[i]]){
                cout<<vec[i];

                if(i!=vec.size()-2) cout<<' ';
            }
        }
        cout<<'\n';
    }
}
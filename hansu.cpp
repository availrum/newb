#include<iostream>
#include<vector>
using namespace std;
int main(){ //1065
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    // int numb[N+1]={0,};
    int cnt=0;
    for(int i=1; i<=N; ++i){
        int tmp=i;
        vector<int> vec;
        int divide=1000;
        while(divide>0){
            if(!(vec.size()==0 && tmp/divide==0)){
                vec.push_back(tmp/divide);
                tmp%=divide;
            }
            divide/=10;
        }
        bool flag=true;
        int dif;
        if(vec.size()>1) dif=vec[0]-vec[1];

        for(int j=1; j<vec.size()-1; ++j){
            if(vec[j]-vec[j+1]!=dif){
                flag=false;
                break;
            }
        }
        // for(int i=0; i<vec.size(); ++i) cout<<vec[i];
        // cout<<'\n';
        if(flag) ++cnt;
    }
    cout<<cnt<<'\n';
}
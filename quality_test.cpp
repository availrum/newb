#include<iostream>
#include<vector>
using namespace std;
struct comp{
    int pw;
    int mt;
    int cb;
    bool inspection;
};
int main(){ //5600
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a,b,c;
    cin>>a>>b>>c;
    int N;
    cin>>N;
    int power[a]={0,}, motor[b]={0,}, cable[c]={0,};
    vector<comp> vec;
    for(int i=0; i<N; ++i){
        int pa,pb,pc;
        bool r;
        cin>>pa>>pb>>pc>>r;
        if(r==true){
            power[pa-1]=2;
            motor[pb-a-1]=2;
            cable[pc-a-b-1]=2;
        }
        else vec.push_back({pa-1,pb-a-1,pc-a-b-1,r});
    }
    for(int i=0; i<vec.size(); ++i){
        if(power[vec[i].pw]+motor[vec[i].mt]+cable[vec[i].cb]==4){
            if(power[vec[i].pw]==0) power[vec[i].pw]=1;
            else if(motor[vec[i].mt]==0) motor[vec[i].mt]=1;
            else if(cable[vec[i].cb]==0) cable[vec[i].cb]=1;
        }
    }
    for(int i=0; i<(a+b+c); ++i){
        if(i<a){
            int sol=power[i];
            if(sol==2) cout<<"1\n";
            else if(sol==1) cout<<"0\n";
            else if(sol==0) cout<<"2\n";
        }
        else if(i<a+b){
            int sol=motor[i-a];
            if(sol==2) cout<<"1\n";
            else if(sol==1) cout<<"0\n";
            else if(sol==0) cout<<"2\n";
        }
        else if(i<a+b+c){
            int sol=cable[i-a-b];
            if(sol==2) cout<<"1\n";
            else if(sol==1) cout<<"0\n";
            else if(sol==0) cout<<"2\n";
        }
    }
}
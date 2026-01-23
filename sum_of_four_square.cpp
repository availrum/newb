#include<iostream>
#include<vector>
using namespace std;
int main(){ //2669
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<vector<bool>> plane(101,vector<bool>(101,false));
    // vector<vector<bool>> dot(101,vector<bool>(101,false));
    for(int i=0; i<4; ++i){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        for(int j=x1; j<x2; ++j){
            for(int k=y1; k<y2; ++k){
                plane[j][k]=true;
                // if(k!=y1) dot[j][k]=true;
            }
        }
    }
    int cnt=0;
    for(int i=1; i<101; ++i){
        int leng=0;
        for(int j=1; j<101; ++j){
            // cout<<plane[i][j]<<' ';

            if(plane[i][j]){
                ++leng;
            }
            else{
                if(leng!=0) cnt+=(leng);
                leng=0;
            }
        }
        if(leng!=0) cnt+=(leng);
        // cout<<'\n';
    }
    cout<<cnt<<'\n';
}
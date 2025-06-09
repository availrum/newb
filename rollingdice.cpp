#include<iostream>
#include<vector>
using namespace std;
// 2     2     2    2    6   1
//136   364   641  413  423 453
// 5     5     5    5    1   6
// 4     1     3    6    5   2
// int rolldice(int bottom, int bef_dir, int dir){
//     vector<vector<int>> dice(7);
//     dice[1]={3,5,4,2};
//     dice[2]={3,1,4,6};
//     dice[3]={6,5,1,2};
//     dice[4]={1,5,6,2};
//     dice[5]={3,6,4,1};
//     dice[6]={4,5,3,2};
//     int direction=bef_dir;
//     if(bef_dir==0)
//     return dice[bottom][dir-1];
// }
void movedice(vector<vector<int>>& minimap, int num, int& x, int& y, int* diceud, int* dicelr){
    if(num==1){
        if(y+1>=minimap[0].size()) return;

        for(int i=2; i>0; --i){
            swap(dicelr[i],dicelr[i-1]);
        }
        swap(dicelr[0],diceud[3]);
        diceud[1]=dicelr[1];
        
        if(minimap[x][y+1]){
            diceud[3]=minimap[x][y+1];
            minimap[x][y+1]=0;
        }
        else{
            minimap[x][y+1]=diceud[3];
        }
        cout<<diceud[1]<<'\n';
        ++y;
    }
    else if(num==2){
        if(y-1<0) return;

        for(int i=0; i<2; ++i){
            swap(dicelr[i],dicelr[i+1]);
        }
        swap(dicelr[2],diceud[3]);
        diceud[1]=dicelr[1];
        
        if(minimap[x][y-1]){
            diceud[3]=minimap[x][y-1];
            minimap[x][y-1]=0;
        }
        else{
            minimap[x][y-1]=diceud[3];
        }
        cout<<diceud[1]<<'\n';
        --y;
    }
    else if(num==3){
        if(x-1<0) return;
        --x;

        for(int i=0; i<3; ++i){
            swap(diceud[i],diceud[i+1]);
        }
        dicelr[1]=diceud[1];
        
        if(minimap[x][y]){
            diceud[3]=minimap[x][y];
            minimap[x][y]=0;
        }
        else{
            minimap[x][y]=diceud[3];
        }
        cout<<diceud[1]<<'\n';
    }
    else if(num==4){
        if(x+1>=minimap.size()) return;
        ++x;
        for(int i=3; i>0; --i){
            swap(diceud[i],diceud[i-1]);
        }
        dicelr[1]=diceud[1];
        
        if(minimap[x][y]){
            diceud[3]=minimap[x][y];
            minimap[x][y]=0;
        }
        else{
            minimap[x][y]=diceud[3];
        }
        cout<<diceud[1]<<'\n';
    }
}
int main(){//14499
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    // int minimap[N][M];
    vector<vector<int>> minimap(N);
    int x,y,K;
    int tmp;
    cin>>x>>y>>K;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin>>tmp;
            // minimap[i][j];
            minimap[i].push_back(tmp);
        }
    }
    int diceud[4]={0,0,0,0};//{2,1,5,6};
    int dicelr[3]={0,0,0};//{4,1,3};
    for(int i=0; i<K; ++i){
        cin>>tmp;
        movedice(minimap, tmp, x, y, diceud, dicelr);
        // cout<<'\n';
        // for(int i=0; i<minimap.size(); ++i){
        //     for(int j=0; j<minimap[i].size(); ++j){
        //         cout<<minimap[i][j]<<' ';
        //     }
        //     cout<<'\n';
        // }

        // cout<<"  "<<diceud[0]<<'\n';
        // cout<<dicelr[0]<<' '<<dicelr[1]<<' '<<dicelr[2]<<'\n';
        // cout<<"  "<<diceud[2]<<'\n';
        // cout<<"  "<<diceud[3]<<'\n';
    }
}
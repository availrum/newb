#include<iostream>
using namespace std;
bool checksquare[10][10]; //한 줄에 하나씩 넣었을때
bool checkrow[10][10]; //행단위 체크
bool checkcol[10][10]; // 
bool flag;
int sdok[10][10];
void rec(int N){
    if(flag) return;
    if(N==81){
        for(int i=0; i<9; ++i) for(int j=0; j<9; ++j){
            cout<<sdok[i][j];
            if(j==8) cout<<'\n';
            else cout<<' ';
            flag=true;
        }
        return;
    }
    int x=N/9, y=N%9;
    int numsq=3*(x/3)+(y/3);
    if(sdok[x][y]){
        rec(N+1);
        return;
    }
    for(int i=1; i<=9; ++i){
        if(checkrow[x][i] || checkcol[y][i] || checksquare[numsq][i]) continue;

        // if(checksquare[i] || checkrow[x+i] || checkcol[x+N-1-i]) continue;
        sdok[x][y]=i;
        checksquare[numsq][i]=true;
        checkrow[x][i]=true;
        checkcol[y][i]=true;
        rec(N+1);
        sdok[x][y]=0;
        checksquare[numsq][i]=false;
        checkrow[x][i]=false;
        checkcol[y][i]=false;
    }
}
int main(){//2580
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0; i<9; ++i) for(int j=0; j<9; ++j){
        cin>>sdok[i][j];
        if(sdok[i][j]){
            checksquare[3*(i/3)+(j/3)][sdok[i][j]]=true;
            checkrow[i][sdok[i][j]]=true;
            checkcol[j][sdok[i][j]]=true;
        }
    }
    rec(0);
    // cout<<cnt<<'\n';
}
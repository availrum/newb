#include<iostream>
#include<queue>
using namespace std;
int main(){//12852
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int number[3*N+1]={0,};
    int pth[3*N+1]={0,};
    queue<int> qu;
    qu.push(1);
    while(!number[N]){
        int x=qu.front();
        qu.pop();
        if(x>=N) continue;
        if(!number[3*x]){
            number[3*x]=number[x]+1;
            pth[3*x]=x;
            qu.push(3*x);
        }
        if(!number[2*x]){
            number[2*x]=number[x]+1;
            pth[2*x]=x;
            qu.push(2*x);
        }
        if(!number[x+1]){
            number[x+1]=number[x]+1;
            pth[x+1]=x;
            qu.push(x+1);
        }
    }
    number[1]=0;
    cout<<number[N]<<'\n';
    int tmp=N;
    if(tmp>1){
        while(true){
            if(tmp!=1){
                cout<<tmp<<' ';
                tmp=pth[tmp];
            }
            else{
                cout<<tmp<<'\n';
                break;
            }
        }
    }
    else cout<<"1"<<'\n';
}
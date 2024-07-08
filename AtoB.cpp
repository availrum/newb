#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;
int main(){//16953
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int A,B;
    int sol=-1;
    queue<int> qu;
    unordered_map<int,int> ma;
    cin>>A>>B;
    qu.push(A);
    ma[A]=1;
    while(!qu.empty()){
        long long int x=qu.front();
        qu.pop();
        if(2*x<=B){
            qu.push(2*x);
            if(ma[2*x]==0 || ma[2*x]>ma[x]+1) ma[2*x]=ma[x]+1;
        }
        if(10*x+1<=B){
            qu.push(10*x+1);
            if(ma[10*x+1]==0 || ma[10*x+1]>ma[x]+1) ma[10*x+1]=ma[x]+1;
        }

        if(x==B){
            if(sol>ma[x] && ma[x]!=0) sol=ma[x];
            else if(sol==-1 && ma[x]!=0) sol=ma[x];
        }
    }
    cout<<sol<<'\n';
}
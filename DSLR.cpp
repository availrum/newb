#include<iostream>
#include<queue>
using namespace std;
int main(){//9019
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int i=0; i<T; ++i){
        int A,B;
        queue<int> qu;
        cin>>A>>B;
        qu.push(A);
        int shorte[10000]={0,};
        bool visited[10000]={0,};
        string cmd[10000];
        for(int j=0; j<10000; ++j) cmd[j]="";
        visited[A]=true;
        while(!qu.empty()){
            int x=qu.front();
            qu.pop();
            // cout<<x<<'\n';
            if(x==B) break;
            if(2*x<10000){
                if(!visited[2*x] || shorte[2*x]>shorte[x]+1) {
                    qu.push(2*x);
                    visited[2*x]=true;
                    shorte[2*x]=shorte[x]+1;
                    cmd[2*x]=cmd[x]+"D";
                    if(2*x==B) break;
                }
            }
            else if(2*x>=10000){
                if(!visited[(2*x)%10000] || shorte[(2*x)%10000]>shorte[x]+1) {
                    qu.push((2*x)%10000);
                    visited[(2*x)%10000]=true;
                    shorte[(2*x)%10000]=shorte[x]+1;
                    cmd[(2*x)%10000]=cmd[x]+"D";
                    if((2*x)%10000==B) break;
                }
            }
            if(x-1>=0){
                if(!visited[x-1] || shorte[x-1]>shorte[x]+1){
                    qu.push(x-1);
                    visited[x-1]=true;
                    shorte[x-1]=shorte[x]+1;
                    cmd[x-1]=cmd[x]+"S";
                    if(x-1==B) break;
                }
            }
            else if(x-1<0){
                if(!visited[x+9999] || shorte[x+9999]>shorte[x]+1){
                    qu.push(x+9999);
                    visited[x+9999]=true;
                    shorte[x+9999]=shorte[x]+1;
                    cmd[x+9999]=cmd[x]+"S";
                    if(x+9999==B) break;
                }
            }
            if(x*10>=10000){
                int tmpl=x/1000;
                if(!visited[(x*10)%10000+tmpl] || shorte[(x*10)%10000+tmpl]>shorte[x]+1){
                    qu.push((x*10)%10000+tmpl);
                    visited[(x*10)%10000+tmpl]=true;
                    shorte[(x*10)%10000+tmpl]=shorte[x]+1;
                    cmd[(x*10)%10000+tmpl]=cmd[x]+"L";
                    if((x*10)%10000+tmpl==B) break;
                }
            }
            else if(x*10<10000){
                if(!visited[x*10] || shorte[x*10]>shorte[x]+1){
                    qu.push(x*10);
                    visited[x*10]=true;
                    shorte[x*10]=shorte[x]+1;
                    cmd[x*10]=cmd[x]+"L";
                    if(x*10==B) break;
                }
            }
            if(x%10!=0){
                int tmpr=x%10;
                if(!visited[x/10+tmpr*1000] || shorte[x/10+tmpr*1000]>shorte[x]+1){
                    qu.push(x/10+tmpr*1000);
                    visited[x/10+tmpr*1000]=true;
                    shorte[x/10+tmpr*1000]=shorte[x]+1;
                    cmd[x/10+tmpr*1000]=cmd[x]+"R";
                    if(x/10+tmpr*1000==B) break;
                }
            }
            else if(x%10==0){
                if(!visited[x/10] || shorte[x/10]>shorte[x]+1){
                    qu.push(x/10);
                    visited[x/10]=true;
                    shorte[x/10]=shorte[x]+1;
                    cmd[x/10]=cmd[x]+"R";
                    if(x/10==B) break;
                }
            }
            
        }
        // cout<<shorte[B]<<'\n';
        cout<<cmd[B]<<'\n';
    }
}
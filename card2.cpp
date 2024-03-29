#include<iostream>
#include<queue>
using namespace std;
int main(){//11866
    int N,K,sol=0;
    string st;
    queue<int> yosi;
    cin>>N;
    for(int i=0; i<N; i++){//Input initial data to queue
        yosi.push(i+1);
    }
    for(int i=0; i<N; i++){
        if(yosi.size()==1){
            cout<<yosi.front()<<'\n';
            break;
        }
        if(yosi.empty()==1) {
            break;
        }
        yosi.pop();
        yosi.push(yosi.front()); 
        yosi.pop();
        
    }
    return 0;
}
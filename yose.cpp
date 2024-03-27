#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){//11866
    int N,K,sol=0;
    string st;
    queue<int> yosi;
    cin>>N>>K;
    for(int i=0; i<N; i++){//Input initial data to queue
        yosi.push(i+1);
    }
    cout<<"<";
    for(int i=0; i<N; i++){// 12/4567(6)>1245/7(2)>1/457(7)>/145(5)>14(1)>4(4)
        if(K==1){//K=1 case
            for(int j=0; j<N; j++){
                if(j==N-1){
                    cout<<j+1;
                    break;
                }
                cout<<j+1<<", ";
            }
            cout<<">"<<'\n';
            return 0;
        }
        if(yosi.empty()==1) {
            break;
        }
        for(int j=0; j<K; j++){
            if(j==K-1) {
                cout<<yosi.front();
                yosi.pop();
                break;
            }
            yosi.push(yosi.front()); 
            yosi.pop();
        }
        if(i==N-1) break;
        cout<<", ";
    }
    cout<<">"<<'\n';
    return 0;
}
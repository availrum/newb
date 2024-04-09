#include<iostream>
#include<algorithm>
using namespace std;

int main(){//11723
    int test,proc,sol=0;
    string st;
    cin>>test;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0; i<test; i++){
        cin>>st;
        if(st=="all"){
            for(int j=0; j<20; j++){
                sol=(sol|(1<<j));
            }
            continue;
            // sol=1;
        }
        else if(st=="empty"){
            sol=0;
            continue;
        }
        cin>>proc;
        proc=proc-1;
        if(st=="add"){
            sol=(sol | (1<<proc));
            continue;
        }
        else if(st=="remove"){
            sol=(sol & ~(1<<proc));
            continue;
        }
        else if(st=="check"){
            cout<<((sol & (1<<proc) ) ? 1:0)<<'\n';

        }
        else if(st=="toggle"){
            sol=(sol^(1<<proc));
        }
    }
    // cout<<(sol>>1)+1<<'\n';
}//256 128 64 32 16 8 4 2 1
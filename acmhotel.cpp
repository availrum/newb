#include<iostream>
using namespace std;
int main(){//10250
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int i=0; i<T; ++i){
        int H,W,N;
        cin>>H>>W>>N;
        if(((N-1)/H)+1 < 10) cout<<((N-1)%H)+1<<"0"<<((N-1)/H)+1;
        else cout<<((N-1)%H)+1<<((N-1)/H)+1;
        cout<<'\n';
    }
}
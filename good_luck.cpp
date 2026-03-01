#include<iostream>
using namespace std;
int main(){ //31713
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int tcase=0; tcase<T; ++tcase){
        int A,B;
        cin>>A>>B;
        int cnt=0;
        while(((3*A)!=B && (4*A)!=B)){
            if(3*A>B){
                ++B;
                ++cnt;
            }
            else if(4*A<B){
                ++A;
                ++cnt;
            }
            else break;
        }
        cout<<cnt<<'\n';
    }
}
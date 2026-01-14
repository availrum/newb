#include<iostream>
using namespace std;
int gcd(int a, int b){
    if(a<b) swap(a,b);
    while(a%b!=0){
        int tmp=a%b;
        a=b;
        b=tmp;
    }
    return b;
}
int main(){ //3036
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int arr[N-1],first_wheel;
    cin>>first_wheel;
    for(int i=0; i<N-1; ++i){
        cin>>arr[i];
        int tmpa=first_wheel, tmpb=arr[i];
        int divid=gcd(tmpa,tmpb);
        cout<<tmpa/divid<<'/'<<tmpb/divid<<'\n';
    }

}
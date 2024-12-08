#include<iostream>
#include<algorithm>
using namespace std;
struct in3{
    int s1;
    int s2;
    long long int summation;
};
int main(){//2473
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    long long int arr[N]={0,};
    for(int i=0; i<N; ++i) cin>>arr[i];
    sort(arr,arr+N);
    
    in3 sol[N];
    for(int i=0; i<N-2; ++i){
        int st=i+1, ed=N-1;
        long long int mini1=arr[st], mini2=arr[ed], minibase=arr[i];
        long long int sum=mini1+mini2+minibase;
        long long int val=3000000001;
        while(st<ed){
            sum=arr[st]+arr[ed]+minibase;
            if(val>abs(sum)){
                val=abs(sum);
                mini1=arr[st];
                mini2=arr[ed];
            }
            if(sum>0){
                --ed;
            }
            else if(sum<0){
                ++st;
            }
            else{
                break;
            }
        }
        sol[i].s1=mini1;
        sol[i].s2=mini2;
        sol[i].summation=val;
    }
    int solution0, solution1, solution2;
    long long int sumofsol=3000000001;
    for(int i=0; i<N-2; ++i){
        if(sumofsol>abs(sol[i].summation)){
            solution0=arr[i];
            solution1=sol[i].s1;
            solution2=sol[i].s2;
            sumofsol=abs(sol[i].summation);
        }
    }
    cout<<solution0<<' '<<solution1<<' '<<solution2<<'\n';
}
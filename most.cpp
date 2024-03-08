#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int N,k,sum,num,c,d;
    int a[N],b[N];
    int aver=0;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>k;
        a[i]=k;
        b[i]=0;
        aver+=k;
    }
    sort(a,a+N);
    // for(int i=0; i<N; i++){
    //     cout<<a[i]<<'\n';
    // }
    if(N==1) d=a[0];
    // else d=a[1];
    // else 
    cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<"?"<<endl;
    num=0;
    // d=1;
    // c==1;
    for(int i=0; i<N; i++){
        if(a[i]==a[i+1]){
            b[i]++;//빈도수 가장앞번호
            for(int j=i+2; j<N; j++){
                num=j;
                if(a[i]==a[j]){
                    b[i]++;
                    continue;
                }
                break;
            }
            i+=num-1;
            // b[i]=1;
            }
    }
    for(int i=0; i<N; i++){//판별용
        if(b[i]>sum){
            sum = b[i];
            d=a[i];
            // cout<<a[i]<<"sds"<<'\n';
            c=1;
        }
        if(b[i]==0) continue;
        if(b[i]==sum && c==1){
            d=a[i];
            c--;
        }

    }

    // cout<<'\n'<<N<<"????"<<'\n';
    // aver/=N;
    // cout<<aver<<'\n';
    // cout<<a[(N-1)/2]<<'\n';
    // cout<<d<<'\n';
    // cout<<a[N-1]-a[0]<<'\n';
    return 0;
}
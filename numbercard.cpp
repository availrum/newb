#include<iostream>
#include<algorithm>
using namespace std;
int main(){//10815
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M,x;
    cin>>N;
    int a[N+1];
    for(int i=0; i<N; i++){
        cin>>a[i];
    }
    sort(a,a+N);
    cin>>M;
    // for(int i=0; i<N; i++){
    //     cout<<a[i]<<' '<<i<<'\n';
    // }
    for(int i=0; i<M; i++){
        int tmp=(N-1)/2,temp=(N-1)/2;
        int start=0, end=N-1,mid=temp;
        cin>>x;
        for(int j=0; j<24; j++){//2^24>1000만이므로
            if(start>end) break;
            mid=(start+end)/2;
            // if(start==mid && end==mid) break;
            if(x>a[mid]) {
                start=mid+1;
            }
            else if(x<a[mid]){
                end=mid-1;
            }
            else if(x==a[mid]){
                // cout<<"1"<<'\n';
                break;
            }
            // cout<<mid<<' ';
        }
            // cout<<'\n';
        //     // if(temp<1) temp=1;

        //     if(x==a[tmp]) {
        //         break;
        //     }
        //     else if(x>a[tmp]){
        //         tmp=(tmp+temp)/2;//(tmp-temp); //100>50>75>87>93>96>98>99
        //     }
        //     else {
        //         tmp-=temp;//(tmp-temp); //100>50>25>13>7>4>2>1
        //     }
        //     temp/=2; //매번 변화값이 절반이 되도록
        //     cout<<tmp<<' ';
        // }
        // cout<<'\n';
        // cout<<a[tmp]<<'\n';
        if(x==a[mid]) cout<<"1"<<' ';//<<'\n';
        else cout<<"0"<<' ';//;<<'\n';
    }
    cout<<'\n';
}
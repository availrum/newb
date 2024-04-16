#include<iostream>
#include<cmath>
using namespace std;
struct vector4{
    int x1,x2,x3,x4;
};
int main(){//17626
    int n,tmp,cnt,low=5;
    cin>>n;
    tmp=pow(n,0.5);
    for(int i=tmp; i>0; i--){
        cnt=1;
        int j=0,k=0,l=0;
        if(n==i*i){
            cnt=(4-((!j)+(!k)+(!l)));
            // cout<<cnt<<'\n';
            // cout<<i<<' '<<j<<' '<<k<<' '<<l<<' '<<i*i+j*j+k*k+l*l<<'\n';
            if(cnt<low) low=cnt;
            // return 0;
        }
        for(int j=i; j>=0; j--){
            // cnt=2;
            if(n-i*i-j*j==0){
                cnt=(4-((!j)+(!k)+(!l)));
                // cout<<cnt<<'\n';
                // cout<<i<<' '<<j<<' '<<k<<' '<<l<<' '<<i*i+j*j+k*k+l*l<<'\n';
                if(cnt<low) low=cnt;
                // return 0;
            }
            for(int k=j; k>=0; k--){
                // cnt=3;
                if(n-i*i-j*j-k*k==0){
                    cnt=(4-((!j)+(!k)+(!l)));
                    // cout<<cnt<<'\n';
                    // cout<<i<<' '<<j<<' '<<k<<' '<<l<<' '<<i*i+j*j+k*k+l*l<<'\n';
                    if(cnt<low) low=cnt;
                    // return 0;
                }
                for(int l=k; l>=0; l--){
                    // cnt=4;
                    if(n-i*i-j*j-k*k-l*l==0){
                        cnt=(4-((!j)+(!k)+(!l)));
                        // cout<<cnt<<'\n';
                        // cout<<i<<' '<<j<<' '<<k<<' '<<l<<' '<<i*i+j*j+k*k+l*l<<'\n';
                        if(cnt<low) low=cnt;
                        // return 0;
                    }
                }
            }
        }
        
    }
    cout<<low<<'\n';
    return 0;
}

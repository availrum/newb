#include<iostream>
#include<algorithm>
#define ll long long int
using namespace std;
int main(){ //9024
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    for(int tcase=0; tcase<t; ++tcase){
        int n; 
        ll K;
        cin>>n>>K;
        ll arr[n];
        for(int i=0; i<n; ++i){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int lft=0, rgt=n-1;
        ll cnt=0;
        int dif=2147483647;
        // for(int i=0; i<n; ++i){
        //     cout<<arr[i]<<' ';
        // }
        // cout<<'\n';
        for(int i=0; i<n-1; ++i){
            if(dif > abs(K-(arr[i]+arr[n-1]))){
                dif=abs(K-(arr[i]+arr[n-1]));
                cnt=1;
            }
            else if(dif==abs(K-(arr[i]+arr[n-1]))){
                ++cnt;
            }
            int st=i+1, ed=n-2;
            while(st<=ed){
                int mid=(st+ed)/2;
                if(abs(K-(arr[i]+arr[mid]))<dif){
                    cnt=1;
                    dif=abs(K-(arr[i]+arr[mid]));

                    if(K<arr[i]+arr[mid]){
                        ed=mid-1;
                    }
                    else if(K>arr[i]+arr[mid]){
                        st=mid+1;
                    }
                    else break;
                }
                else if(abs(K-(arr[i]+arr[mid]))>dif){
                    if(K<arr[i]+arr[mid]){
                        ed=mid-1;
                    }
                    else if(K>arr[i]+arr[mid]){
                        st=mid+1;
                    }
                    else break;
                }
                else{
                    ++cnt;
                    if(K<arr[i]+arr[mid]){
                        ed=mid-1;
                    }
                    else if(K>arr[i]+arr[mid]){
                        st=mid+1;
                    }
                    else break;
                }
            }
        }
        cout<<cnt<<'\n';
    }
}
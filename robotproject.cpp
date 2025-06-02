#include<iostream>
#include<algorithm>
using namespace std;
int main(){//3649
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x;
    while(cin>>x){
        if(x==-1) break;
        x*=10000000;
        int n;
        cin>>n;
        int lego[n];
        for(int i=0; i<n; ++i){
            cin>>lego[i];
        }
        sort(lego,lego+n);

        // for(int i=0; i<n; ++i){
        //     cout<<lego[i]<<' ';
        // }
        // cout<<'\n';

        int l1=-1, l2=-1, dif=-1;
        bool flag=false;
        for(int i=0; i<n-1; ++i){
            int st=i+1, ed=n-1;
            while(st<=ed){
                int mid=(st+ed)/2;
                if(lego[i]+lego[mid]<x){
                    st=mid+1;
                }
                else if(lego[i]+lego[mid]>x){
                    ed=mid-1;
                }
                else{
                    if(lego[mid]-lego[i]>dif){
                        l1=lego[i];
                        l2=lego[mid];
                        dif=lego[mid]-lego[i];
                    }
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }
        // cout<<x<<' '<<l1<<' '<<l2<<'\n';
        if(l1!=-1){
            cout<<"yes "<<l1<<' '<<l2<<'\n';
        }
        else cout<<"danger"<<'\n';
    }
}
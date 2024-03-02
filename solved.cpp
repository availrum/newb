#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int roundd(double x){//18110번
    int t;
    double k;
    k=x-int(x);
    if(k>=0.5){
        t = int(x+1);
    }
    else {
        t = int(x);
    }
        // cout<<k<<' '<<int(x+1)<<'\n';
        return t;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,sol,start,end,tmp;
    double cal;
    map<int,int> a;
    cin>>N;
    cal=0;
    for(int i=0; i<N; i++){
        cin>>tmp;
        a[tmp]++;
    }
    start=roundd(N*0.15);
    end=N-start;

    tmp=start;
    for(int i=30; i>0; i--){
        if(tmp!=0 && a[i]>0){//최소 15퍼 제외
            a[i]-=tmp;
            tmp=0;
            if(a[i]<0){
                tmp=-a[i];
                a[i]=0;
            }
        }
    }

    tmp=start;
    for(int i=1; i<=30; i++){
        if(tmp!=0 && a[i]>0){//최소 15퍼 제외
            a[i]-=tmp;
            tmp=0;
            if(a[i]<0){
                tmp=-a[i];
                a[i]=0;
            }
        }
    }
    for(int i=1; i<=30; i++){
        cal+=i*a[i];
        // cout<<a[i]<<'\n';
    }
    if(cal==0) {
        cout<<"0"<<'\n';
        return 0;
    }
    sol=roundd(cal/(N-2*start));
    cout<<sol<<'\n';
    // cout<<cal<<'\n';
    // cout<<N-2*start<<'\n';
    return 0;
}
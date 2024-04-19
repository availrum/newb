#include<iostream>
using namespace std;
int det(int a, int b){
    return a>b ? a:b;
}
int main(){//2579
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,sum;//,msum;
    cin>>n;
    int sta[n],msum[n];
    for(int i=0; i<n; i++){
        cin>>sta[i];
    }
    msum[0]=sta[0];
    msum[1]=sta[0]+sta[1];
    msum[2]=det(sta[0]+sta[2],sta[1]+sta[2]);//012 123(~0+1+3,~0+2+3) 234 345 ...
    for(int i=3; i<n; i++){//3개씩 0123 456 789 101112 ...n/3
        msum[i]=det(msum[i-2]+sta[i],sta[i-1]+sta[i]+msum[i-3]);//직전 한칸만 건너뛴것 vs 2번째전만 건너뛴것
    }
    
    cout<<msum[n-1]<<'\n';
    return 0;
}

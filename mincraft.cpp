#include<iostream>
#include<algorithm>
using namespace std;
int main(){//18111
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M,B,tim,tmp=0,spare,min=-1,high=0;
    cin>>N>>M>>B;
    tmp=N*M;
    int hig[tmp];
    for(int i=0; i<tmp; i++){
        cin>>hig[i];
    }
    sort(hig,hig+tmp);
    for(int i=hig[tmp-1]; i>=hig[0]; i--){
        tim=0;
        spare=B;
        for(int j=0; j<tmp; j++){
            if(hig[j] > i) {
                tim+=2*(hig[j]-i);
                spare+=(hig[j]-i);
            }
            else if(hig[j]<i){
                tim+=(i-hig[j]);
                spare-=(i-hig[j]);
            }
        }
        if(spare<0) continue;
        if(min>tim || min==-1){
            min=tim;
            high=i;
        }
    }
    cout<<min<<' '<<high<<'\n';
    return 0;
}
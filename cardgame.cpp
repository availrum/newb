#include<iostream>
using namespace std;
int card[4000001];
int find(int N){
    if(card[N]==N) return N;
    return card[N]=find(card[N]);
}
void merge(int a, int b){
    int x=find(a);
    int y=find(b);
    if(x==y) return;
    if(x>y) swap(x,y);
    card[x]=y;
    
}
int main(){//16566
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, K;
    cin>>N>>M>>K;
    for(int i=0; i<=N; ++i){
        card[i]=i;
    }
    int cardcheck[N+1]={0,};
    int tmp;
    for(int i=0; i<M; ++i){
        cin>>tmp;
        cardcheck[tmp]=1;
    }
    for(int i=1; i<=N; ++i){
        if(cardcheck[i] == 1){
            card[i] = i;
        }
        else{
            merge(i,i+1);
        }
    }
    for(int i=0; i<K; ++i){
        cin>>tmp;
        int x = find(tmp+1);
        if(x<tmp+1){
            int st=tmp+1, ed=N-1;
            int mid;
            while(st<=ed){
                mid=(st+ed)/2;
                if(tmp < find(mid)){
                    x=find(mid);
                    ed=mid-1;
                }
                else{
                    st=mid+1;
                }
            }

        }
        merge(x,x+1);
        cout<<x<<'\n';
    }
}
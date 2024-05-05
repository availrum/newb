#include<iostream>
// #include<vector>
// int bet(int a, int b, int c, int d){
//     if(a<b && c<d) return a<b;
//     if(a>b && c>d) return a>b;
//     else return 0;
// }
using namespace std;
int main(){//7568
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int m[N],h[N],num[N];
    for(int i=0; i<N; i++){
        cin>>m[i]>>h[i];
        num[i]=1;
        // int tmp=1;
        // for(int j=i; j>=0; j--){//새로운 숫자가 들어갈때마다 이전번호 체크
        //     if(m[i]>m[j] && h[i]>h[j]) num[j]++;
            // if(m[i]<m[j] && h[i]<h[j]) tmp++;





            // if(m[i]>m[j]) {//몸무게가 더클때
            //     if(h[i]>h[j]) num[j]++;
            //     else if(h[i]<h[j]) {
            //         if(num[i]<num[j]) num[i]=num[j];
            //     }
            //     else tmp++;
            // }
            // else if(h[i]>h[j]){//몸무게는 작거나 같고 키가 클때
            //     // if(m[i]==m[j]) num[j]++; //몸무게가 같을때 (키가 크고)
            //     // else 
            //     num[i]=num[j]; //키는 크고 몸무게는 작을때
            // }
            // else {//몸무게와 키 둘다 작거나 같을때
            //     // if(m[i]==m[j] && h[i]==h[j]) num[i]=num[j]; //둘다 같은경우
            //     // else 
            //     tmp++; //둘다작을때
            // }
        // }
        // if(num[i]==1 && tmp!=1) num[i]=tmp;
    }
    for(int i=0; i<N; i++){
        for(int j=i; j>=0; j--) if(m[i]>m[j] && h[i]>h[j]) num[j]++;
        
        for(int j=i; j<N; j++) if(m[i]>m[j] && h[i]>h[j]) num[j]++;
        
    }
    for(int i=0; i<N; i++){
        cout<<num[i]<<' ';
    }
    cout<<'\n';
}
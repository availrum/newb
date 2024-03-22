#include<iostream>
// #include<ctime>
using namespace std;
int main (){//17103
    // int start=clock();
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test,max=1000000;
    int num =0;
    bool prim[max+1]={0,};
    cin >> test;    
    int a[test];
    prim[2]=true;
    prim[3]=true;
    prim[5]=true;
    prim[7]=true;
    for(int i=9; i<=max; i+=2){ // 
        // if(prim[i]=false){
        for(int j=3; j*j<=i; j+=2){ // 
            if(i%j==0) break;
            if((j+2)*(j+2)>i) prim[i]=true;
        }
        // }
    }

    for(int k =0; k<test; k++){//test set - Max 100
    int sol =0;
    cin >>a[k];
    if(a[k]==4){
        cout<<1<<'\n';
        continue;
    }
    for(int j=3; j<=a[k]/2; j++){
        // cout<<prim[j]<<'\n';
        if(prim[j]==true && prim[a[k]-j]==true) { //if a, a[k]-j both prime
            sol++;
            // cout<<j<<'\n';
        }
    }
    cout<<sol<< '\n' ;
        // cout<<prim[9]<< '\n' ;
    }
    // for(int k=0; k<test; k++){
    //     // cout<<a[k]<< '\n' ;
    // }
    // int fin=clock();
    // cout<<(fin-start)/CLOCKS_PER_SEC<<'\n';

    return 0;
}
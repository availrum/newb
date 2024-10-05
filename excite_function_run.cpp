#include<iostream>
using namespace std;
int main(){//9184
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a,b,c;
    int w[21][21][21];
    for(int i=0; i<21; ++i) for(int j=0; j<21; ++j) for(int k=0; k<21; ++k) w[i][j][k]=1;
    w[0][0][0]=1;
    for(int i=0; i<=20; ++i){
        for(int j=0; j<=20; ++j){
            for(int k=0; k<=20; ++k){
                if(i==0 || j==0 || k==0) w[i][j][j]=1;
                else if(i<j && j<k) w[i][j][k]=w[i][j][k-1]+w[i][j-1][k-1]-w[i][j-1][k];
                else w[i][j][k]=w[i-1][j][k]+w[i-1][j-1][k]+w[i-1][j][k-1]-w[i-1][j-1][k-1];
            }
        }
    }//111=011+001+010-000
    //0>(a-1)(b-1)(c-1) / 1>(a-1)bc / 2>a(b-1)c / 3>ab(c-1) / 4>(a-1)(b-1)c / 5>(a-1)b(c-1) / 6>a(b-1)(c-1)
    while(cin>>a>>b>>c){
        if(a==-1 && b==-1 && c==-1) break;
        int mini=min(20,min(a,min(b,c))), maxi=max(0,max(a,max(b,c)));
        if(mini<=0){
            cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<"1"<<'\n';
            continue;
        }
        else if(maxi>20){
            cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<w[20][20][20]<<'\n';
            continue;
        }
        else cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<w[a][b][c]<<'\n';
    }
}
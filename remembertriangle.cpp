#include<iostream>
#include<algorithm>
using namespace std;
int main(){//10101
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int angle[3]={0,},sum=0, cnt=0;
    for(int i=0; i<3; ++i){
        cin>>angle[i];
        sum+=angle[i];
    }
    sort(angle,angle+3);
    for(int i=1; i<3; ++i) if(angle[i]==angle[i-1]) ++cnt;
    if(sum!=180) cout<<"Error"<<'\n';
    else if(cnt==0) cout<<"Scalene"<<'\n';
    else if(cnt==1) cout<<"Isosceles"<<'\n';
    else if(cnt==2) cout<<"Equilateral"<<'\n';
}
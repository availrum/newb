#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define ll long long int
using namespace std;
int main(){ //1490
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // int N;
    // cin>>N;
    string st;
    cin>>st;
    // cout<<st<<'\n';
    int check[10]={0,};
    vector<int> component;
    for(int i=0; i<st.length(); ++i){
        if(!check[st[i]-'0'] && st[i]-'0' != 0){
            component.push_back(st[i]-'0');
            ++check[st[i]-'0'];
            // cout<<st[i]-'0'<<'\n';
        }
    }
    ll lcm=component[0];
    for(int i=1; i<component.size(); ++i){
        // cout<<component[i]<<'\n';
        int gcd=lcm;
        int tmpa=max(gcd,component[i]);
        int tmpb=min(gcd,component[i]);
        while(tmpa % tmpb != 0){
            gcd=tmpb;
            tmpb=tmpa%tmpb;
            tmpa=gcd;
        }
        lcm*=(component[i]/tmpb);
    }
    // cout<<lcm<<'\n';
    // 1부터 9까지 모두 있다고 해도 최대 2520으로 나눠지면 됨
    // 그러므로 포함된 숫자들의 최소공배수를 구하고, 그걸로 나눠떨어지는거까지 브루트포스하면 될듯

    ll sol=9223372036854775806;
    for(int i=0; i<10; ++i){
        string tmpst1=st;
        if(stol(tmpst1)%lcm==0){
            sol=stol(tmpst1);
            break;
        }

        tmpst1+=to_string(i);
        // cout<<tmpst1<<'\n';
        if(stol(tmpst1)%lcm==0){
            ll tmp=stol(tmpst1);
            sol=min(sol,tmp);
        }
        for(int j=0; j<10; ++j){
            string tmpst2=tmpst1;
            tmpst2+=to_string(j);
            if(stol(tmpst2)%lcm==0){
                ll tmp=stol(tmpst2);
                sol=min(sol,tmp);
            }
            for(int k=0; k<10; ++k){
                string tmpst3=tmpst2;
                tmpst3+=to_string(k);
                if(stol(tmpst3)%lcm==0){
                    ll tmp=stol(tmpst3);
                    sol=min(sol,tmp);
                }
                for(int l=0; l<10; ++l){
                    string tmpst4=tmpst3;
                    tmpst4+=to_string(l);
                    if(stol(tmpst4)%lcm==0){
                        ll tmp=stol(tmpst4);
                        sol=min(sol,tmp);
                    }
                    // cout<<tmpst4<<'\n';
                }
            }
        }
        
    }
    cout<<sol<<'\n';
}
#include<iostream>
using namespace std;
int main(){//2671
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string N;
    cin>>N;
    int soundlength=N.length();
    int idx=0;
    bool flag=false;
    bool aft100=false;
    // 100나옴 -> 다음 1까지 모두 생략 idx=다음1인덱스+1, aft100 = true
    while(idx<soundlength){
        if(aft100 && N[idx]=='1'){
            if(idx+2<soundlength && (N[idx+1]=='0' && N[idx+2]=='0')){
                idx+=3;
                aft100=true;
                flag=true;
                for(int i=idx; i<soundlength; ++i){
                    if(N[i]=='1'){
                        flag=false;
                        idx=i+1;
                        break;
                    }
                }
                if(flag) break;
            }
            else ++idx;
        }
        else if(idx+2<soundlength){
            if((N[idx]=='1' && N[idx+1]=='0' && N[idx+2]=='0')){
                idx+=3;
                aft100=true;
                flag=true;
                for(int i=idx; i<soundlength; ++i){
                    if(N[i]=='1'){
                        flag=false;
                        idx=i+1;
                        break;
                    }
                }
                if(flag) break;
            }
            else if(N[idx]=='0' && N[idx+1]=='1'){
                idx+=2;
                aft100=false;
            }
            else{
                flag=true;
                break;
            }
        }
        else if(idx+1<soundlength){
            if(N[idx]=='0' && N[idx+1]=='1'){
                idx+=2;
                aft100=false;
            }
            else{
                flag=true;
                break;
            }
        }
        else{
            flag=true;
            break;
        }
    }
    // cout<<'\n';
    if(flag) cout<<"NOISE"<<'\n';
    else cout<<"SUBMARINE"<<'\n';
}
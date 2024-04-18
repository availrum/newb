#include<iostream>
#include<deque>
#include<string>
using namespace std;
int main(){//5430
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test,pm,n;
    string p,tmp,tmps;
    deque<int> dq;
    cin>>test;
    for(int i=0; i<test; i++){
        cin>>p>>n;
        cin>>tmp;
        tmps="";
        for(int j=0; j<tmp.length(); ++j){
            if(isdigit(tmp[j])){
                tmps+=tmp[j];
            }
            else{
                if(tmps.length()){//없으면 에러
                    dq.push_back(stoi(tmps));//문자열로 합치고 다음 문자열 나오면 정수로 인풋
                    tmps="";
                }
            }
        }
        pm=0;
        int erm=0;
        for(int j=0; j<p.length(); j++){
            int dql=dq.size();
            if(p[j]=='R'){
                if(pm==0) pm=-1;
                else if(pm==-1) pm=0;
            }
            else if(p[j]=='D'){
                if(dq.empty()){
                    cout<<"error"<<'\n';
                    erm=1;//에러확인용
                    break;
                }
                else{
                    if(pm==0) dq.pop_front();
                    else dq.pop_back();
                }
            }
        }
        if(erm==1){//에러처리
            continue;
        }

        int dql=dq.size();//출력부
        cout<<"[";
        if(pm==0){
            for(int j=0; j<dql; j++){
                cout<<dq.front();
                dq.pop_front();
                if(j!=dql-1) cout<<",";
            }
        }
        else if(pm==-1){
            for(int j=0; j<dql; j++){
                cout<<dq.back();
                dq.pop_back();
                if(j!=dql-1) cout<<",";
            }
        }
        cout<<"]"<<'\n';
    }
    return 0;
}

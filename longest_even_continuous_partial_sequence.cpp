#include<iostream>
using namespace std;
int main(){ //22862
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,K;
    cin>>N>>K;
    int arr[N];
    for(int i=0; i<N; ++i){
        cin>>arr[i];
    }
    int lft=0, rgt=0, cnt=0, max_cnt=0, pass=K;
    while(lft<N){

        if(arr[rgt]%2==1){ // arr[rgt]가 홀수일때
            if(!pass){ // 남아있는 삭제횟수가 없다면
                if(arr[lft]%2==0){ //짝수
                    --cnt;
                    ++lft;
                }
                else{
                    ++pass;
                    ++lft;
                }
            }
            else{
                --pass;
                ++rgt;
            }
        }
        else{ // 오른쪽이 짝수라면
            ++cnt;
            ++rgt;
        }
        
        // cout<<"Left idx="<<lft<<", Right idx="<<rgt<<", remain pass="<<pass<<", total even="<<cnt<<'\n';
        max_cnt=max(max_cnt,cnt);
        if(rgt>=N) break;
    }
    cout<<max_cnt<<'\n';
}
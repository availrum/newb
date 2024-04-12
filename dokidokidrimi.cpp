#include<iostream>
#include<stack>
using namespace std;
int main(){//12789
    int N,num,fin=1,tmp=1;
    stack<int> qu;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>num;
        if(tmp!=num){//입력받은 숫자가 들어갈 순서가 아니면
            if(!qu.empty() && tmp==qu.top()){//샛길을 확인하고 샛길끝 사람이 들어갈 순서면
                // for(int j=0; j<qu.size(); j++){//샛길의 길이만큼
                while(!qu.empty()){
                    if(qu.top()==tmp){//순번확인후 처리한다
                        qu.pop(); 
                        tmp++;
                    }
                    else break;
                }
                // continue;
            }
            if(tmp==num) tmp++;
            else if(!qu.empty() && tmp!=qu.top()){//샛길에 무언가 있고, 샛길끝 사람이 들어갈 순서가 아니면
                if(!qu.empty() && fin*(qu.top()-num)<0){
                    cout<<"Sad"<<'\n';
                    return 0;
                }
                fin=qu.top()-num;
                qu.push(num);
            }
            else qu.push(num);
        }
        else tmp++;
    }
    // if(qu.size()==0) {
    //     cout<<"Nice"<<'\n';
    //     return 0;
    // }
    // cout<<qu.top()<<' '<<qu.size()<<'\n';
    // cout<<qu.size()<<'\n';
    // cout<<tmp<<'\n';
    // while(!qu.empty()){
    //     cout<<qu.top()<<'\n';
    //     qu.pop();
    // }
    //     else{
    //         cout<<"Sad"<<'\n';
    //         return 0;
    //     }
    // }
    // cout<<qu.top()<<'\n';
    // if(qu.size()==0) {
        cout<<"Nice"<<'\n';
        return 0;
    // }
    // else{
        // cout<<"Sad"<<'\n';
    // }
}
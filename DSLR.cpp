#include<iostream>
#include<queue>
using namespace std;
int main(){// 백준 9019번 DSLR
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int i=0; i<T; ++i){
        int A,B;
        queue<int> qu;
        cin>>A>>B;
        qu.push(A);
        int shortest_path[10000]={0,};
        bool visited[10000]={0,};
        string cmd[10000];
        for(int j=0; j<10000; ++j) cmd[j]="";
        visited[A]=true; // 시작숫자
        while(!qu.empty()){
            int current_value=qu.front();
            qu.pop();
            // cout<<current_value<<'\n';
            if(current_value==B) break;
            if(2*current_value<10000){ // 2*n이 10000아래인 경우 - D
                if(!visited[2*current_value] || shortest_path[2*current_value]>shortest_path[current_value]+1){ // 방문한 적 없거나 방문했던 것보다 더 빨리 올수있으면
                    qu.push(2*current_value);
                    visited[2*current_value]=true;
                    shortest_path[2*current_value]=shortest_path[current_value]+1;
                    cmd[2*current_value]=cmd[current_value]+"D";
                    if(2*current_value==B) break;
                }
            }
            else if(2*current_value>=10000){ // 2*n에 나머지 연산이 필요한 경우 - D
                if(!visited[(2*current_value)%10000] || shortest_path[(2*current_value)%10000]>shortest_path[current_value]+1) {
                    qu.push((2*current_value)%10000);
                    visited[(2*current_value)%10000]=true;
                    shortest_path[(2*current_value)%10000]=shortest_path[current_value]+1;
                    cmd[(2*current_value)%10000]=cmd[current_value]+"D";
                    if((2*current_value)%10000==B) break;
                }
            }
            if(current_value-1>=0){ // current_value-1이 0보다 큰경우 - S
                if(!visited[current_value-1] || shortest_path[current_value-1]>shortest_path[current_value]+1){
                    qu.push(current_value-1);
                    visited[current_value-1]=true;
                    shortest_path[current_value-1]=shortest_path[current_value]+1;
                    cmd[current_value-1]=cmd[current_value]+"S";
                    if(current_value-1==B) break;
                }
            }
            else if(current_value-1<0){ // current_value-1이 -가 되는경우 9999로 - S
                if(!visited[current_value+9999] || shortest_path[current_value+9999]>shortest_path[current_value]+1){
                    qu.push(current_value+9999);
                    visited[current_value+9999]=true;
                    shortest_path[current_value+9999]=shortest_path[current_value]+1;
                    cmd[current_value+9999]=cmd[current_value]+"S";
                    if(current_value+9999==B) break;
                }
            }
            if(current_value*10>=10000){ // n*10이 10000을 넘어가는 경우 - L
                int tmpL=current_value/1000;
                if(!visited[(current_value*10)%10000+tmpL] || shortest_path[(current_value*10)%10000+tmpL]>shortest_path[current_value]+1){
                    qu.push((current_value*10)%10000+tmpL);
                    visited[(current_value*10)%10000+tmpL]=true;
                    shortest_path[(current_value*10)%10000+tmpL]=shortest_path[current_value]+1;
                    cmd[(current_value*10)%10000+tmpL]=cmd[current_value]+"L";
                    if((current_value*10)%10000+tmpL==B) break;
                }
            }
            else if(current_value*10<10000){ // n*10이 10000 아래인 경우 ex)0987 - L
                if(!visited[current_value*10] || shortest_path[current_value*10]>shortest_path[current_value]+1){
                    qu.push(current_value*10);
                    visited[current_value*10]=true;
                    shortest_path[current_value*10]=shortest_path[current_value]+1;
                    cmd[current_value*10]=cmd[current_value]+"L";
                    if(current_value*10==B) break;
                }
            }
            if(current_value%10!=0){ // n을 오른쪽으로 넘기는경우 1의자리가 0이 아닐때 ex)1234->4123 - R
                int tmpR=current_value%10;
                if(!visited[current_value/10+tmpR*1000] || shortest_path[current_value/10+tmpR*1000]>shortest_path[current_value]+1){
                    qu.push(current_value/10+tmpR*1000);
                    visited[current_value/10+tmpR*1000]=true;
                    shortest_path[current_value/10+tmpR*1000]=shortest_path[current_value]+1;
                    cmd[current_value/10+tmpR*1000]=cmd[current_value]+"R";
                    if(current_value/10+tmpR*1000==B) break;
                }
            }
            else if(current_value%10==0){ // n을 오른쪽으로 넘기는경우 1의 자리가 0일때 ex)1230->2301 - R
                if(!visited[current_value/10] || shortest_path[current_value/10]>shortest_path[current_value]+1){
                    qu.push(current_value/10);
                    visited[current_value/10]=true;
                    shortest_path[current_value/10]=shortest_path[current_value]+1;
                    cmd[current_value/10]=cmd[current_value]+"R";
                    if(current_value/10==B) break;
                }
            }
            
        }
        // cout<<shortest_path[B]<<'\n';
        cout<<cmd[B]<<'\n';
    }
}
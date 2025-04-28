#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
long long int heap[100001];
vector<long long int> sol; // 답을 저장할 배열 
unordered_map<long long int,int> negative_count; // 음수 개수 카운팅
int heap_idx=0;
void heap_push(int n){
    ++heap_idx;// 새로운걸 넣으니 전체 개수 index+1;
    int push_idx=heap_idx;
    heap[push_idx]=n; // 배열의 새 인덱스에 push한 숫자를 넣는다
    if(n<0) ++negative_count[abs(n)];
    while(push_idx != 1 && abs(n) < abs(heap[push_idx/2])){ // 최상위노드까지, 새 값이 배열의 바로위 부모노드보다 작은경우만 
        swap(heap[push_idx],heap[push_idx/2]);
        push_idx/=2; // 이진트리의 부모는 해당 자식노드의 인덱스/2
    }
}
void heap_pop(){
    int pop_idx=1;
    swap(heap[pop_idx],heap[heap_idx]); // 지우려는 인덱스와 가장 마지막 값 교체
    // heap[heap_idx]=0;
    --heap_idx;
    while(heap_idx >= pop_idx*2){
        if(heap_idx==2){
            if(abs(heap[pop_idx])<abs(heap[heap_idx])) break;
            else swap(heap[pop_idx],heap[heap_idx]);
            break;
        }
        if(pop_idx*2+1 <= heap_idx){//앞뒤노드 둘다존재
            if(abs(heap[pop_idx*2])<=abs(heap[pop_idx*2+1])){//앞자식이 뒷자식보다 작을때
                if(abs(heap[pop_idx*2])<abs(heap[pop_idx])){//자식노드 중 앞이 부모노드보다 작으면
                    swap(heap[pop_idx*2],heap[pop_idx]);
                    // cout<<heap_idx<<' '<<heap[pop_idx*2]<<' '<<heap[pop_idx*2+1]<<'\n'<<'\n';
                    pop_idx*=2;
                }
                else break;
            }
            else if(abs(heap[pop_idx*2])>abs(heap[pop_idx*2+1])){//뒷자식이 앞자식보다 작을때
                if(abs(heap[pop_idx*2+1])<abs(heap[pop_idx])){//자식노드 중 뒤가 부모노드보다 작으면
                    swap(heap[pop_idx*2+1],heap[pop_idx]);
                    pop_idx=pop_idx*2+1;
                }
                else break;
            }
        }
        else if(pop_idx *2 <= heap_idx){ //앞쪽 노드만 존재
            if(abs(heap[pop_idx*2])<abs(heap[pop_idx])){//자식노드 중 앞이 부모노드보다 작으면
                swap(heap[pop_idx*2],heap[pop_idx]);
                // cout<<heap_idx<<' '<<heap[pop_idx*2]<<' '<<heap[pop_idx*2+1]<<'\n'<<'\n';
                pop_idx*=2;
            }
            else break; //둘다 상위노드보다 크다
            
        }
    }
}
int main(){// 백준 11286번 절댓값 힙 (힙 직접구현)
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    long long int num;
    cin>>N;
    heap_idx=0;
    for(int i=0; i<N; ++i){
        cin>>num;
        if(num==0){ // 힙에서 제거하는 연산
            if(heap_idx<1) {
                sol.push_back(0);
                continue;
            }
            else{
                if(negative_count[abs(heap[1])]>0){ // 만약 해당 절대값에 남은 음수 개수가 있다면 음수로 
                    sol.push_back(-abs(heap[1]));
                    --negative_count[abs(heap[1])]; // 음수 개수 -1
                }
                else sol.push_back(abs(heap[1]));
                heap_pop(); //힙에서 빼기
            }
        }
        else{ // 힙에 추가하는 연산산
            if(heap[1]==0){
                ++heap_idx;
                heap[1]=num;
                if(num<0) ++negative_count[abs(num)];
                continue;
            }
            heap_push(num);//i=0> 1-1
        }
        // cout<<heap_idx<<'\n';
    }
    for(int i=0; i<sol.size(); ++i){
        cout<<sol[i]<<'\n'; 
    }
    return 0;
}
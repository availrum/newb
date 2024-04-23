#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
long long int hp[100001];
vector<long long int> sol;
map<long long int,int> nsig;
int hpidx;
void hp_push(int n){//hp[
    hpidx++;//새로운걸 넣으니 index+1;
    int pushidx=hpidx;
    if(n<0) nsig[abs(n)]++;
    hp[pushidx]=n; //배열의 새 인덱스에 push한 숫자를 넣는다
    while(pushidx != 1 && abs(n) <= abs(hp[pushidx/2])){ //최상위노드까지, 새 값이 배열의 바로위 부모노드보다 작은경우만 
        if (abs(n)==abs(hp[pushidx/2]) && n<hp[pushidx/2]){
            swap(hp[pushidx],hp[pushidx/2]);
            pushidx/=2;
        }
        else if(abs(n)<abs(hp[pushidx/2])){
            swap(hp[pushidx],hp[pushidx/2]);
            pushidx/=2;
        }
        else break;
    }
}
void hp_remove(){
    int remidx=1;//,tmp,nidx;
    // int befmax=hp[remidx];
    // hp[remidx]=hp[hpidx];//hp[1]
    swap(hp[remidx],hp[hpidx]);
    // hp[hpidx]=0;
    hpidx--;
    while(hpidx >= remidx*2){
        if(hpidx==2){
            if(abs(hp[remidx])==abs(hp[hpidx])){
                if(hp[remidx]>hp[hpidx]) swap(hp[remidx],hp[hpidx]);
                else break;
            }
            else if(abs(hp[remidx])<abs(hp[hpidx])) break;
            else swap(hp[remidx],hp[hpidx]);
            // break;
        }
        if(remidx*2+1 <= hpidx){//앞뒤노드 둘다존재
            if(abs(hp[remidx*2])<=abs(hp[remidx*2+1])){//앞자식이 뒷자식보다 작을때
                if(abs(hp[remidx*2])==abs(hp[remidx]) && hp[remidx*2]<hp[remidx]){
                    swap(hp[remidx*2],hp[remidx]);
                    remidx*=2;
                }
                else if(abs(hp[remidx*2])<abs(hp[remidx])){//자식노드 중 앞이 부모노드보다 작으면
                    swap(hp[remidx*2],hp[remidx]);
                    // cout<<hpidx<<' '<<hp[remidx*2]<<' '<<hp[remidx*2+1]<<'\n'<<'\n';
                    remidx*=2;
                }
                else break;
            }
            else if(abs(hp[remidx*2])>abs(hp[remidx*2+1])){//뒷자식이 앞자식보다 작을때
                if(abs(hp[remidx*2+1])==abs(hp[remidx]) && hp[remidx*2+1]<hp[remidx]){
                    swap(hp[remidx*2+1],hp[remidx]);
                    remidx=remidx*2+1;
                }
                else if(abs(hp[remidx*2+1])<abs(hp[remidx])){//자식노드 중 뒤가 부모노드보다 작으면
                    swap(hp[remidx*2+1],hp[remidx]);
                    // swap();
                    remidx=remidx*2+1;
                }
                else break;
                // }
            }
        }
        else if(remidx *2 <= hpidx){ //앞쪽 노드만 존재
            if(abs(hp[remidx*2])==abs(hp[remidx]) && hp[remidx*2]<hp[remidx]){
                swap(hp[remidx*2],hp[remidx]);
                remidx*=2;
            }
            else if(abs(hp[remidx*2])<abs(hp[remidx])){//자식노드 중 앞이 부모노드보다 작으면
                swap(hp[remidx*2],hp[remidx]);
                // cout<<hpidx<<' '<<hp[remidx*2]<<' '<<hp[remidx*2+1]<<'\n'<<'\n';
                remidx*=2;
            }
            // else if(hp[remidx*2+1]<hp[remidx]){ //자식노드 중 뒤가 부모노드보다 작으면
            //     swap(hp[remidx*2+1],hp[remidx]);
            //     remidx=remidx*2+1;
            // }
            else break;
            // }; //둘다 상위노드보다 크다
            
        }
        else break;
    }
    // cout<<hp[1]<<'\n';
}
int main(){//11286
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    long long int num;
    cin>>N;
    hpidx=0;
    for(int i=0; i<N; i++){
        cin>>num;
        if(num==0){
            if(hpidx<1) {
                // cout<<"0"<<'\n';
                sol.push_back(0);
                continue;
            }
            else{
                // cout<<hp[1]<<'\n';
                if(nsig[abs(hp[1])]>0){
                    sol.push_back(-1*abs(hp[1]));
                    nsig[abs(hp[1])]--;
                }
                else sol.push_back(abs(hp[1]));
                hp_remove();
                // hpidx--;
            }
        }
        else{
            if(hp[1]==0){
                hpidx++;
                hp[1]=num;
                if(num<0) nsig[abs(num)]++;
                // hpidx++;
                continue;
            }
            hp_push(num);//i=0> 1-1
        }
        // cout<<hpidx<<'\n';
    }
    // cout<<'\n';
    // for(int i=0; i<10; i++){
    //     cout<<hp[i]<<'\n';
    // }
    for(int i=0; i<sol.size(); i++){
        cout<<sol[i]<<'\n';
    }
    // cout<<hp[1]<<' '<<hp[2]<<'\n';
    // swap(hp[1],hp[2]);
    // cout<<hp[1]<<' '<<hp[2]<<'\n';
    
    return 0;
}

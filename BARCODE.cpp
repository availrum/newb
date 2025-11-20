#include<iostream>
#include<vector>
using namespace std;
vector<string> vec;
int N;
void rec(string st, vector<int> arr, int idx){
    int cnt=1;
    if(idx==N){
        for(int i=1; i<idx; ++i){
            if(arr[i]==arr[i-1]) ++cnt;
            else cnt=1;
            if(cnt>2) return;
        }
        // for(int i=0; i<arr.size(); ++i) cout<<arr[i]<<' ';
        // cout<<'\n';
        // cout<<st<<'\n';
        vec.push_back(st);
        return;
    }

    for(int i=1; i<=idx; ++i){
        if(arr[i]==arr[i-1]) ++cnt;
        else cnt=1;
        if(cnt>2) return;
    }

    for(int i=idx; i<N; ++i){
        if(arr[i]==1){
            if(i<N-1){
                if(arr[i]==arr[i+1]){
                    st+='1';
                    ++i;
                }
                else if(arr[i+1]==-1){
                    st+='1';
                    arr[i+1]=arr[i];
                    rec(st,arr,i+2);
                    st.pop_back();
                    st+='0';
                    arr[i+1]=1-arr[i];
                    rec(st,arr,i+1);
                    st.pop_back();
                    return;
                }
                else st+='0';
            }
            else st+='0';
        }
        else if(arr[i]==0){
            if(i<N-1){
                if(arr[i]==arr[i+1]){
                    st+='1';
                    ++i;
                }
                else if(arr[i+1]==-1){
                    st+='1';
                    arr[i+1]=arr[i];
                    rec(st,arr,i+2);
                    st.pop_back();
                    st+='0';
                    arr[i+1]=1-arr[i];
                    rec(st,arr,i+1);
                    st.pop_back();
                    return;
                }
                else st+='0';
            }
            else st+='0';
        }
        else{
            arr[i]=1;
            rec(st,arr,i);
            arr[i]=0;
            rec(st,arr,i);
            return;
        }
    }
    rec(st,arr,N);
}
int main(){ //3283
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    vector<int> code(N,-1);
    // 1??1 1??0 1?1 1?0
    //최소한 3칸마다 2칸은 알아야 판별가능 >> 길이 N에서 ?개수 1/3이하
    for(int i=0; i<5; ++i){
        string tmp;
        cin>>tmp;
        for(int j=0; j<N; ++j){
            if(tmp[j]==0 || tmp[j]==1) continue;
            else if(tmp[j]=='.') code[j]=0;
            else if(tmp[j]=='X') code[j]=1;
        }
    }
    // for(int i=0; i<N; ++i) cout<<code[i]<<'\n';
    string st="";
    rec(st,code,0);
    // cout<<vec.size()<<'\n';
    if(vec.size()==1) cout<<vec[0]<<'\n';
    else cout<<"UNDETERMINABLE\n";
    // for(int i=0; i<vec.size(); ++i) cout<<vec[i]<<'\n';
}
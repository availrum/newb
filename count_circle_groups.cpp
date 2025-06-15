#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
struct pos{
    int x;
    int y;
    int r;
};
int find(int n, vector<int>& arr){
    if(arr[n]==n) return n;
    return arr[n]=find(arr[n],arr);
}
void merge(int a, int b, vector<int>& arr){
    int x=find(a,arr);
    int y=find(b,arr);
    if(x==y) return;
    if(x>y) swap(x,y);
    arr[x]=y;
}
int main(){//10216
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int tcase=0; tcase<T; ++tcase){
        int N;
        cin>>N;
        vector<int> arr;
        for(int i=0; i<=N; ++i){
            arr.push_back(i);
        }
        pos group[N];
        for(int i=0; i<N; ++i){
            cin>>group[i].x>>group[i].y>>group[i].r;
        }
        for(int i=0; i<N; ++i){
            for(int j=i; j<N; ++j){
                if((group[i].x-group[j].x)*(group[i].x-group[j].x)
                   +(group[i].y-group[j].y)*(group[i].y-group[j].y) 
                   <= (group[i].r+group[j].r)*(group[i].r+group[j].r)
                   ){
                        merge(i, j, arr);
                   }
            }
        }
        unordered_map<int,int> check;
        int cnt=0;
        for(int i=0; i<N; ++i){
            int curunion=find(i, arr);
            if(!check[curunion]){
                ++check[curunion];
                ++cnt;
            }
        }
        cout<<cnt<<'\n';
    }
}
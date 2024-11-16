#include<iostream>
#include<stack>
using namespace std;
int main(){//9466
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int iter=0; iter<T; ++iter){
        int n;
        cin>>n;
        int choose[n+1];
        int graph[n+1];

        int visited[n+1];
        for(int i=1; i<=n; ++i){
            cin>>choose[i];
            visited[i]=0;
        }
        stack<int> st;
        int sol=n;
        for(int i=1; i<=n; ++i){
            if(visited[i]==2) continue;
            visited[i]=1;
            st.push(i);

            stack<int> st_path;
            st_path.push(i);

            while(!st.empty()){
                int x=st.top();
                st.pop();
                int y=choose[x];
                // cout<<x<<' '<<y<<'\n';
                if(x==y){
                    --sol;
                    visited[x]=2;
                    // cout<<x<<" case:1\n";
                    while(!st_path.empty()){
                        visited[st_path.top()]=2;
                        st_path.pop();
                    }
                    break;
                }
                if(visited[y]==2){
                //사이클이 없거나 이미 체크한 사이클
                    while(!st_path.empty()){
                        visited[st_path.top()]=2;
                        st_path.pop();
                        // cout<<rm<<" case:2\n";
                    }
                    break;
                }
                else if(visited[y]==1){
                //경로가 하나이므로 visited가 1이라면 무조건 사이클
                    int cnt=0;
                    while(!st_path.empty()){
                        int rm=st_path.top();
                        ++cnt;
                        if(y==rm){
                            sol-=cnt;
                        }
                        // cout<<rm<<" case:3\n";
                        st_path.pop();
                        visited[rm]=2;
                    }
                    break;
                }
                visited[y]=1;
                st.push(y);
                st_path.push(y);
            }
        }
        cout<<sol<<'\n';
    }
    //dfs의 마지막이 소속된 P또는 O모양이 된것/
    //다른 부분에서 시작하지 않게 visited 면 끝
    //스택에 시작지점부터의 거리를 같이 넘기며 카운팅
    //끝부분거리-도달지점 거리
}
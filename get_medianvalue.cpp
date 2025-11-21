#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){ //2696
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int tcase=0; tcase<T; ++tcase){
        int M;
        cin>>M;
        vector<int> sol;
        priority_queue<int> qu1;
        priority_queue<int, vector<int>, greater<int>> qu2;
        for(int i=0; i<M; ++i){
            int t;
            cin>>t;
            if(qu1.empty()) qu1.push(t);
            else if(qu2.empty()){
                if(qu1.top()>t){
                    qu2.push(qu1.top());
                    qu1.pop();
                    qu1.push(t);
                }
                else qu2.push(t);
            }
            else{
                if(t<=qu1.top()){
                    qu1.push(t);
                }
                else{
                    qu2.push(t);
                }
                while(!(qu1.empty() || qu2.empty()) && qu1.top()>qu2.top()){
                    qu2.push(qu1.top());
                    qu1.pop();
                }
                while(qu1.size()<qu2.size()){
                    qu1.push(qu2.top());
                    qu2.pop();
                }
                while(qu1.size()-qu2.size()>1){
                    qu2.push(qu1.top());
                    qu1.pop();
                }
            }
            // cout<<qu1.size()<<' '<<qu2.size()<<'\n';
            if(i%2==0) sol.push_back(qu1.top());
            // qu.push(t);
            // for(int j=0; j<qu.size(); ++j){
            //     cout<<*(&qu.top()+j)<<' ';
            //     if(j==qu.size()-1) cout<<'\n';
            // }
            // int idx=*(&qu.top());
            // if(i%2==0){
            //     cout<<qu.top();
            // }
            // cout<<idx<<'\n';
        }
        cout<<sol.size()<<'\n';
        for(int i=0; i<sol.size(); ++i){
            cout<<sol[i];
            if(i!=sol.size()-1) cout<<' ';
            else cout<<'\n';
        }
    }
}
#include<iostream>
#include<deque>
#include<vector>
using namespace std;
int main(){ //1406
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    cin>>str;
    int N=str.length(), M, cur=N;
    cin>>M;
    deque<char> de;
    for(int i=0; i<N; ++i){
        de.push_back(str[i]);
    }
    for(int i=0; i<M; ++i){
        char c;
        cin>>c;
        if(c=='L'){
            if(cur>0){
                --cur;
                de.push_front(de.back());
                de.pop_back();
            }
        }
        else if(c=='D'){
            if(cur<N){
                ++cur;
                de.push_back(de.front());
                de.pop_front();
            }
        }
        else if(c=='B'){
            if(cur>0){
                --cur;
                de.pop_back();
                --N;
            }
        }
        else if(c=='P'){
            char d;
            cin>>d;
            ++cur;
            de.push_back(d);
            ++N;
        }
    }
    if(cur >= (N/2)){
        while(cur<N){
            ++cur;
            de.push_back(de.front());
            de.pop_front();
        }
    }
    else{
        while(cur>0){
            --cur;
            de.push_front(de.back());
            de.pop_back();
        }
    }
    while(!de.empty()){
        cout<<de.front();
        de.pop_front();
    }
    cout<<'\n';
}
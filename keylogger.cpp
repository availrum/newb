#include<iostream>
#include<deque>
using namespace std;
int main(){ //5397
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int tcase=0; tcase<T; ++tcase){
        string st;
        cin>>st;
        deque<char> de;
        int idx=0;
        // for(int i=0; i<st.length(); ++i) de.push_back(st[i]);
        for(int i=0; i<st.length(); ++i){
            if(st[i]=='<'){
                if(idx==0) continue;
                --idx;
                de.push_front(de.back());
                de.pop_back();
            }
            else if(st[i]=='>'){
                if(idx==de.size()) continue;
                else{
                    ++idx;
                    de.push_back(de.front());
                    de.pop_front();
                }
            }
            else if(st[i]=='-'){
                if(idx==0) continue;
                else{
                    --idx;
                    de.pop_back();
                }
            }
            else{
                ++idx;
                de.push_back(st[i]);
            }
        }
        for(idx; idx>0; --idx){
            de.push_front(de.back());
            de.pop_back();
        }
        while(!de.empty()){
            cout<<de.front();
            de.pop_front();
        }
        cout<<'\n';
    }
} 
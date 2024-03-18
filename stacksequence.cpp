#include<iostream>
#include<stack>
using namespace std;
int main(){//1874
    int N;
    int max=0;
    stack<int> st,no;
    cin>>N;
    int a[N];
    for(int i=0; i<N; i++){
        cin>>a[i];
        if(max<a[i]){
            for(int j=max+1; j<=a[i]; j++){
                no.push(j);
                max=a[i];
                if(j==a[i]) no.pop();
            }
        }
        else if(max>a[i]){
            if(a[i]>a[i-1] || no.empty()==1){
                cout<<"NO"<<'\n';
                return 0;
            }
            for(int j=max; j>=a[i]; j--){
                if(no.top()==a[i]){
                    // cout<<no.top()<<'\n';
                    no.pop();
                    break;
                }
                // if(no.empty()==1) continue;
                if(no.empty()==0) {
                    no.pop();
                    // cout<<no.top()<<'\n';
                }
                    // cout<<no.top()<<'\n';
                if(no.top()<a[i] || no.empty()==1){
                    cout<<"NO"<<'\n';
                    return 0;
                }
            }
        }
    }
    max=0;
    for(int i=0; i<N; i++){
        if(max<a[i]){
            for(int j=max+1; j<=a[i]; j++){
                st.push(j);
                cout<<"+"<<'\n';
                if(j==a[i]){
                    cout<<"-"<<'\n';
                    st.pop();
                }
            }
            max=a[i];
        }
        else{
            for(int j=max; j>=a[i]; j--){
                if(st.top()==a[i]){
                    cout<<"-"<<'\n';
                    st.pop();
                    break;
                }
                cout<<"-"<<'\n';
                st.pop();
            }

            // cout<<"-"<<'\n';
            // st.pop();
        }
    }
    return 0;
}
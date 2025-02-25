#include<iostream>
#include<unordered_map>
using namespace std;
int main(){//12891
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,P;
    cin>>N>>P;
    string st;
    cin>>st;
    char arr[4]={'A','C','G','T'};
    int num;
    unordered_map<char, int> number, check;
    for(int i=0; i<4; ++i){
        cin>>num;
        number[arr[i]]=num;
    }
    int cnt=0;
    int lidx=0, ridx=0;
    for(ridx=0; ridx<P; ++ridx){
        ++check[st[ridx]];
    }
    // cout<<ridx<<'\n';
    ridx=P-1;
    while(ridx<st.length()){
        if(number['A'] <= check['A'] 
            && number['C'] <= check['C']
            && number['G'] <= check['G'] 
            && number['T'] <= check['T']){
                ++cnt;
        }
                // cout<<lidx<<' '<<ridx<<'\n';
                // cout<<"count_num "<<number['A']<<' '<<number['C']<<' '<<number['G']<<' '<<number['T']<<'\n';
                // cout<<"count_check "<<check['A']<<' '<<check['C']<<' '<<check['G']<<' '<<check['T']<<'\n';

        ++ridx;
        if(ridx<st.length()){
            ++check[st[ridx]];
        }
        --check[st[lidx]];
        ++lidx;
    }
    cout<<cnt<<'\n';
}
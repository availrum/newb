// #include<iostream>
// #include<algorithm>
// using namespace std;
// int P[3], Y[3];
// string S[3];
// int main(){//28114
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     for(int i=0; i<3; ++i){
//         cin>>P[i]>>Y[i]>>S[i];
//         Y[i]%=100;
//     }
//     sort(Y,Y+3);
//     string st1="", st2="";
//     for(int i=0; i<3; ++i){
//         st1+=to_string(Y[i]);
//         // cout<<Y[i]<<'\n';
//     }
//     if(P[0]>P[2]){
//         swap(P[0],P[2]);
//         swap(S[0],S[2]);
//         if(P[0]>P[1]){
//             swap(P[0],P[1]);
//             swap(S[0],S[1]);
//         }
//         else if(P[1]>P[2]){
//             swap(P[1],P[2]);
//             swap(S[1],S[2]);
//         }
//     }
//     else if(P[0]>P[1]){
//         swap(P[0],P[1]);
//         swap(S[0],S[1]);
//     }
//     else if(P[1]>P[2]){
//         swap(P[1],P[2]);
//         swap(S[1],S[2]);
//     }
//     for(int i=2; i>=0; --i){
//         st2+=S[i][0];
//     }
//     cout<<st1<<'\n';
//     cout<<st2<<'\n';
// }
#include<iostream>
#include<algorithm>
using namespace std;
int Y[3];
pair<int, string> numname[3];
int main(){//28114
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0; i<3; ++i){
        cin>>numname[i].first>>Y[i]>>numname[i].second;
        Y[i]%=100;
    }
    sort(Y,Y+3);
    sort(numname,numname+3);
    string st1="", st2="";
    for(int i=0; i<3; ++i){
        st1+=to_string(Y[i]);
    }
    for(int i=2; i>=0; --i){
        st2+=numname[i].second[0];
    }
    cout<<st1<<'\n';
    cout<<st2<<'\n';
}
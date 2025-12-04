#include<iostream>
#include<algorithm>
using namespace std;
struct score{
    int kor;
    int eng;
    int math;
    string student_name;
    bool operator< (const score& other) const{
        if(kor!=other.kor) return kor>other.kor;
        else if(eng!=other.eng) return eng<other.eng;
        else if(math!=other.math) return math>other.math;
        else return student_name<other.student_name;
    }
};
int main(){ //10825
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,t;
    cin>>N;
    score st[N];
    for(int i=0; i<N; ++i){
        cin>>st[i].student_name>>st[i].kor>>st[i].eng>>st[i].math;
    }
    sort(st,st+N);
    for(int i=0; i<N; ++i){
        cout<<st[i].student_name<<'\n';
    }
}
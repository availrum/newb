#include<iostream>
#include<algorithm>
using namespace std;
struct birthday{
    string name;
    int year;
    int month;
    int day;
    bool operator< (const birthday other) const{
        if(year!=other.year) return year<other.year;
        else if(month!=other.month) return month<other.month;
        else return day<other.day;
    }
};
int main(){ //5635
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    birthday student[n];
    for(int i=0; i<n; ++i){
        cin>>student[i].name>>student[i].day>>student[i].month>>student[i].year;
    }
    sort(student,student+n);
    cout<<student[n-1].name<<'\n';
    cout<<student[0].name<<'\n';
}
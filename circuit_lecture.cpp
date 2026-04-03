#include<iostream>
#include<queue>
using namespace std;
// struct type1{
//     int day;
//     int pay;
//     bool operator< (const type1& other) const{
//         if(day!=other.day) return day>other.day;
//         return pay>other.pay;
//     }
// };
struct type2{
    int day;
    int pay;
    bool operator< (const type2& other) const{
        if(pay!=other.pay) return pay>other.pay;
        return day<other.day;
    }
};
int main(){ //2109
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> qu;
    for(int i=0; i<n; ++i){
        pair<int,int> tmp;
        cin>>tmp.second>>tmp.first;
        qu.push(tmp);
    }
    priority_queue<type2> schedule;
    // cout<<'\n';
    while(!qu.empty()){
        type2 tmp;
        tmp.day=qu.top().first;
        tmp.pay=qu.top().second;
        qu.pop();

        schedule.push(tmp);
        if(tmp.day<schedule.size()) schedule.pop();
        // cout<<tmp.pay<<' '<<tmp.day<<'\n';
    }
    // cout<<'\n';
    int money=0;
    while(!schedule.empty()){
        // cout<<schedule.top().pay<<' '<<schedule.top().day<<'\n';
        money+=schedule.top().pay;
        schedule.pop();
    }
    cout<<money<<'\n';
}
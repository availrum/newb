#include<iostream>
using namespace std;
int main(){ //17211
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, feel;
    cin>>N>>feel;
    double gtog, gtob, btog, btob;
    cin>>gtog>>gtob>>btog>>btob;
    double good, bad;
    if(!feel){
        good=gtog;
        bad=gtob;
    }
    else{
        good=btog;
        bad=btob;
    }
    double total_good=good, total_bad=bad;
    for(int i=1; i<N; ++i){
        total_good=good*gtog;
        total_good+=bad*btog;
        total_bad=good*gtob;
        total_bad+=bad*btob;

        good=total_good;
        bad=total_bad;
    }
    cout.precision(0);
    cout<<fixed;
    cout<<total_good*1000<<'\n';
    cout<<total_bad*1000<<'\n';
}
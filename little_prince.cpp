#include<iostream>
using namespace std;
int dist(int x1, int y1, int x2, int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int main(){ //1004
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int tcase=0; tcase<T; ++tcase){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        // 진입-이탈 조건에 해당하는 경우는
        // 원의 중심+반지름에 두 중심점중 한개만 존재하는 경우이다
        int n;
        cin>>n;
        int cnt=0;
        for(int i=0; i<n; ++i){
            int cx,cy,r;
            cin>>cx>>cy>>r;
            int cur_dist1=dist(cx,cy,x1,y1);
            int cur_dist2=dist(cx,cy,x2,y2);

            if(cur_dist1<r*r && cur_dist2>r*r) ++cnt;
            else if(cur_dist1>r*r && cur_dist2<r*r) ++cnt;
        }
        cout<<cnt<<'\n';
    }
}
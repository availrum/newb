#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){//1931
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,st,ed,max=1,cnt=1;
    cin>>N;
    int arr[N+1]={0,}, val[N+1]={0,};
    unordered_map<int,int> value_check;
    pair<int,int> pai;
    vector<pair<int,int>> vec;
    vec.push_back({0,0});//맨 앞을 1로 만들기 위함
    for(int i=0; i<N; ++i){
        cin>>pai.first>>pai.second;
        vec.push_back(pai);
    }
    sort(vec.begin(),vec.end());
    // cout<<'\n';
    // for(int i=0; i<vec.size(); i++) cout<<vec[i].first<<' '<<vec[i].second<<'\n';
    // cout<<'\n';
    value_check[1]=vec[1].second; //첫값의 종료시간
    arr[1]=1;//맨앞데이터의 인덱스:1
    for(int i=2; i<vec.size(); ++i){//2번째부터 시작
        if(value_check[cnt]<=vec[i].first){ //현재 저장된 최대와 비교해서 추가가능하면
            cnt++;
            value_check[cnt]=vec[i].second;
            arr[cnt]=arr[cnt-1]+1; 
            continue;
        }
        int flag=0,mid;
        st=0, ed=cnt; 
//value=값 | arr=순서 | cnt=현재 입력된 최대순서 | first=시작시간 | second=종료시간
        while(st<=ed){
            mid=(st+ed)/2;
            if(value_check[mid]==vec[i].first){
                flag=1;
                break;
            }
            if(value_check[mid]>vec[i].first) ed=mid-1;
            else if(value_check[mid]<vec[i].first) st=mid+1;
        }
        if(flag==1) continue;
        else if(value_check[mid]<vec[i].first){
            if(value_check[mid+1]>=vec[i].second) value_check[mid+1]=vec[i].second;
        }
        else if(value_check[mid]>=vec[i].second) value_check[mid]=vec[i].second;
        // else if(value_check[mid-1]<value_check[mid] && value_check[mid]<value_check[mid+1]);
        // value_check[mid]=vec[i].first;
        // arr[i]=;
    }

    for(int i=0; i<=N; ++i) if(max<arr[i]) max=arr[i]; //정답판별부분
    cout<<max<<'\n';
}
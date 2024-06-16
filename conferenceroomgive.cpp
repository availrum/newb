#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// struct Vector3D{
//     vector<vector<int>> x;
//     int z;
// };
// bool cmp(Vector3D &vec1,Vector3D &vec2){
bool cmp(vector<int> vec1, vector<int> vec2){
    return (vec1.at(0)) > (vec2.at(0));
}
int main(){//
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,st,ed;
    cin>>N;
    int arr[N];
    // Vector3D vec;
    vector<vector<int>> vec;
    for(int i=0; i<N; i++){
        cin>>st>>ed;
        vec.at(0).push_back(st);
        vec.at(1).push_back(ed);
    }
    sort(vec.begin(),vec.end(),cmp);
    for(int i=0; i<vec.size(); i++) cout<<vec[0][i]<<'\n';
}
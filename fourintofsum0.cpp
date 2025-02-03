#include<iostream>
// #include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;
int main(){//7453
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int A[n],B[n],C[n],D[n];
    for(int i=0; i<n; ++i){
        cin>>A[i]>>B[i]>>C[i]>>D[i];
    }
    // unordered_map<int,int> check;
    vector<int> vec;

    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            int sum=A[i]+B[j];
            // ++check[sum];
            vec.push_back(sum);
        }
    }
    sort(vec.begin(),vec.end());
    long long int cnt=0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            int sum=-(C[i]+D[j]);
            // if(check[-sum]) cnt+=check[-sum];
            int st=0, ed=vec.size();
            int mid;
            while(st<ed){
                mid=(st+ed)/2;
                if(vec[mid]>=sum){
                    ed=mid;
                }
                else if(vec[mid]<=sum){
                    st=mid+1;
                }
            }
            int lc=st;
            st=0, ed=vec.size();
            while(st<ed){
                mid=(st+ed)/2;
                if(vec[mid]>sum){
                    ed=mid;
                }
                else{
                    st=mid+1;
                }
            }
            int uc=st;
            cnt+=(uc-lc);
        }
    }
    cout<<cnt<<'\n';
}
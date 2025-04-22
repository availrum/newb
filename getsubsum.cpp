#include<iostream>
#include<vector>
using namespace std;
#define ll long long int
class segment_tree{
    private:
        vector<ll> tree;
        ll n;
        void buildtree(vector<ll>& data, ll node, ll start, ll end){
            if(start==end){
                tree[node]=data[start];
            }
            else{
                ll mid=(start+end)/2;
                ll leftchild=2*node+1;
                ll rightchild=2*node+2;
                buildtree(data,leftchild,start,mid);
                buildtree(data,rightchild,mid+1,end);
                tree[node]=tree[leftchild]+tree[rightchild];
            }
        }
        ll query(ll node, ll start, ll end, ll lft, ll rgt){
            if(start>rgt || end<lft){
                return 0;
            }
            else if(start>=lft && end<=rgt){
                return tree[node];
            }
            ll mid=(start+end)/2;
            ll leftchild=2*node+1;
            ll rightchild=2*node+2;
            ll leftsum=query(leftchild,start,mid,lft,rgt);
            ll rightsum=query(rightchild,mid+1,end,lft,rgt);
            return leftsum+rightsum;
        }
        void update(ll node, ll start, ll end, ll idx, ll value){
            if(start==end){
                tree[node]=value;
            }
            else{
                ll mid=(start+end)/2;
                ll leftchild=2*node+1;
                ll rightchild=2*node+2;
                if(start<=idx && idx<=mid){
                    update(leftchild,start,mid,idx,value);
                }
                else{
                    update(rightchild,mid+1,end,idx,value);
                }
                tree[node]=tree[leftchild]+tree[rightchild];
            }
        }
    public:
        segment_tree(vector<ll>& data){
            n=data.size();
            tree.resize(4*n,0);
            buildtree(data,0,0,n-1);
        }
        ll query(ll lft, ll rgt){
            return query(0,0,n-1,lft,rgt);
        }
        void update(ll idx, ll value){
            update(0,0,n-1,idx,value);
        }
};
int main(){//2042
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N,M,K,tmp;
    cin>>N>>M>>K;
    vector<ll> vec;
    for(int i=0; i<N; ++i){
        cin>>tmp;
        vec.push_back(tmp);
    }
    segment_tree segtree(vec);
    ll a,b,c;
    for(int i=0; i<M+K; ++i){
        cin>>a>>b>>c;
        if(a==1){
            segtree.update(b-1,c);
        }
        else{
            cout<<segtree.query(b-1,c-1)<<'\n';
        }
    }
}
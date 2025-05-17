#include<iostream>
#include<vector>
using namespace std;
#define ll long long int 
class minidx_segment_tree{
    private:
        vector<ll> tree; //인덱스
        vector<ll> data; //값
        ll n;
        void buildtree(ll node, ll start, ll end){
            if(start==end){
                tree[node]=start;
            }
            else{
                ll mid=(start+end)/2;
                ll leftchild=2*node+1;
                ll rightchild=2*node+2;
                buildtree(leftchild,start,mid);
                buildtree(rightchild,mid+1,end);
                if(data[tree[leftchild]]==data[tree[rightchild]]){
                    tree[node]=min(tree[leftchild],tree[rightchild]);
                }
                else if(data[tree[leftchild]]<data[tree[rightchild]]){
                    tree[node]=tree[leftchild];
                }
                else{
                    tree[node]=tree[rightchild];
                }
            }
        }
        ll query(ll node, ll start, ll end, ll lft, ll rgt){
            if(start>rgt || end<lft){
                return -1;
            }
            else if(start>=lft && end<=rgt){
                return tree[node];
            }
            ll mid=(start+end)/2;
            ll leftchild=2*node+1;
            ll rightchild=2*node+2;
            
            ll leftquery=query(leftchild,start,mid,lft,rgt);
            ll rightquery=query(rightchild,mid+1,end,lft,rgt);

            if(leftquery==-1) return rightquery;
            if(rightquery==-1) return leftquery;
            if(data[leftquery]==data[rightquery]){
                return min(leftquery,rightquery);
            }
            else if(data[leftquery]<data[rightquery]) return leftquery;
            else return rightquery;
        }
        void update(ll node, ll start, ll end, ll idx, ll value){
            if(start==end){
                data[idx]=value;
                tree[node]=idx;
            }
            else{
                ll mid=(start+end)/2;
                ll leftchild=2*node+1;
                ll rightchild=2*node+2;
                if(idx<=mid){
                    update(leftchild,start,mid,idx,value);
                }
                else{
                    update(rightchild,mid+1,end,idx,value);
                }
                if(data[tree[leftchild]]==data[tree[rightchild]]){
                    tree[node]=min(tree[leftchild],tree[rightchild]);
                }
                else if(data[tree[leftchild]]<data[tree[rightchild]]){
                    tree[node]=tree[leftchild];
                }
                else{
                    tree[node]=tree[rightchild];
                }
            }
        }
    public:
        minidx_segment_tree(const vector<ll>& input){
            data=input;
            n=input.size();
            tree.resize(4*n);
            buildtree(0,0,n-1);
        }
        ll query(ll lft, ll rgt){
            return query(0,0,n-1,lft,rgt);
        }
        void update(ll idx, ll value){
            update(0,0,n-1,idx,value);
        }
};
ll rec(minidx_segment_tree& segtree, vector<ll>& vec, ll start, ll end){
    ll x=segtree.query(start,end);
    if(start==end) return vec[x];
    else if(start>end) return 0;

    ll curval=vec[x]*(end-start+1);

    ll Lseg=rec(segtree, vec, start, x-1);
    ll Rseg=rec(segtree, vec, x+1, end);

    curval=max(curval,Lseg);
    curval=max(curval,Rseg);
    return curval;
}
int main(){//6549
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N,tmp;
    while(cin>>N){
        if(N==0) break;

        vector<ll> vec;
        for(ll i=0; i<N; ++i){
            cin>>tmp;
            vec.push_back(tmp);
        }
        minidx_segment_tree min_segtree(vec);

        ll max_val=rec(min_segtree, vec, 0, N-1);

        // cout<<vec[min_segtree.query(0,N-1)]<<'\n';
        cout<<max_val<<'\n';
    }
}
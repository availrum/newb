#include<iostream>
#include<vector>
using namespace std;
const int con=2147483647;
class segtree{
    private:
        vector<int> tree;
        void build_tree(vector<int>& original, int node, int st, int ed){
            if(st==ed){
                tree[node]=min(tree[node],original[st]);
            }
            else{
                int mid=(st+ed)/2;
                int lc=2*node+1;
                int rc=2*node+2;
                build_tree(original,lc,st,mid);
                build_tree(original,rc,mid+1,ed);
                tree[node]=min(tree[lc],tree[rc]);
            }
        }
        int query(int node, int st, int ed, int l, int r){
            if(r<st || l>ed) return con;
            if(l<=st && ed<=r) return tree[node];

            int mid=(st+ed)/2;
            int lc=2*node+1;
            int rc=2*node+2;

            int lq=query(lc,st,mid,l,r);
            int rq=query(rc,mid+1,ed,l,r);
            return min(lq,rq);
        }

    public:
        int n;
        segtree(vector<int>& original){
            n=original.size();
            tree.resize(4*n,con);
            build_tree(original,0,0,n-1);
        }
        int query(int l, int r){
            return query(0,0,n-1,l,r);
        }
        void qq(void){
            cout<<tree.size()<<'\n';
            for(int i=0; i<10; ++i){
                cout<<tree[i];
                if(i!=tree.size()-1) cout<<' ';
            }
            cout<<'\n';
        }
};
int main(){ //10868
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M,t;
    cin>>N>>M;
    vector<int> vec(N);
    for(int i=0; i<N; ++i){
        cin>>vec[i];
    }
    segtree stree(vec);
    // stree.qq();
    int a,b;
    for(int i=0; i<M; ++i){
        cin>>a>>b;
        cout<<stree.query(a-1,b-1)<<'\n';
    }
}
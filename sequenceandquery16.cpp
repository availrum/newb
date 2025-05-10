#include<iostream>
#include<vector>
using namespace std;
class minidx_segment_tree{
    private:
        vector<int> tree; //인덱스
        vector<int> data; //값
        int n;
        void buildtree(int node, int start, int end){
            if(start==end){
                tree[node]=start;
            }
            else{
                int mid=(start+end)/2;
                int leftchild=2*node+1;
                int rightchild=2*node+2;
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
        int query(int node, int start, int end, int lft, int rgt){
            if(start>rgt || end<lft){
                return -1;
            }
            else if(start>=lft && end<=rgt){
                return tree[node];
            }
            int mid=(start+end)/2;
            int leftchild=2*node+1;
            int rightchild=2*node+2;
            
            int leftquery=query(leftchild,start,mid,lft,rgt);
            int rightquery=query(rightchild,mid+1,end,lft,rgt);

            if(leftquery==-1) return rightquery;
            if(rightquery==-1) return leftquery;
            if(data[leftquery]==data[rightquery]){
                return min(leftquery,rightquery);
            }
            else if(data[leftquery]<data[rightquery]) return leftquery;
            else return rightquery;
        }
        void update(int node, int start, int end, int idx, int value){
            if(start==end){
                data[idx]=value;
                tree[node]=idx;
            }
            else{
                int mid=(start+end)/2;
                int leftchild=2*node+1;
                int rightchild=2*node+2;
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
        minidx_segment_tree(const vector<int>& input){
            data=input;
            n=input.size();
            tree.resize(4*n);
            buildtree(0,0,n-1);
        }
        int query(int lft, int rgt){
            return query(0,0,n-1,lft,rgt);
        }
        void update(int idx, int value){
            update(0,0,n-1,idx,value);
        }
};
int main(){//14428
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M,tmp;
    cin>>N;
    vector<int> vec;
    for(int i=0; i<N; ++i){
        cin>>tmp;
        vec.push_back(tmp);
    }
    minidx_segment_tree min_segtree(vec);
    cin>>M;
    int a,b,c;
    for(int i=0; i<M; ++i){
        cin>>a>>b>>c;
        if(a==1) min_segtree.update(b-1,c);
        else cout<<min_segtree.query(b-1,c-1)+1<<'\n';
    }
}
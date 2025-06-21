#include<iostream>
using namespace std;
int main(){ //17609
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int tcase=0; tcase<T; ++tcase){
        string st;
        cin>>st;
        int lft=0, rgt=st.length()-1;
        int lftsub=-1, rgtsub=-1;
        bool flag=false, passone=false;
        while(lft<=rgt){
            if(flag) break;
            if(st[lft]!=st[rgt]){
                if(!passone){
                    passone=true;
                    //su(mmu)us -> o
                    //a(ppl)a -> o
                    //alplb -> x
                    //a(lqq)a -> o
                    //drord -> o
                    //a(dbb)a -> o
                    //abbcdba -> x
                    //a(b[dbbb]d)a (앞의 b를 지울때만 가능) -> o
                    //ad(ab)da -> o
                    if(lft<=rgt-1 && st[lft]==st[rgt-1]){
                        if(st[lft+1]==st[rgt]){
                            lftsub=lft+2;
                            rgtsub=rgt-1;
                        }
                        ++lft;
                        rgt-=2;
                        continue;
                    }
                    else if(lft+1<=rgt && st[lft+1]==st[rgt]){
                        lft+=2;
                        --rgt;
                    }
                    else flag=true;
                }
                else if(lftsub!=-1 && st[lftsub]==st[rgtsub]){
                    lft=lftsub;
                    rgt=rgtsub;
                    lftsub=-1;
                    rgtsub=-1;
                }
                else flag=true;
            }
            ++lft;
            --rgt;
        }
        if(!passone) cout<<"0"<<'\n';
        else if(!flag) cout<<"1"<<'\n';
        else cout<<"2"<<'\n';
    }
}
#include<iostream>
using namespace std;
#define ll long long int
void kmp(ll* stat, string st){
    int n=st.length();
    int i=-1, j=0;
    stat[j]=i;
    while(j<n){
        if(i==-1 || st[i]==st[j]){
            ++i;
            ++j;
            stat[j]=i;
        }
        else i=stat[i];
    }
}
ll find_pattern(string str, string pattern){
    ll n=str.length();
    ll m=pattern.length();
    ll stat[m+1];
    kmp(stat,pattern);
    ll i=0, j=0, cnt=0;
    while(i<n){
        if(j==-1 || str[i]==pattern[j]){
            ++i, ++j;
        }
        else j=stat[j];
        if(j==m){
            ++cnt;
            j=stat[j];
        }
    }
    return cnt;
}
string str[101];
// ll dp[101];
string fib(int n){
    if(n==0) return "0";
    else if (n==1) return "1";
    if(str[n]!="") return str[n];
    return str[n]=fib(n-1)+fib(n-2);
}
int main(){//4206
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // 기본적으로 패턴의 개수는 F(n)=F(n-1)+F(n-2)를 따라가지만 끝부분이 겹치면 추가로 생김
    // ex) 11과 같은 패턴을 넣으면 개수[F(6)=3, F(5)=1, F(4)=1] >> 겹치는 부분 처리 필요
    // 관찰결과 짝수와 홀수일때로 함수의 끝부분이 다름 (시작부분은 n-1을 따라가기에 항상 같음)
    // 근데 그러면 시작부분은 항상 같고, 뒷부분은 짝/홀로 다르니 짝수-홀수로 나눠서 하면 되는게 아닌가?
    // 패턴의 끝은 항상 n-2고, 패턴의 시작은 항상 n-1이므로 짝수일때 겹치는부분, 홀수일때 겹치는부분
    // 나눠서 계산하면 짝/홀마다 더하는 방식으로 될거같음

    // [n-1 끝나는부분 + n-2시작부분]에서 패턴찾기
    // F(n)이 패턴 길이보다 길어지는 순간부터 계산
    // F(n) 직접 계산은 경험상 30부터 segmantation fault (core dumped) 발생
    // 30 아래일때는 직접 kmp, 이상이면 29,30에서 계산후 dp+kmp 사용

    // for(int i=0; i<101; ++i) str[i]="";
    int N;
    // cin>>N;
    int casenum=1;
    while(cin>>N){
        // if(N==-1) break;
        string pattern;
        cin>>pattern;
        
        ll dp[101];
        ll count;
        string str;

        for(int i=0; i<30; ++i){
            str=fib(i);
            dp[i]=find_pattern(str,pattern);
        }
        ll oddplus=dp[29]-(dp[28]+dp[27]), evenplus=dp[28]-(dp[27]+dp[26]);
        for(int i=30; i<=N; ++i){
            if(i%2==0) dp[i]=dp[i-1]+dp[i-2]+evenplus;
            else dp[i]=dp[i-1]+dp[i-2]+oddplus;
        }
        cout<<"Case "<<casenum<<": "<<dp[N]<<'\n';
        ++casenum;
        // cout<<str<<'\n';
    }
    // for(int i=1; i<=str.length(); ++i) cout<<stat[i]<<' ';
    // cout<<'\n';
    // cout<<count<<'\n';
}
#include<iostream>
#include<queue>
#define ll long long int
using namespace std;
int main(){//13975
	int T;
	cin>>T;
	for(int tcase=0; tcase<T; ++tcase){
		int N;
		cin>>N;
		priority_queue<ll,vector<ll>,greater<ll>> qu;
		ll tmp;
		for(int i=0; i<N; ++i){
			cin>>tmp;
			qu.push(tmp);
		}
		ll sum=0;
		while(qu.size()>1){
			ll num1=qu.top();
			qu.pop();
			ll num2=qu.top();
			qu.pop();
			ll cur_file=num1+num2;
			qu.push(cur_file);
			sum+=cur_file;
		}
		cout<<sum<<'\n';
	}
}
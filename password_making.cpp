#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int L,C;
vector<string> sol;
void btr(vector<char>& vec, int n, vector<char> candi){
    if(candi.size()==L){
        int num_of_consonant=0, num_of_vowels=0;
        string tmp="";
        for(int i=0; i<candi.size(); ++i){
            // cout<<candi[i];
            if(candi[i]=='a' || candi[i]=='e' || candi[i]=='i' 
                || candi[i]=='o' || candi[i]=='u') ++num_of_vowels;
            else ++num_of_consonant;
            tmp+=candi[i];
        }
        // cout<<'\n';
        if(num_of_consonant>1 && num_of_vowels>0) sol.push_back(tmp);
        return;
    }
    for(int i=n; i<vec.size(); ++i){
        candi.push_back(vec[i]);
        btr(vec,i+1,candi);
        candi.pop_back();
    }
}
int main(){ //1759
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>L>>C;
    char tmp;
    vector<char> vec,candi;
    for(int i=0; i<C; ++i){
        cin>>tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end());
    btr(vec,0,candi);
    sort(sol.begin(), sol.end());
    for(int i=0; i<sol.size(); ++i){

        cout<<sol[i]<<'\n';
    }
}
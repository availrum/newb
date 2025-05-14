#include<iostream>
using namespace std;
int main(){//4900
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string st;
    while(cin>>st){
        if(st=="BYE") break;
        string a="", aorigin="", b="", borigin="", input="", input2="";
        bool flag=true;
        int cnt=0;
        for(int i=0; i<st.length(); ++i){
            if(!(st[i]=='+' || st[i]=='=')){
                input2+=st[i];
                ++cnt;
                if(flag) aorigin+=st[i];
                else borigin+=st[i];
            }
            else if(st[i]=='+' && flag){
                flag=false;
                // a+=input;
                // input="";
                continue;
            }
            else continue;
            if(cnt%3==0){
                if(input2=="063"){ //0
                    input+="0";
                }
                else if(input2=="010"){ //1
                    input+="1";
                }
                else if(input2=="093"){ //2
                    input+="2";
                }
                else if(input2=="079"){ //3
                    input+="3";
                }
                else if(input2=="106"){ //4
                    input+="4";
                }
                else if(input2=="103"){ //5
                    input+="5";
                }
                else if(input2=="119"){ //6
                    input+="6";
                }
                else if(input2=="011"){ //7
                    input+="7";
                }
                else if(input2=="127"){ //8
                    input+="8";
                }
                else if(input2=="107"){ //9
                    input+="9";
                }
                input2="";
                if(flag){
                    a+=input;
                    input="";
                    input2="";
                }
                else{
                    b+=input;
                    input="";
                    input2="";
                }
            }
        }
        int tmp=stoi(a)+stoi(b);
        string sol="";
        // if(tmp<100) sol+='0';
        sol+=to_string(tmp);

        cout<<aorigin<<"+"<<borigin<<"=";//<<sol<<'\n';
        for(int i=0; i<sol.length(); ++i){
            if(sol[i]=='0'){ //0
                cout<<"063";
            }
            else if(sol[i]=='1'){ //1
                cout<<"010";
            }
            else if(sol[i]=='2'){ //2
                cout<<"093";
            }
            else if(sol[i]=='3'){ //3
                cout<<"079";
            }
            else if(sol[i]=='4'){ //4
                cout<<"106";
            }
            else if(sol[i]=='5'){ //5
                cout<<"103";
            }
            else if(sol[i]=='6'){ //6
                cout<<"119";
            }
            else if(sol[i]=='7'){ //7
                cout<<"011";
            }
            else if(sol[i]=='8'){ //8
                cout<<"127";
            }
            else if(sol[i]=='9'){ //9
                cout<<"107";
            }
        }
        cout<<'\n';
    }
}
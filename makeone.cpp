#include<iostream>
using namespace std;
int det(int a, int b){
    return a<b ? a:b;
}
int cnt, maktoone[1000001]; 

int main(){//1463
    int N,M,cnt=0;
    cin>>N;
    int leas[N+1]; //**12 4 2 1 / 13 12 4 2 1 / 14 7 6 2 1 / 15 5 4 2 1 / 16 8 4 2 1 / 17 16 8 4 2 1
    //**18 (9 3 1) - (6 2 1) / 19 18 9 3 1 / 20 10 9 3 1 / 21 7 6 2 1 / 22 21 7 6 2 1 / 23 22 21 7 6 2 1 /**24 8 4 2 1
        
    // )
    leas[0]=1; 
    leas[1]=1; 
    leas[2]=1; // (2/1)
    leas[3]=1; //(3/1)
    leas[4]=2; //(4/2/2)
    leas[5]=3; //(5-1 /2/2)
    for(int i=6; i<=N; i++){
        if(i%3==0){//3의 배수일때
            if(i%2==0){//짝수(2의 배수 ex-6,12)
                leas[i]=det(leas[i/3]+1,leas[i/2]+1);
            }
            else{//홀수 (ex-9,15)
                leas[i]=det(leas[i/3]+1, leas[(i-1)/2]+2);
            }
        }
        else if(i%2==0){//3의 배수가 아니고 2의 배수일때
            if((i-1)%3==0){//6배수-2 ex-10,16
                leas[i]=det(leas[i/2]+1,leas[(i-1)/3]+2);
            }
            else{//6배수-4 ex-8,14
                leas[i]=det(leas[i/2]+1,leas[(i-2)/3]+3);
            }
        }
        else{
            if((i-1)%3==0){//6의배수-5 ex-7,13
                leas[i]=det(leas[(i-1)/2]+2,leas[(i-1)/3]+2);
            }
            else if((i-1)){//6의배수-1 ex-11,17
                leas[i]=det(leas[(i-1)/2]+2,leas[(i-2)/3]+3);
            }
        }
        // leas[i]=det(leas[(i+2)])
        // leas[i]=det(leas[(i+2)/3]+1,det(leas[(i+2)/2]+1, det(leas[(i+1)/3]+1,leas[(i+1)/2]+1))); //i+2의 최솟값
    }
    cout<<leas[N]<<'\n';
    return 0;
}

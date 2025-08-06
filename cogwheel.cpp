#include<iostream>
using namespace std;
void clockwise(int* cogwheel){
    int tmp=cogwheel[7];
    for(int i=7; i>=0; --i){
        if(i!=0) cogwheel[i]=cogwheel[i-1];
        else cogwheel[i]=tmp;
    }
}
void counterclockwise(int* cogwheel){
    int tmp=cogwheel[0];
    for(int i=0; i<8; ++i){
        if(i!=7) cogwheel[i]=cogwheel[i+1];
        else cogwheel[i]=tmp;
    }
}
void contact(int* cw1, int* cw2, int* cw3, int* cw4, int num, int dir, bool* cog){
    cog[num-1]=true; // 현재 톱니바퀴 사용처리

    if(num==1 && cw1[2]!=cw2[6] && cog[num]==false){
        contact(cw1,cw2,cw3,cw4,num+1,dir*-1, cog);
    }
    else if(num==2){
        if(cw1[2]!=cw2[6] && cog[num-2]==false){
            contact(cw1,cw2,cw3,cw4,num-1,dir*-1, cog);
        }
        if(cw2[2]!=cw3[6] && cog[num]==false){
            contact(cw1,cw2,cw3,cw4,num+1,dir*-1, cog);
        }
    }
    else if(num==3){
        if(cw2[2]!=cw3[6] && cog[num-2]==false){
            contact(cw1,cw2,cw3,cw4,num-1,dir*-1, cog);
        }
        if(cw3[2]!=cw4[6] && cog[num]==false){
            contact(cw1,cw2,cw3,cw4,num+1,dir*-1, cog);    
        }
    }
    else if(num==4 && cw3[2]!=cw4[6] && cog[num-2]==false){
        contact(cw1,cw2,cw3,cw4,num-1,dir*-1, cog);
    }

    if(dir==1){ // 먼저 접촉면이 어떻게 돌지를 다 재귀로 넣어야 해서 마지막으로 계산
        if(num==1) clockwise(cw1);
        else if(num==2) clockwise(cw2);
        else if(num==3) clockwise(cw3);
        else if(num==4) clockwise(cw4);
    }
    else if(dir==-1){
        if(num==1) counterclockwise(cw1);
        else if(num==2) counterclockwise(cw2);
        else if(num==3) counterclockwise(cw3);
        else if(num==4) counterclockwise(cw4);
    }
}
int main(){ //14891
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int cw1[8], cw2[8], cw3[8], cw4[8];
    string tmp;
    for(int i=0; i<4; ++i){
        cin>>tmp;
        for(int j=0; j<tmp.length(); ++j){
            if(i==0){
                cw1[j]=tmp[j]-'0';
            }
            else if(i==1){
                cw2[j]=tmp[j]-'0';
            }
            else if(i==2){
                cw3[j]=tmp[j]-'0';
            }
            else if(i==3){
                cw4[j]=tmp[j]-'0';
            }
        }
    }
    int K;
    cin>>K;
    for(int i=0; i<K; ++i){
        int num, dir;
        cin>>num>>dir;
        bool check[4]={false,};
        contact(cw1,cw2,cw3,cw4, num, dir, check);
    }
    // for(int i=0; i<8; ++i){
    //     cout<<cw4[i]<<' ';
    // } cout<<'\n';
    int sol=cw1[0]+2*cw2[0]+4*cw3[0]+8*cw4[0];
    cout<<sol<<'\n';
}
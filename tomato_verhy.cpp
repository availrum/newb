#include <iostream>
#include <queue>
#define FOR(x,n) for(int x=0 ; x<n ; ++x)

using namespace std;

int dirM[6] = {1, -1, 0, 0, 0, 0};
int dirN[6] = {0, 0, 1, -1, 0, 0};
int dirO[6] = {0, 0, 0, 0, 1, -1};
struct Vector11{
    int m, n, o;
    int days = 0;
};

int main(){//7569
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M,N,O,P,Q,R,S,T,U,V,W;
    cin>>M>>N>>O;
    int tomatos[O][N][M];
    int total = M*N*O;

    queue<Vector11> qu;

    FOR(o, O)FOR(n, N)FOR(m, M){
        cin >> tomatos[o][n][m];
        Vector11 vec;
        vec.o = o; vec.n = n; vec.m = m;

        if (tomatos[o][n][m] == 1) qu.push(vec);
        else if (tomatos[o][n][m] == -1) total--;
    }

    int days = 0;
    int rippedCnt = 0;

    while (!qu.empty()){
        Vector11 f = qu.front();
        qu.pop();
        rippedCnt++;
        days = f.days;

        for (int i = 0; i < 6; ++i){
            int newIndexM = f.m + dirM[i];
            int newIndexN = f.n + dirN[i];
            int newIndexO = f.o + dirO[i];

            if (newIndexM >= M || newIndexM < 0
             || newIndexN >= N || newIndexN < 0
             || newIndexO >= O || newIndexO < 0){
                continue;
            }

            int *state = &tomatos[newIndexO][newIndexN][newIndexM];

            if (*state == 0){
                *state = 1;
                Vector11 vec;
                vec.o = newIndexO;
                vec.n = newIndexN;
                vec.m = newIndexM;
                vec.days = f.days + 1;
                qu.push(vec);
            }
        }
    }

    if (rippedCnt == total){
        cout << days << "\n";
    }
    else{
        cout << -1 << "\n";
    }

    return 0;
}
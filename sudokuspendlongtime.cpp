#include<iostream>
#include<vector>
using namespace std;
int main(){//12095
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<vector<int>> sudoku;
    sudoku.push_back({8,0,0,0,0,0,0,0,0});
    sudoku.push_back({0,0,3,6,0,0,0,0,0});
    sudoku.push_back({0,7,0,0,9,0,0,0,0});

    sudoku.push_back({0,5,0,0,0,7,0,0,0});
    sudoku.push_back({0,0,0,0,4,5,7,0,0});
    sudoku.push_back({0,0,0,1,0,0,0,3,0});

    sudoku.push_back({0,0,1,0,0,0,0,6,0});
    sudoku.push_back({0,0,8,5,0,0,0,1,0});
    sudoku.push_back({0,9,0,0,0,0,4,0,0});

    for(int i=0; i<9; ++i){
        for(int j=0; j<9; ++j){
            cout<<sudoku[i][j];
            if(j!=8) cout<<' ';
        }
        cout<<'\n';
    }
}
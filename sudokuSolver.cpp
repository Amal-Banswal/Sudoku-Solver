#include <bits/stdc++.h>
#define N 9
using namespace std;


bool isValid(int ch, int row, int col, vector<vector<int>>& board){
    for(int i=0;i<N;i++){
        if(board[row][i]==ch) return false;
        if(board[i][col]==ch) return false;
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==ch) return false;
    }
    return true;
}
    

bool solveSudoku(vector<vector<int>>& board) {
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(board[i][j]==0){
                for(int ch=1;ch<=9;ch++){
                    if(isValid(ch, i, j, board)) {
                        board[i][j]=ch;
                        if(solveSudoku(board)) return true;
                        else board[i][j]=0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

//print the sudoku grid after solve
void sudokuGrid(vector<vector<int>> &grid){ 
   for (int row = 0; row < N; row++){
      for (int col = 0; col < N; col++){
         if(col == 3 || col == 6)
            cout << " | ";
         cout << grid[row][col] <<" ";
      }
      if(row == 2 || row == 5){
         cout << endl;
         for(int i = 0; i<N; i++)
            cout << "---";
      }
      cout << endl;
   }
}


int main(){


    vector<vector<int>> grid{ {3, 0, 6, 5, 0, 8, 4, 0, 0},
    {5, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 8, 7, 0, 0, 0, 0, 3, 1},
    {0, 0, 3, 0, 1, 0, 0, 8, 0},
    {9, 0, 0, 8, 6, 3, 0, 0, 5},
    {0, 5, 0, 0, 9, 0, 6, 0, 0},
    {1, 3, 0, 0, 0, 0, 2, 5, 0},
    {0, 0, 0, 0, 0, 0, 0, 7, 4},
    {0, 0, 5, 2, 0, 6, 3, 0, 0}};


    if (solveSudoku(grid) == true)
        sudokuGrid(grid);
    else
        cout << "No solution exists";

    return 0;
}
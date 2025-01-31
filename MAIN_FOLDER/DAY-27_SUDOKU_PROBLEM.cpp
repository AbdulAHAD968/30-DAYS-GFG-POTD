#include<bits/stdc++.h>

using namespace std;


bool IS_SAFE(vector<vector<int>> &mat, int row, int col, int num){
    for(int i=0 ; i<9 ; i++){
        if(mat[row][i]==num){
            return false;
        }
        if(mat[i][col]==num){
            return false;
        }
    }

    int start_row = 3 * (row/3);
    int start_col = 3 * (col/3);

    for(int i=start_row ; i<start_row+3 ; i++){
        for(int j=start_col ; j<start_col+3 ; j++){
            if(mat[i][j]==num){
                return false;
            }
        }
    }
    return true;
}



bool SOLVE(vector<vector<int>> &mat){

    for(int i=0 ; i<9 ; i++){
        for(int j=0 ; j<9 ; j++){

            if(mat[i][j]==0){
            
                for(int k=1 ; k<=9 ; k++){
                    if(IS_SAFE(mat,i,j,k)){
                        mat[i][j]=k;
                        if(SOLVE(mat)){
                            return true;
                        }
                        mat[i][j]=0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}



// WRAPER FUNCTION TO HANDLE THE DATA.
void SOLVE_SUDOKU(vector<vector<int>> &mat){
    SOLVE(mat);
}

int main(){

    vector<vector<int>> sudoku = {  {3, 0, 6, 5, 0, 8, 4, 0, 0},
                                    {5, 2, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 8, 7, 0, 0, 0, 0, 3, 1},
                                    {0, 0, 3, 0, 1, 0, 0, 8, 0},
                                    {9, 0, 0, 8, 6, 3, 0, 0, 5},
                                    {0, 5, 0, 0, 9, 0, 6, 0, 0},
                                    {1, 3, 0, 0, 0, 0, 2, 5, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 7, 4},
                                    {0, 0, 5, 2, 0, 6, 3, 0, 0}  };


    SOLVE_SUDOKU(sudoku);
    
    for(int i=0 ; i<9 ; i++){
        for(int j=0 ; j<9 ; j++){
            cout<<sudoku[i][j]<<" ";
        }
        cout<<endl;
    }


return 0;
}
#include<bits/stdc++.h>

using namespace std;


// MAKE A 2-D GRID.
vector<vector<int>> sol;
vector<int> board;


// HELPER FUNCTION, [USING BACKTRACKING]
void SOLVE(int j , int n , vector<bool>& col , vector<bool> &d1 , vector<bool> &d2){
    
    // A VALID PLACEMENT
    if(j==n){
        sol.push_back(board);
        return;
    }
    
    for(int i=0 ; i<n ; i++){
        
        if( !col[i] && !d1[i+j] && !d2[j-i+(n-1)]){
            
            board[j] = i+1;
            
            col[i] = d1[i+j] = d2[j-i + (n-1)] = true;

            SOLVE(j+1, n, col, d1, d2);

            col[i] = d1[i+j] = d2[j-i + (n-1)] = false;  // Backtrack
        }
    }
}
    
    
// WRAPER FUNCTION
vector<vector<int>> nQueen(int n) {
    
    sol.clear();
    board.resize(n);
    
    vector<bool> col(n+1 , false);
    
    vector<bool> d1(n*2 , false);
    vector<bool> d2(n*2 , false);
    
    SOLVE( 0 , n , col , d1 , d2 );
    
    return sol;
}



// MAIN FUNCTION.
int main(){

    int n;
    cout<<"Enter the size of the N-Queens board: ";
    cin>>n;
    
    vector<vector<int>> ans = nQueen(n);
    
    cout<<"Number of solutions: "<<ans.size()<<endl;
    
    for(int i=0 ; i<ans.size() ; i++){
        cout<<"Solution "<<i+1<<": ";
        for(int j=0 ; j<n ; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    
return 0;
}
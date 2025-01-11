#include<bits/stdc++.h>

using namespace std;


// SOLUTION CLASS CONTAINING THE FUNCTION.
class Solution{


    // CONSTRUCTORS AND DISTRUCTORS WILL BE DEFAULT.

  public:
  
    const int MAX_CHAR = 26;
    
    // ACTUALLY THIS PROBLEM IS SIMILAR TO THE DAY 07 PROBLEM FOR FINDING THE NUMBER OF UNIQUE ELEMENTS IN A WINDOW.
    // THAT CASE WAS FOR THE INTEGERS BUT NOW WE HAVE THE CHARACTERS.
    // PEACE AND EAZE IF YOU KNOW OR WORK WITH THE LAST ONE. THANKS.
    int LONGEST_UNIQUE_SUBSTRING(string &s) {
        
        int n = s.size();
        int res = 0;
    
        // last index of all characters is initialized as -1
        vector<int> LAST_IDX(MAX_CHAR, -1);
    
        // Initialize start of current window
        int start = 0;
    
        // Move end of current window
        for(int end=0 ; end<n ; end++){
    
            // Find the last index of s[end]
            // Update starting index of current window as
            // maximum of current value of end and last index + 1
            start = max(start, LAST_IDX[s[end] - 'a'] + 1);
    
            // Update result if we get a larger window
            res = max(res, end-start+1);
    
            // Update last index of s[end]
            LAST_IDX[s[end] - 'a'] = end;
        }
        
    return res;
    }
};


// OUR MAIN FUNCTION WITH ONLY ONE TEST CASE FOR THE SOLUTION CLASS FUNCTION.
int main(){

    Solution sol;
    string s = "abcabcbb";
    cout << "Length of the longest substring without repeating characters: " << sol.LONGEST_UNIQUE_SUBSTRING(s) << endl;

return 0;
}
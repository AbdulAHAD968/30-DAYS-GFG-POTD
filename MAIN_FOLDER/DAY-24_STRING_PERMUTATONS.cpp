#include<bits/stdc++.h>

using namespace std;


// FUNCTION TO PERMUTATION OF GIVEN STRING.
void HELPER(string &s, int start, vector<string> &result, unordered_set<string> &seen){

    if(start == s.size()-1){

        // CHECK IF THE CURRENT PERMUTATION IS ALREADY IN THE SET.
        if(seen.find(s) == seen.end()){
            result.push_back(s);
            seen.insert(s);
        }
        return;
    }

    for(int i=start ; i<s.size() ; i++){

        if(i != start && s[start] == s[i]){
            continue;
        }
        swap(s[start], s[i]);
        HELPER(s, start + 1, result, seen);
        swap(s[start], s[i]);
    }
}


// MAIN FUNCTION TO GET THE PERMUTATION OF PASSED STING.
vector<string> FIND_PERMUTATION(string s){

    vector<string> result;

    unordered_set<string> seen;
    
    sort(s.begin(), s.end());  // SORT SO THAT DUPLICATES CAN BE GROUPED TOGETHER.
    
    HELPER(s, 0, result, seen);

return result;
}


// OUR MAIN FUNCTION, WITH ONL ONE TEST CASE...
int main(){


return 0;
}
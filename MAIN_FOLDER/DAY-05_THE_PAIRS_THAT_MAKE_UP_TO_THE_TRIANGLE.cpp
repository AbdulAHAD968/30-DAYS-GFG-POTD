#include<bits/stdc++.h>

using namespace std;

// MAIN FUNCTION TO EVALUATE THE NUMBER OF TRIANGLES.
int COUNT_TRIANGLES(vector<int>& arr) {
    
    int result=0;
    
    sort(arr.begin() , arr.end());
    
    for(int i=2 ; i<arr.size() ; i++){
        
        int start=0;    // below this 
        int end = i-1;  // after this
        
        
        // again relying on double pointer approach.
        while(start<end){
            
            // as per condition the pair will form triangle if the sum
            // of two is greater than or equal to the third.
            if(arr[start]+arr[end] > arr[i]){
                result += end - start;
                end--;
            }
            else{
                start++;
            }
        }
    }
    return result;
}


// MAIN FUNCTION WITH ONLY ONE TEST CASE. [HAHAHA]
int main(){

    vector<int> arr = {10, 20, 30, 40, 50};
    
    cout << "Number of triangles: " << COUNT_TRIANGLES(arr) << endl;
    
return 0;
}
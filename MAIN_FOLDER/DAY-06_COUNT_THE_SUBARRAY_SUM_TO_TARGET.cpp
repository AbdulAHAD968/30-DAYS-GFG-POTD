#include<bits/stdc++.h>

using namespace std;

// THE PROBLEM WAS REPEATED,


// I HAVE TRIED HASH MAO EARLIER, USING UNORDERED_MAP OF STL.
// NOW, I HAVE USED SLIDING WINDOW APPRAOCH TO TACKLE THIS PROBLEM.
vector<int> SUB_ARRAY_SUM(vector<int> &arr, int target){
        
    int START=0;
    int SUM = 0;

    // TRAVERSE FROM BOTH ENDS AND MAKE THE WINDOW BECOME SHRINK AND SHRINK.
    for(int END=0 ; END<arr.size() ; END++){
        
        SUM += arr[END];

        // SHRINK THE WINDOW, AS LONG AS THE CURRENT SUM EXCEEDS OUR TARGET VALUE.
        while(SUM>target && START<=END){
            SUM -= arr[START];
            START++;
        }

        // CHECK IF THE SUM MATCHES THE TARGET VALUE.
        if(SUM == target){
            return {START+1 , END+1};    // WE HAVE ADDED 1 HERE AS IT WAS MENTIONED TO RETURN 1 BASED INDEXES.
        }
    }


// If no subarray sum equals the target, return -1    
return {-1};
}


// OUR MAIN FUNCTION WITH ONE TEST CASE ONLY...
int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 15;
    vector<int> result = SUB_ARRAY_SUM(arr, target);
    if(result.size() > 0){
        cout << "The subarray with sum " << target << " starts at index " << result[0] << " and ends at index " << result[1] << endl;
    }else{
        cout << "No subarray with sum " << target << " found." << endl;
    }
    return 0;
}
#include<bits/stdc++.h>

using namespace std;


// MAIN FUNCTION TO EVALUATE THE CASE.
int LONGEST_SUBARRAY_WITH_SUM_K(vector<int>& arr, int k) {
        
    unordered_map<int, int> TEST;
    int CADIT = 0;
    int TARGET = 0;

    for(int i=0 ; i<arr.size() ; i++){
        
        TARGET += arr[i];

        // Check if the entire prefix sums to k
        if(TARGET == k){
            CADIT = i+1;
        }

        // If prefixSum - k exists in the map then there exist such 
        // subarray from (index of previous prefix + 1) to i.
        else if(TEST.find(TARGET-k) != TEST.end()){
            CADIT = max(CADIT, i - TEST[TARGET - k]);
        }

        // Store only first occurrence index of TARGET
        if(TEST.find(TARGET) == TEST.end()){
            TEST[TARGET] = i;
        }
        
    }

return CADIT;
}



// OUR MAIN FUNCTION WITH ONLY ONE TEST CASE...
int main(){

    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};
    int k = 23;
    
    int result = LONGEST_SUBARRAY_WITH_SUM_K(arr, k);
    cout << "Length of longest subarray with sum " << k << " is " << result << endl;

return 0;
}
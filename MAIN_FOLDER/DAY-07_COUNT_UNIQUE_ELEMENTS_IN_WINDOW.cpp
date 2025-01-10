#include<bits/stdc++.h>

using namespace std;


// MAIN FUNCTION TO COUNT DISTINCT ELEMENTS IN THE WINDOW SIZE.
vector<int> COUNT_UNIQUE_WINDOWS(vector<int> &arr, int k) {
        
    int n = arr.size();  
    vector<int> res;
    unordered_map<int, int> freq;
    
    // Store the frequency of elements of first window
    for(int i = 0; i < k; i++){
        freq[arr[i]] += 1;
    }
    
    // Store the count of distinct element of first window
    res.push_back(freq.size());
    
    for(int i = k; i < n; i++) {
        freq[arr[i]] += 1;
        freq[arr[i - k]] -= 1;
        
        // If the frequency of arr[i - k] becomes 0, remove 
        // it from hash map
        if(freq[arr[i - k]] == 0){
            freq.erase(arr[i - k]);
        }
        
        res.push_back(freq.size());
    }
    
return res;
}


// OUR MAIN FUNCTION WITH ONLY ONE TEST CASE...
int main(){
    vector<int> arr = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    int k = 4;
    
    vector<int> result = COUNT_UNIQUE_WINDOWS(arr, k);
    
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    
    return 0;
}
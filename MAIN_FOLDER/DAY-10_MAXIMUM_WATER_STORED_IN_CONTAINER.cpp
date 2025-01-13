#include<bits/stdc++.h>

using namespace std;


// FUNCTION TO EVALUATE THE MAXIMUM AMOUNT OF WATER THAT CAN BE STORED IN CONTAINER.
int MAX_WATER(vector<int> &arr) {
        
    int left=0;
    int right=arr.size() - 1;
    int res=0;
    
    // using two pointer approach
    while(left<right){
        
        int water = min(arr[left], arr[right]) * (right-left);
        
        res = max(res, water);
        
        // if we are below the mark, incriment it.
        if(arr[left] < arr[right]){
            left++;
        }
        // if we are above the mark decriment it.
        else{
            right--;
        }
    }

return res; 
}


// OUR MAIN FUNCTION WITH ONLY ONE TEST CASE...
int main(){
    
    // Given array
    vector<int> arr = {3, 0, 2, 0, 4};
    
    // Call the function and print the result
    cout<<"\n MAXIMUM WATER THAT CAN BE TRAPPED IN THESE CONTAINERS IS :: "<<MAX_WATER(arr)<<endl;
    
    
return 0;
}
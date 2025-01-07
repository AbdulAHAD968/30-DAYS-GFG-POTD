#include<bits/stdc++.h>

using namespace std;


// THIS IS AGAIN THE SIMILAR PROBLEM RELATED TO COUNTING THE SUM OF PAIR EQUAL TO TARGET.
int countPairs(vector<int> &arr, int target){
        
    int ans=0;
    int start=0;
    int end=arr.size()-1;

    while(start<end){
    
        int current_sum = arr[start]+arr[end];
    
        if(current_sum>target){
            end--;
        }
        else if(current_sum < target){
            start++;
        }
        else{
            
            int e1=arr[start];
            int e2 = arr[end];
            int c1=0 , c2=0;
    
            // Count duplicates at startart of array
            while(start <= end && arr[start] == e1){
                start++;
                c1++;
            }
    
            // Count duplicates at end of the array
            while(start <= end && arr[end] == e2){
                end--;
                c2++;
            }
    
            if(e1 == e2){
                ans += (c1 * (c1 - 1)) / 2;     // nC2 formula
            }
            else{
                ans += c1 * c2;
            }
        }
    }
    
    return ans;
}


// MAIN FUNCTION WITH ONLY ONE TEST CASE. JUST FOR UNDERSTANDING HOW THE THINGS WORK.
int main(){

    vector<int> arr = {1, 2, 3, 4, 4, 4, 7, 8, 8, 9};
    int target = 6;

    cout << "Number of pairs with sum equal to " << target << " : " << countPairs(arr, target) << endl;

    return 0;
}
#include<bits/stdc++.h>

using namespace std;


vector<int> sumClosest(vector<int>& arr, int target) {
        
    // EDGE CASE: AGR ARRAY KA SIZE LESS HY TO KHALI RETURN KR DO.
    if(arr.size()<2){
        return {};
    }

    // STL HEAP SORT.
    sort(arr.begin(), arr.end());
    
    int left=0 , right=arr.size()-1;
    int CADET = INT_MAX;
    vector<int> result;

    // THE BEST TWO-POINTER APPROACH.
    while(left<right){
        
        int sum = arr[left] + arr[right];

        // MAKE CHANGE IF NEW BEST IS FOUND.
        if(abs(target-sum) < abs(target-CADET)){
            CADET = sum;
            result = {arr[left], arr[right]};
        }

        if(sum<target){
            left++;
        }
        else{
            right--;
        }
    }

return result;
}

// DUMMY MAIN. HAHAHA
int main(){

    vector<int> arr = {1, 4, 45, 6, 10, -8};
    int target = 16;

    vector<int> result = sumClosest(arr, target);
    cout << "Closest pair is: " << result[0] << ", " << result[1] << endl;
return 0;
}
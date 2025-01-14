#include<bits/stdc++.h>

using namespace std;


// MAIN FUNCTION TO EVALUATE THE EQUILIBRIUM POINT.
int FIND_EQUILIBRIUM(vector<int> &arr) {
    
    int total=0;
    
    // get the sum of array.
    for(int i : arr){
        total += i;
    }
    
    int left_sum=0;
    
    // traverse from left to right, bruteforcing the right candidate
    for(int i=0 ; i<arr.size() ; i++){
        
        // eq. pos finder
        int check = total - arr[i] - left_sum;
        
        // validator
        if(check == left_sum){
            return i;
        }
        
        // traverser, if prev condition was false
        left_sum += arr[i];
    }
    
    // error case not found.
    return -1;
}


// OUR MAIN FUNCTION FOR TESTING ONLY ONE CASE.
int main(){
    
    vector<int> arr = {2, 13, 4, 6, 19};
    
    int equilibrium_point = FIND_EQUILIBRIUM(arr);
    
    if(equilibrium_point!= -1){
        cout<<"\nEQUILIBRIUM POINT IS AT INDEX = ["<< equilibrium_point<<"] ALONG THE ELEMENT { "<<arr[equilibrium_point-1]<<"} \n";
    }else{
        cout<<"\nNO EQUILIBRIUM POINT FOUND."<<endl;
    }
    
    return 0;
}
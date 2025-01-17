#include<bits/stdc++.h>


using namespace std;


// THIS WAS MY APPROACH, SIMPLE YET LESS EFFICENT.

// A HELPER FUNCTION TO GET THE PRODUCT. [O(N)]
void help(vector<int> arr , vector<int> &res , int idx){
        
    int prod=1;
    
    for(int i=0 ; i<arr.size() ; i++){
        if(i == idx){
            continue;
        }
        else{
            prod *= arr[i];
        }
    }
    
    res.push_back(prod);
}

// MAIN FUNCTION, WITH TIME COMPLEXITY OF [O(N)^2]
vector<int> productExceptSelf(vector<int>& arr) {
    
    vector<int> res;
    
    for(int i=0 ; i<arr.size() ; i++){
        help(arr , res, i);
    }
    
    return res;
}


// OPTIMIZED MY CODE USING GPT GAVE ME AN AMAZING OUTPUT.
vector<int> OPTIMIZED_PRODUCT_EXCEPT_SELF(vector<int> arr){
    
    int n = arr.size();  
    vector<int> res(n, 1);  
    
    // CALCULATE THE PREFIX PRODUCT.
    // In the first loop, you compute the products of all the elements before each index 
    // (prefix products). For example, res[i] will hold the product of all elements to the left of index i.
    for(int i=1 ; i<n ; i++){  
        res[i] = res[i-1] * arr[i-1];  
    }  
    

    // CALCULATE THE SUFFIX PRODUCT AND MULTIPLY IT WITH THE SUFFIX PRODUCT.
    // In the second loop, you traverse the array in reverse and compute the products 
    // of all the elements after each index (suffix products). You multiply these suffix 
    // products with the corresponding prefix products already stored in res.

    int SUFFIX_PROD = 1;  
    
    for(int i=n-1 ; i>=0 ; i--){
        res[i] *= SUFFIX_PROD;
        SUFFIX_PROD *= arr[i];
    }

return res;
}


// OUR MAIN FUNCTION WITH ONYL ONE TEST CASE.
int main(){
    
    vector<int> arr = {1,2,3,4};
    vector<int> res = productExceptSelf(arr);
    
    for(int i=0 ; i<res.size() ; i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    
    res = OPTIMIZED_PRODUCT_EXCEPT_SELF(arr);
    
    for(int i=0 ; i<res.size() ; i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;

return 0;
}
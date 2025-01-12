#include<bits/stdc++.h>

using namespace std;


// CALCULATE HOW MUCH RAIN WATER CAN BE TRAPPED IN THE BLOCKS OF AN ARRAY.
int TRAP_RAIN_WATER(vector<int> arr){

    // GET THE SIZE OF ARRAY.
    int size = arr.size();
    
    int left=1 , right=size-2;
    long long result=0;
    
    int L_max = arr[left-1] , R_max = arr[right+1];
    

    // USING TWO POINTER TECHINQUE TO AVOID LOOP'S NESTING.
    while(left<=right){
        
        if(R_max<=L_max){
            result += max ( 0 , R_max - arr[right]);
            R_max = max ( R_max , arr[right] );
            right--;
        }
        else{
            result += max ( 0 , L_max - arr[left]);
            L_max = max ( L_max , arr[left] );
            left++;
        }
    }
    
    return result;
}



// OUR MAIN FUNCTION WITH ONLY ONE TEST CASE.
int main(){

    vector<int> test = {1,2,3,4,8,4,9};

    int res = TRAP_RAIN_WATER(test);

    cout<<"\n THE RAIN WATER PARTICLES TRAPPED INSIDE THE ARRAY ARE  ::  "<<res<<endl;

return 0;
}
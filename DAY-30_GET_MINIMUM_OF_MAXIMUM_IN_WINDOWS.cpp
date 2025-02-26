#include<bits/stdc++.h>

using namespace std;

// FUNCTION TO GET THE MINIMUM OF THE MAXIMUM IN SLIDING WINDOWS.
vector<int> maxOfMins(vector<int>& arr) {
    
    // get the size
    int size=arr.size();
    // make a result vector of that size and initialize all teh entries with 0.
    vector<int> res(size,0);
    // make a stack to get the priority obj (value basically)
    stack<int> s;
    
    // temp vector for maximum storage
    vector<int> temp(size,0);
    
    for(int i=0 ; i<size ; i++){
        
        // recureively check for the condition match, and fill the temp vector
        while(!s.empty() && arr[s.top()] >= arr[i]){
            int top = s.top();
            s.pop();
            int window = s.empty() ? i : i-s.top()-1;
            temp[top] = window;
        }
        s.push(i);
    }
    
    // see if we miss any one, just in case...
    while(!s.empty()){
        int top = s.top();
        s.pop();
        int window = s.empty() ? size : size-s.top()-1;
        temp[top] = window;
    }
    
    // populate the resultant vector from temp and the stack.
    for(int i=0 ; i<size ; i++){
        int window = temp[i]-1;
        res[window] = max(res[window],arr[i]);
    }
    
    for(int i=size-2 ; i>0 ; i--){
        res[i] = max(res[i] , res[i+1]);
    }
    
    // all set, just return
    return res;
}


// OUR MAIN FUCNTION WITH ONLY ONE TEST CASE...
int main(){

    vector<int> arr = {1, 3, -1, -2, 5, 3, 6, 7};
    vector<int> res = maxOfMins(arr);
    
    for(int i=0 ; i<res.size() ; i++){
        cout << res[i] << " ";
    }

return 0;
}
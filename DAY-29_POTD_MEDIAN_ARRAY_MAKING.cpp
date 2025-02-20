#include<bits/stdc++.h>


using namespace std;


// GET THE MEDIAN OF THE DATA SET.
vector<double> getMedian(vector<int> &arr) {
        
    // USING MAX HEAP AND MIN HEAP.
    // SUCH THAT THE INSERTIONS WILL BE AT LOG-N AND THE RETRIVEL WILL BE AT O(1)
    priority_queue<int> left_half;
    priority_queue<int , vector<int> , greater<int>> right_half;
    
    vector<double> median;
    
    for(int i:arr){
        
        // PLACING THE ELEMENT AT CORRECT LOCATION
        if(left_half.empty() || i<=left_half.top()){
            left_half.push(i);
        }
        else{
            right_half.push(i);
        }
        
        // REBALANCING THE HEAPS IF NECESSARY.
        if(left_half.size() > right_half.size()+1){
            right_half.push(left_half.top());
            left_half.pop();
        }
        else if(right_half.size() > left_half.size()){
            left_half.push(right_half.top());
            right_half.pop();
        }
        
        // CALCULATING THE MEDIAN AND PUSHING IT TO THE OUTPUT VECTOR.
        if(left_half.size() == right_half.size()){
            median.push_back((left_half.top() + right_half.top()) / 2.0);
        }
        else{
            median.push_back(left_half.top());
        }
    }
    
    // RETURNING THE MEDIANS.
    return median;
}


// THIS IS OUR MAIN FUNCTION WITH ONLY ONE TEST CASE...
int main(){
    
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    vector<double> medians = getMedian(arr);
    
    for(double m:medians){
        cout << m << " ";
    }
    
    return 0;
}
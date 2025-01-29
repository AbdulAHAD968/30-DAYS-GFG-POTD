#include<bits/stdc++.h>

using namespace std;


double POWER_FUN(double num , int exp){

    // BASE CASE.
    if(exp==0){
        return 1;
    }

    // CASE IF THE EXPONENT IS NEGATIVE.
    if(exp<1){
        return 1/POWER_FUN(num, abs(exp));
    }

    // GET THE HALF IN LOG-N TIME INSTEAD OF GOING FOR THE 1-BY-1 APPROACH.
    double temp = POWER_FUN(num, exp/2);

    // IF THE EXPONENT IS EVEN, RETURN THE SQUARE OF THE HALF.
    if(exp%2==0){
        return temp*temp;
    }
    // IF THE EXPONENT IS ODD, RETURN THE NUM * THE SQUARE OF THE HALF.
    else{
        return num*temp*temp;
    }

}


// OUR MAIN FUNCTION WITH ONLY ONE TEST CASE.
int main(){

    double num = 2.5;
    int exp = 3;

    double result = POWER_FUN(num, exp);
    cout<<num<<" raised to the power of "<<exp<<" is: "<<result<<endl;
    
return 0;
}
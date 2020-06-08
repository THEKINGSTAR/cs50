// CPP program to implement Luhn algorithm 
#include <bits/stdc++.h> 
#include <stdio.h>
//#include <cs50.h>
#include <ctype.h>
using namespace std; 
  
// Returns true if given card number is valid 
bool checkLuhn(const string& cardNo) 
{ 
    int nDigits = cardNo.length(); 
  
    int nSum = 0, isSecond = false; 
    for (int i = nDigits - 1; i >= 0; i--) { 
  
        int d = cardNo[i] - '0'; 
  
        if (isSecond == true) 
            d = d * 2; 
  
        // We add two digits to handle 
        // cases that make two digits after 
        // doubling 
        nSum += d / 10; 
        nSum += d % 10; 
  
        isSecond = !isSecond; 
    } 
    return (nSum % 10 == 0); 
} 
  
// Driver code 
int main() 
{ 

    string cardNo ;
    cout << "Please enter your credit card number : ";
    // 79927398713 --Valid card number
    // 11232465456 --not valid card number
    cin >> cardNo;

    // string cardNo = "79927398713";

    if (checkLuhn(cardNo)) 
        printf("This is a valid card"); 
    else
        printf("This is not a valid card"); 
    return 0; 
} 
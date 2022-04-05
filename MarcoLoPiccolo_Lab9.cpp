// MarcoLoPiccolo_Lab9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>    //Preprocessor directive
#include <cmath>       //allows us to use functions such as pow
using namespace std;   //allows us to use functions without needing std: in front of it

double calculateInterest(double initialAmount, double interestRate, int numYears);   //Function header

int main()
{
    double initialAmount;    //declares two variables that are of type double since the user can enter a dollar amount that has change and the interest rate is in decimal form
    double interestRate;     
    int numYears;            //number of years is of type int since we are just doing based off of whole number years passing
    double compoundInterestFormula;   //saves the value of the normal compound interest formula that is used below
    
    cout << "Enter Initial Value Amount" << endl;         //Asks user to enter a the initial value with a while loop to check to make sure the user doesn't enter a negative number
    cin >> initialAmount;
    while (initialAmount <= 0) {
        cout << "Invalid initial amount, please enter a value greater than 0" << endl;
        cin >> initialAmount;
    }

    cout << "Enter the Interest Rate on the account, enter in decimal format, example 10% would be 0.10" << endl;  //Asks user to enter the interest rate, not in percentage form but in decimal form such as 0.10 
    cin >> interestRate;
    while (interestRate < 0 || interestRate >= 1) {     //uses the while loop to check to make sure the interest rate isn't negative and doesn't go past 1
        cout << "Invalid interest Rate, please enter a value that is greater than 0, but less than 1" << endl;
        cin >> interestRate;
    }

    cout << "Enter the amount years the amount will accrue interest" << endl;  //Asks user to enter the number of years that the interest rate will happen for
    cin >> numYears;
    while (numYears <= 0) {                                                       //while loop checks to make sure that the user doesn't enter a negative number for amount of years
        cout << "Invalid amount of years, the amount must be greater than 0 years, please enter another value" << endl;
        cin >> numYears;
    }

    cout << "Using Recursion the amount of money you will have in your account after the entered years is $";   //displays the value using the recursion function below
    cout << calculateInterest(initialAmount, interestRate, numYears) << endl;

    cout << "Using the basic compound interest formula the amount of money in your account is $";   //displays the value using just the basic compound interest formula and uses the pow function for
    compoundInterestFormula = initialAmount * pow(1 + interestRate, numYears);                      //making something to the power of number of years
    cout << compoundInterestFormula << endl;                                                         //used to check to make sure the recursion formula is correct

    system("Pause");
    return 0;
}

//Functions uses type double so that it can return an accurate amount after interest is compounded with the three input parameters being initial value, interest rate, and the number of years it will compound for
//Function uses recursion to return the compounded value 
double calculateInterest(double initialAmount, double interestRate, int numYears) {
    if (numYears == 0) {         //base case is activated when numyears reaches 0 and then returns the initial amount
        return initialAmount;
    }
    else {
        double interest = initialAmount * interestRate;   //calculates the interest per year by multiplying the decimal value interest rate by the initial amount
        return calculateInterest(initialAmount + interest, interestRate, numYears - 1);  //this initial amount changes each time the function is called as the interest is added to the initial amount
    }                                                                                     //which is the initial amount parameter in the function and the number of years is subtracted each time by one until it 
}                                                                                          //reaches 0 
                                                                                            //because the initial amount keeps changing once num years reaches 0 then the initial amount paramater will have all
                                                                                             //added interest which will then return the initial amount with each year's interest added to it giving us the 
                                                                                             //compounded interest
#include <iostream>
#include "mersenne-twister.h"
int chooseRandomNumber(int min, int max);
using namespace std;

int num1, num2, num3, num4 ,num5 , num6;

// Funtion to replace the used numbers after each calculation by 0.
// Parameter: replaceNum - the number will be replaced by 0.
void replaceNumberByZero(int replaceNum){
    if (replaceNum == num1){
        num1 = 0;
    }
    else if (replaceNum == num2){
        num2 = 0;
    }
    else if (replaceNum == num3){
        num3 = 0;
    }
    else if (replaceNum == num4){
        num4 = 0;
    }
    else if (replaceNum == num5){
        num5 = 0;
    }
    else if (replaceNum == num6){
        num6 = 0;
    }
}

// Funtion to replace the first avaiable 0 with a calculation result.
// Parameter: ReplaceZero - the result will be inserted into the first availabe 0 slot.
void replaceZeroByResult(int ReplaceZero){
    if (num1 == 0) {
        num1 = ReplaceZero;      
    }
    else if (num2 == 0) {
        num2 = ReplaceZero;        
    }
    else if (num3 == 0) {
        num3 = ReplaceZero;       
    }
    else if (num4 == 0) {
        num4 = ReplaceZero;        
    }
    else if (num5 == 0) {
        num5 = ReplaceZero;       
    }
    else if (num6 == 0) {
        num6 = ReplaceZero;       
    }
}

// Funtion to display current sequence numbers.
// It will print out all non-zero numbers and each number followed by a space.
void displayNumberSequence(){
    if (num1 != 0) {
        cout << num1 << " ";
    }
    if (num2 != 0) {
        cout << num2 << " ";
    }
    if (num3 != 0) {
        cout << num3 << " ";
    }
    if (num4 != 0) {
        cout << num4 << " ";
    }
    if (num5 != 0) {
        cout << num5 << " ";
    }
    if (num6 != 0) {
        cout << num6 ;
    }
}

int main() {
    int randSeed = 0;
    cout << "Enter random seed: ";
    seed(randSeed);
    cin >> randSeed; 
    seed(randSeed);

    int bigNumberChoice;
       
    cout << endl;
    cout << "Let's play Countdown!" << endl;
    cout << "How many big numbers would you like (0-4)? ";
    cin >> bigNumberChoice;
    cout << endl;
    cout << endl;
    cout << "Your numbers are: ";

// Generate the number sequence based on the selected big numbers.

    if (bigNumberChoice == 0) {
        num1 = chooseRandomNumber(1,10);
        num2 = chooseRandomNumber(1,10);
        num3 = chooseRandomNumber(1,10);
        num4 = chooseRandomNumber(1,10);
        num5 = chooseRandomNumber(1,10);
        num6 = chooseRandomNumber(1,10);
    }
    else if (bigNumberChoice == 1) {
        num1 = 25 * chooseRandomNumber(1,4);
        num2 = chooseRandomNumber(1,10);
        num3 = chooseRandomNumber(1,10);
        num4 = chooseRandomNumber(1,10);
        num5 = chooseRandomNumber(1,10);
        num6 = chooseRandomNumber(1,10);  
    }
    else if (bigNumberChoice == 2) {
        num1 = 25 * chooseRandomNumber(1,4);
        num2 = 25 * chooseRandomNumber(1,4);
        num3 = chooseRandomNumber(1,10);
        num4 = chooseRandomNumber(1,10);
        num5 = chooseRandomNumber(1,10);
        num6 = chooseRandomNumber(1,10);      
    }
    else if (bigNumberChoice == 3) {
        num1 = 25 * chooseRandomNumber(1,4);
        num2 = 25 * chooseRandomNumber(1,4);
        num3 = 25 * chooseRandomNumber(1,4);
        num4 = chooseRandomNumber(1,10);
        num5 = chooseRandomNumber(1,10);
        num6 = chooseRandomNumber(1,10);
    }
    else if (bigNumberChoice == 4) {
        num1 = 25 * chooseRandomNumber(1,4);
        num2 = 25 * chooseRandomNumber(1,4);
        num3 = 25 * chooseRandomNumber(1,4);
        num4 = 25 * chooseRandomNumber(1,4);
        num5 = chooseRandomNumber(1,10);
        num6 = chooseRandomNumber(1,10);              
    }
    cout << num1 << " " << num2 << " " << num3 << " "
        << num4 << " " << num5 << " " << num6 << " " << endl;;
    

// Calculation
    // random the target number
    int targetNumber = chooseRandomNumber(101,999);

    cout << "The target is: " << targetNumber << endl;
    
    int firstNum;       // Variable for first number in calculation
    int secondNum;      // Variable for second number in calculation
    char mathOperators; // Variable for math operators
    int result;         // Variable for calculation result
    
    int i = 0;
    while (i < 5){
        cout << "Enter a calculation (or 0 to quit): ";
        cin >> firstNum;

// if you enter 0, program is closed.
        if (firstNum == 0){
            break;
        }
        cin >> mathOperators;
        cin >> secondNum;

// display calculation
        if (mathOperators == '+'){
            result = firstNum + secondNum;
            cout << firstNum << " + " << secondNum << " = " << result << endl;
        } 
        else if (mathOperators == '-'){
            result = firstNum - secondNum;
            cout << firstNum << " - " << secondNum << " = " << result << endl;           
        }
        else if (mathOperators == '*'){
            result = firstNum * secondNum;
            cout << firstNum << " * " << secondNum << " = " << result << endl;           
        }
        else if (mathOperators == '/'){
            // check to make sure the denominator is different from 0
            if (secondNum!= 0){
                result = firstNum / secondNum;
                cout << firstNum << " / " << secondNum << " = " << result << endl;
            }
            else{
                break;
            }           
        }
// Check if you win during the calculation process.  
        if (result == targetNumber){
            cout << endl;
            cout << "You win!";
            break;
        }
// Print you lose at the last calculation
// and you don't meet the target number.
        if ((i == 4) && (result != targetNumber)){          
            cout << endl;
            cout << "You lose.";
            break;           
        }
// Call the function replaceNumberByZero() to replace 
// the used numbers after each calculation.
        replaceNumberByZero(firstNum);
        replaceNumberByZero(secondNum);

// Call the function replaceZeroByResult() to insert 
// the result of calculaion to number sequence.
        replaceZeroByResult(result);
        cout << endl;
        
        cout << "Your numbers are: ";

// Call the function displayNumberSequence() to print out
// the new number sequnence after each calculation.   
        displayNumberSequence();
        cout << endl;
        cout << "The target is: " << targetNumber << endl;

        i++ ;
    } 
}

int chooseRandomNumber(int min, int max) {
	return rand_u32() % (max + 1 - min) + min;
}

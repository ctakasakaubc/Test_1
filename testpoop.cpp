#include <iostream>
#include <string>

using namespace std;

void isPrime(int userNumber){
    if(userNumber > 100){
        cout << "Your number is too big to waste time figuring out if it's prime";
    }else{
        bool isPrime = true; // duh
        int i; // factor iterator

        if(userNumber == 0 || userNumber == 1)
            isPrime = false;
        else{
            for(i = 2; i <= userNumber/2; i++){ // check factors up to userNumber/2
                if(userNumber % i == 0){ // if mod of userNumber and factor is 0, then not prime for sure
                    isPrime = false;
                    break;
                }
            }
        }
        if(isPrime)
            cout << "That's a prime number right there";
        else
            cout << "That's no prime number";
    }
}

void enteredInteger(int userNumber){
    cout<<"You entered an Integer\n";
    isPrime(userNumber);
}

void enteredString(string test){
    string reverse;
    for(int i=test.length();i>=0;i--){
        reverse.push_back(test[i]);
    }
    cout<<reverse;
}

int main() {

    string userString; // will hold initial user input
    int userNumber = -1; // this will be used if the user has an integer in their input (random int to reduce likelihood of user choosing it and bugging)
    bool isInt = false;

    cout << "Type something in: "; // ask user for any single word or number input
    cin >> userString; // store user input in the given variable
    
    try{
        int testNum = std::stoi(userString); // try to parse some integer from the user's string
        if(to_string(testNum).length() == userString.length()){
            userNumber = testNum;
            isInt = true;
        }
    }catch(...){}

    // isInt will be true if the user's input was an integer
    if(isInt){
        enteredInteger(userNumber); // called if the input is an integer
    }else{
        enteredString(userString); // called if the input is a string
    }

    return 0;
}

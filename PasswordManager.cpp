 /********************************************
 * PasswordManager.cpp
 *
 * Gabriel Carpio
 * October 21, 2015
 * CS2308-002 - Project #4
 *
 * File Description:  The following file holds
 * the functions for the PasswordManager class.
 *
 ********************************************/

#include <fstream>
#include <sstream>
#include "PasswordManager.h"

using namespace std;

  // private member functions

  string PasswordManager::encrypt(string input) const {
    string encryptedPassword;
    int inputSize = input.length();
    for (int i = 0; i <= inputSize; i++) {
      encryptedPassword += (input[i] ^ 26);
    }
    return encryptedPassword;
  }

  bool PasswordManager::validatePassword(string input) const {
    // Length checked here.
    int checkLength = 0;
    int inputSize = input.length();
    if(inputSize >= 8)
        checkLength = 1;

    //Checking for uppercase letter.
    int checkUp;
    char letter;
    for (int i = 0; i <= inputSize; i++){
        letter = input[i];
        if(isupper(letter)){
            checkUp=1;
            break;
        }
        else
            checkUp=0;
    }

    // Checking lowercase letter.
    int checkDown;
    for (int i = 0; i <= inputSize; i++){
        letter = input[i];
        if(isupper(letter)){
            checkDown=1;
            break;
        }
        else
            checkDown=0;
    }

    // Checking for digit
    int checkDigit;
    for (int i = 0; i <= inputSize; i++){
        letter = input[i];
        if(isdigit(letter)){
            checkDigit=1;
            break;
        }
        else
            checkDigit=0;
    }

    // Checking for symbol character
    int checkSymbol;
    for (int i = 0; i <= inputSize; i++){
        letter = input[i];
        if(ispunct(letter)){
            checkSymbol=1;
            break;
        }
        else
            checkSymbol=0;
    }

    if(checkLength == 1 && checkUp == 1 && checkDown == 1 && checkDigit == 1 && checkSymbol == 1)
      return true;
    else
      return false;
    }


  // public member functions

  // accessors
  string PasswordManager::getEncryptedPassword() const{
    return password;
  }

  // mutators
  bool PasswordManager::setNewPassword(string input){
    if (validatePassword(input)){
      password = encrypt(input);
      return true;
    }
    else
      return false;
  }

  bool PasswordManager::checkPassword(string input) const{
    string testPassword = encrypt(input);
    if (testPassword == password)
      return true;
    else
      return false;
  }

  bool PasswordManager::storeEncryptedPassword(string inputFileName) const {
    ofstream fOut;
    fOut.open(inputFileName.c_str());
    fOut << password;
    fOut.close();
    return true;
  }

  bool PasswordManager::loadEncryptedPassword(string inputFilename){
    ifstream fIn;
    fIn.open(inputFilename.c_str());
    fIn >> password;
    fIn.close();
    return true;
  }

 /********************************************
 * PasswordDriver.cpp
 *
 * Gabriel Carpio
 * October 21, 2015
 * CS2308-002 - Project #4
 *
 * File Description: The following driver conducts 10 tests that calls on public
 * functions from the PasswordManager class with specific input data to test the
 * functionality of each function.
 *
 * Changes to Submitted Test Plan:
 * I misunderstood the rules for the test plan and included private functions
 * in my submitted plan. Once I realized private functions did not need to be tested and
 * could not be tested outside of their class, I removed them from the test plan and
 * added the correct tests.
 *
 ********************************************/

#include <iostream>
#include <sstream>
#include "PasswordManager.h"
using namespace std;

int main() {
   PasswordManager test;

  // Test #1
  cout << "Test Case #1: getEncryptedPassword (with uninitiated member variable) " << endl;
  cout << "Test data: empty string " << endl;
  cout << "Expected Output: "  << endl;
  cout << "Actual Results : " << test.getEncryptedPassword()  << endl << endl;

  // Test #2:
  cout << "Test Case #2: setNewPassword " << endl;
  cout << "Test data:  H3llo Univ3rs3! " << endl;
  cout << "Expected Output: 1 (true) "  << endl;
  cout << "Actual Results : " << test.setNewPassword("H3llo Univ3rs3!")  << endl << endl;

  // Test #3:
  cout << "Test Case #3: getEncryptedPassword (with a correct password). " << endl;
  cout << "Test data: H3llo Galaxy! " << endl;
  test.setNewPassword("H3llo Galaxy!");
  cout << "Expected Output: Encrypted value of password "  << endl;
  cout << "Actual Results : " << test.getEncryptedPassword()  << endl << endl;

  // Test #4:
  cout << "Test Case #4: setNewPassword (with incorrect password - too short) " << endl;
  cout << "Test data:  Yo Yo Yo! " << endl;
  cout << "Expected Output: 0 (false) "  << endl;
  cout << "Actual Results : " << test.setNewPassword("Yo Yo Yo!")  << endl << endl;

  // Test #5:
  cout << "Test Case #5: setNewPassword (with incorrect password - no digit) " << endl;
  cout << "Test data:  Cr@p cak3s! " << endl;
  cout << "Expected Output: 0 (false) "  << endl;
  cout << "Actual Results : " << test.setNewPassword("Cr@p cak3s!")  << endl << endl;

  // Test #6:
  cout << "Test Case #6: checkPassword (H3llo Univ3rs3! as correct password)" << endl;
  test.setNewPassword("H3llo Univ3rs3!");
  cout << "Test data: H3llo Univ3rs3!  (correct)" << endl;
  cout << "Expected Output: 1 (true) "  << endl;
  cout << "Actual Results : " << test.checkPassword("H3llo Univ3rs3!")  << endl << endl;

  // Test #7:
  cout << "Test Case #7: checkPassword (H3llo Univ3rs3! as correct password)" << endl;
  test.setNewPassword("H3llo Univ3rs3!");
  cout << "Test data: Err! (Incorrect)" << endl;
  cout << "Expected Output: 0 (false) "  << endl;
  cout << "Actual Results : " << test.checkPassword("Err")  << endl << endl;

  // Test #8:
  cout << "Test:Case #8; storeEncryptedPassword " << endl;
  test.setNewPassword("H3llo Univ3rs3!");
  cout << "Test data: H3llo Univ3rs3! (encrypted) " << endl;
  cout << "Expected Output: " << test.getEncryptedPassword()  << endl;
  test.storeEncryptedPassword("file");
  test.loadEncryptedPassword("file");
  cout << "Actual Results : " << test.getEncryptedPassword()  << endl << endl;

  // Test #9:
  cout << "Test Case #9: loadEncryptedPassword " << endl;
  test.setNewPassword("H3llo Univ3rs3!");
  cout << "Test data: H3llo Univ3rs3! (encrypted) " << endl;
  cout << "Expected Output: " << test.getEncryptedPassword()  << endl;
  test.storeEncryptedPassword("file");
  test.loadEncryptedPassword("file");
  cout << "Actual Results : " << test.getEncryptedPassword()  << endl << endl;

  // Test #10:
  cout << "Test Case #10: setNewPassword (with incorrect password - no uppercase) " << endl;
  cout << "Test data:  noupp3rcase! " << endl;
  cout << "Expected Output: 0 (false) "  << endl;
  cout << "Actual Results : " << test.setNewPassword("noupp3rcase!")  << endl << endl;

  return 0;
}



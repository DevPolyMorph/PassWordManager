 /********************************************
 * PasswordManager.h
 *
 * Gabriel Carpio
 * October 21, 2015
 * CS2308-002 - Project #4
 *
 * File Description:  The following file holds the
 * class declaration for the class PasswordManager.
 *
 ********************************************/

using namespace std;

class PasswordManager{
  private:
    string password;

    string encrypt(string) const;
    bool validatePassword(string) const;

  public:

    // accessors
    string getEncryptedPassword() const;

    // mutators
    bool setNewPassword(string);
    bool checkPassword(string) const;
    bool storeEncryptedPassword(string) const;
    bool loadEncryptedPassword(string);

 };

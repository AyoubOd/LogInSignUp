#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void signUp()
{
    string username, password, un;

    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    ofstream signup(username + ".txt");
    if (signup.is_open())
    {
        signup << username << endl;
        signup << password << endl;
        cout << "your sign up was completed seccusfully.\n";
    }

    else
    {
        cerr << "an error was occured!, please try again later.\n";
    }

    signup.close();
}

void logIn()
{
    string username, password, un, pass;

    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    ifstream login(username + ".txt");
    if (login.is_open())
    {

        while (!login.eof())
        {
            login >> un >> pass;
            if (un == username && pass == password)
            {
                cout << "Hello " << username << endl;
                break;
            }
            else
            {
                cout << "the password or the username is incorrect,please try again." << endl;
                logIn();
            }
        }
    }
}

int main()
{
    int Input;
    do
    {
        cout << "to sign up enter: 1" << endl;
        cout << "to log in enter: 2" << endl;
        cout << "to quit enter: 0" << endl;
        cin >> Input;
        switch (Input)
        {
        case (1):
            signUp();
            break;

        case (2):
            logIn();
            break;
        }
        cout << endl;
    } while (Input != 0);
    system("pause");
}
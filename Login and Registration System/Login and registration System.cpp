#include <bits/stdc++.h> // Login and Registration System
using namespace std;

// Function prototypes
void registerNewUser();         // Function to register a new user
bool isValidEmail(string);       // Function to check the validity of an email address
bool isValidFirstName(string);   // Function to check the validity of a first name
bool isValidLastName(string);    // Function to check the validity of a last name
bool isValidPassword(string);     // Function to check the validity of a password
void sendVerificationCode();     // Function to send a verification code
void loginUser();                // Function to log in a user

// Main function
int main()
{
    cout << "Hello there!" << endl;
	cout << "Welcome to our platform!" << endl;
	cout << "Let's embark on this journey together.." << endl << endl;

    // Start the registration process
    registerNewUser();

    return 0;
}

// Function to register a new user
void registerNewUser()
{
    string newUser, username, password, firstName, lastName, email;

    // Ask the user if they are a new user
    cout << "Are you a new user?\n(Note: Type Yes if you are a new user otherwise, type No) \n";
    cin >> newUser;

    if (newUser == "Yes" || newUser == "yes")
    {
        // Collect user information
        cout << "First name : ";
        cin >> firstName;
        while (!isValidFirstName(firstName))
        {
            cout << "Please try again. The first name is not valid.  : " << endl;
            cin >> firstName;
        }
        cout << endl << "First Name is Valid." << endl << endl;

        cout << "Last name : ";
        cin >> lastName;
        while (!isValidLastName(lastName))
        {
            cout << " Please try again. The last name is not valid. : " << endl;
            cin >> lastName;
        }
        cout << endl << "Last Name is Valid." << endl << endl;

        cout << "Email : ";
        cin >> email;
        while (!isValidEmail(email))
        {
            cout << "Please try again.The email address is not valid.  : " << endl;
            cin >> email;
        }
        cout << endl << "Valid email address." << endl << endl;

        cout << "Password : \n(Note: your password must contain at least one digit, one special character, one uppercase letter, and one lowercase letter) \n";
        cin >> password;
        while (!isValidPassword(password))
        {
            cout << "Please try again.The password is not valid. : " << endl;
            cin >> password;
        }
        cout << endl << "Valid password." << endl << endl;

        // Registration completed, send verification code
        cout << "Registration completed! \n" << endl;
        sendVerificationCode();
    }
    else if (newUser == "No" || newUser == "no")
    {
        // User already has an account, proceed to login
        loginUser();
    }
}

// Function to check the validity of a first name
bool isValidFirstName(string firstName)
{
    return (firstName[0] >= 'A' && firstName[0] <= 'Z');
}

// Function to check the validity of a last name
bool isValidLastName(string lastName)
{
    return (lastName[0] >= 'A' && lastName[0] <= 'Z');
}

// Function to check the validity of an email address
bool isValidEmail(string email)
{
    int AT = -1, dot = -1;
    int counterforAT = 0, counterforDot = 0;

    if ((email[0] >= 'a' && email[0] <= 'z') || (email[0] >= 'A' && email[0] <= 'Z'))
    {
        for (int i = 0; i < email.length(); i++)
        {
            if (email[i] == '@')
            {
                AT = i;
                ++counterforAT;
            }
            else if (email[i] == '.')
            {
                dot = i;
                ++counterforDot;
            }
        }

        if (AT == -1 || dot == -1)
            return false;

        if (AT > dot)
            return false;

        if (counterforDot > 1 || counterforAT > 1)
            return false;

        return !(dot >= (email.length() - 1));
    }
    else if (email[0] >= '0' && email[0] <= '9')
    {
        return false;
    }
    else
    {
        return false;
    }
}

// Function to check the validity of a password
bool isValidPassword(string password)
{
    int digit = 0, uppercase = 0, lowercase = 0, specialchar = 0;

    if (password.length() >= 8 && password.length() <= 15)
    {
        if (password.find(" ") == -1)
        {
            for (int i = 0; i < password.length(); i++)
            {
                if (password[i] >= '0' && password[i] <= '9')
                {
                    ++digit;
                }
                else if (password[i] >= 'a' && password[i] <= 'z')
                {
                    ++lowercase;
                }
                else if (password[i] >= 'A' && password[i] <= 'Z')
                {
                    ++uppercase;
                }
                else if (password[i] == '@' || password[i] == '#' || password[i] == '_')
                {
                    ++specialchar;
                }
            }

            if (digit == 0 || uppercase == 0 || lowercase == 0 || specialchar == 0)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else if (password.find(" ") != -1)
        {
            return false;
        }
    }

    cout << "Note: Your password length should be between 8 and 15 characters." << endl;
    return false;
}

// Function to send a verification code
void sendVerificationCode()
{
    int code;

    cout << "We've dispatched a confirmation code to your email for account verification." << endl
         << "Please check your email." << endl;

    cout << "Email message: Your verification code is  ";

    srand(time(0));
    for (int i = 0; i <= 3; i++)
    {
        cout << rand() % 10;
    }
    cout << "\n";

    cout << "Enter the verification code here : \n";
    cin >> code;

    cout << "Your account has been verified." << endl;
    loginUser();
}

// Function to log in a user
void loginUser()
{
    string username, password;

    cin.ignore();
    cout << endl << "     Log in       " << endl << endl;
    cout << "Enter your username :" << endl;
    getline(cin, username);

    cout << "Enter your password :" << endl;
    cin >> password;

    cout << endl << "Login success!" << endl;
}


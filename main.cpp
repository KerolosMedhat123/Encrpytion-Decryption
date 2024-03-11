// File: CS112_A2_T2_S25_20230582_20231233_20230349.cpp
// Purpose: This is a message encrpytion and decryption program using Atbash Cipher,Vignere Cipher
// or Rail_fence Cipher depending on the user's choice.
// Section: S25
//                           Name                           ID              Cipher                  Email
// Author_1:     Kerolos Medhat Malakhy Nakhnokh        (20231233):      Vignere Cipher(3)      kerolosm117@gmail.com
// Author_2:     Yousef Tamer Zaki Mohamed              (20230582):      Atbash Cipher(2)       yousef9tamer@gmail.com            
// Author_3:     Mohamed Kamal Ahmed                    (20230349):      Rail_fence Cipher(9)   elkpir666@gmail.com               



#include<iostream>
#include<string>
#include <cctype>
#include<vector>
#include<algorithm>
#define endl "\n"
#define all(v)  v.begin() ,v.end()
using namespace std;


void Atbash_Cipher();
void vignere_Encrypt();
void vignere_Decrypt();
void Rail_fence(int choice);


int main() {
    // Display welcome message
    cout << "Welcome to message cipher and decipher program." << endl;

    // Main program loop
    while (true) {
        // Display options to the user
        cout << "What do you want to do?" << endl;
        cout << "1-Cipher a message" << endl << "2-Decipher a message" << endl << "3-Exit" << endl << endl;
        string user_choice1;
        cout << "Please enter a number from 1 to 3" << endl;
        cin >> user_choice1;

        // Validate user input for the main menu
        while (true) {
            if (user_choice1 != "1" && user_choice1 != "2" && user_choice1 != "3") {
                cout << "Invalid choice. Please enter a number from 1 to 3" << endl;
                cin >> user_choice1;
            }
            else break;
        }

        // Cipher a message
        if (user_choice1 == "1") {
            cout << endl;
            string user_choice2;
            cout << "Which Cipher do you want to use?" << endl << "1-Atbash Cipher" << endl << "2-Vignere Cipher" << endl << "3-Rail-fence Cipher" << endl;
            cin >> user_choice2;

            // Validate user input for cipher selection
            while (true) {
                if (user_choice2 != "1" && user_choice2 != "2" && user_choice2 != "3") {
                    cout << "Invalid choice. Please enter a number from 1 to 3" << endl;
                    cin >> user_choice2;
                }
                else break;
            }
            cout << endl;

            // Perform selected cipher operation
            if (user_choice2 == "1") {
                Atbash_Cipher();
                cout << endl;
            }
            else if (user_choice2 == "2") {
                vignere_Encrypt();
                cout << endl;
            }
            else if (user_choice2 == "3") {
                Rail_fence(1);
                cout << endl;
            }

        }

        // Decipher a message
        if (user_choice1 == "2") {
            cout << endl;
            string user_choice2;
            cout << "Which Decipher do you want to use?" << endl << "1-Atbash Decipher" << endl << "2-Vignere Decipher" << endl << "3-Rail-fence Decipher" << endl;
            cin >> user_choice2;
            // Validate user input for decipher selection
            while (true) {
                if (user_choice2 != "1" && user_choice2 != "2" && user_choice2 != "3") {
                    cout << "Invalid choice. Please enter a number from 1 to 3" << endl;
                    cin >> user_choice2;
                }
                else break;
            }
            cout << endl;

            // Perform selected decipher operation
            if (user_choice2 == "1") {
                Atbash_Cipher();
                cout << endl;
            }
            else if (user_choice2 == "2") {
                vignere_Decrypt();
                cout << endl;
            }
            else if (user_choice2 == "3") {
                Rail_fence(2);
                cout << endl;
            }
        }

        // Exit the program
        if (user_choice1 == "3") {
            break;
        }
    }
    return 0;
}

// Function to encrypt or decrypt a message using Atbash cipher
void Atbash_Cipher()
{
    string user_choice3; // Variable to store user's choice for type of Atbash cipher
    cout << "1-Use the whole alphabet" << endl << "2-Divide the alphabet into 2 groups" << endl;
    cin >> user_choice3; // Taking user's choice

    // Validation loop to ensure user enters a valid choice
    while (true)
    {
        if (user_choice3 != "1" and user_choice3 != "2")
        {
            cout << "Invalid choice. Please enter 1 or 2" << endl;
            cin >> user_choice3;
        }
        else
            break; // Break the loop if the choice is valid
    }
    cout << endl;

    if (user_choice3 == "1")
    {
        string msg, y, output; // Variables to store user's message, processed message, and output
        cin.ignore(); // Ignore any remaining characters in the input buffer
        cout << "Enter the message: ";
        getline(cin, msg); // Allowing input of a full line including spaces

        // Convert the message to uppercase and remove non-alphabetic characters
        for (char character : msg)
        {
            if (isalpha(character))
            {
                y = y + char(toupper(character));
            }
        }

        // Atbash encryption for whole alphabet
        for (char character : y)
        {
            // Atbash transformation: Replace each letter with its corresponding opposite in the alphabet
            output += char(int(character) + 25 - 2 * (int(character) - 65)); // ASCII manipulation for encryption
        }
        cout << "The output message is: " << output << endl; // Output the encrypted message
    }

    if (user_choice3 == "2")
    {
        string msg, y, output; // Variables to store user's message, processed message, and output
        cin.ignore(); // Ignore any remaining characters in the input buffer
        cout << "Enter the message: ";
        getline(cin, msg); // Allowing input of a full line including spaces

        // Convert the message to uppercase and remove non-alphabetic characters
        for (char character : msg)
        {
            if (isalpha(character))
            {
                y = y + char(toupper(character));
            }
        }

        // Atbash encryption for alphabet divided into two groups
        for (char character : y)
        {
            if (int(character) >= 65 and int(character) <= 77) // First group of alphabet
            {
                // Atbash transformation: Replace each letter with its corresponding opposite in the first group
                output += char(int(character) + 12 - 2 * (int(character) - 65)); // ASCII manipulation for encryption
            }
            if (int(character) >= 78 and int(character) <= 90) // Second group of alphabet
            {
                // Atbash transformation: Replace each letter with its corresponding opposite in the second group
                output += char(int(character) + 12 - 2 * (int(character) - 78)); // ASCII manipulation for encryption
            }
        }
        cout << "The output message is: " << output << endl; // Output the encrypted message
    }
}

// Function to encrypt a message using Vigenere cipher
void vignere_Encrypt() {
    // Declare variables to store message and keyword
    string message, keyword;

    // Prompt user to enter message (up to 80 characters) and keyword (up to 8 characters)
    cin.ignore();
    cout << "Enter the message (up to 80 characters): ";
    getline(cin, message);
    cout << "Enter the keyword (up to 8 characters): ";
    getline(cin, keyword);

    // Check if message or keyword exceeds length limit
    while (message.length() > 80 || keyword.length() > 8) {
        cout << "Message or keyword exceeds the length limit." << endl;
        cout << "Enter the message (up to 80 characters): ";
        getline(cin, message);
        cout << "Enter the keyword (up to 8 characters): ";
        getline(cin, keyword);
    }

    // Declare variable to store encrypted message
    string encryptedMessage;
    // Initialize index for keyword
    int keywordIndex = 0;

    // Convert message to uppercase
    for (char& ch : message) {
        if (isalpha(ch))
            ch = toupper(ch);
    }

    // Convert keyword to uppercase
    for (char& ch : keyword) {
        ch = toupper(ch);
    }

    // Extend the keyword to match the length of the message
    while (keyword.length() < message.length()) {
        keyword += keyword[keywordIndex++];
        keywordIndex %= keyword.length();
    }

    // Encrypt the message using the Vigenere cipher
    for (int i = 0; i < message.length(); i++) {
        char ch = message[i];
        if (isalpha(ch)) {
            // Calculate the shift value based on the corresponding character in the keyword
            char keywordChar = keyword[i];
            int shift = (keywordChar - 'A') % 26;
            // Apply the Vigenere encryption formula
            ch = ((ch - 'A' + shift) % 26) + 'A';
        }
        // Append the encrypted character to the encrypted message
        encryptedMessage += ch;
    }

    // Output the encrypted message
    cout << "Encrypted message: " << encryptedMessage << endl;
}

// Function to decrypt a message encrypted using Vigenere cipher
void vignere_Decrypt() {
    // Declare variables to store encrypted message and keyword
    string encryptedMessage, keyword;

    // Prompt user to enter encrypted message (up to 80 characters) and keyword (up to 8 characters)
    cin.ignore();
    cout << "Enter the message (up to 80 characters): ";
    getline(cin, encryptedMessage);
    cout << "Enter the keyword (up to 8 characters): ";
    getline(cin, keyword);

    // Check if encrypted message or keyword exceeds length limit
    while (encryptedMessage.length() > 80 || keyword.length() > 8) {
        cout << "Message or keyword exceeds the length limit." << endl;
            cout << "Enter the message (up to 80 characters): ";
            getline(cin, encryptedMessage);
            cout << "Enter the keyword (up to 8 characters): ";
            getline(cin, keyword);
    }

    // Declare variable to store decrypted message
    string decryptedMessage = "";
    // Initialize index for keyword
    int keywordIndex = 0;

    // Convert keyword to uppercase
    for (char& ch : keyword)
        ch = toupper(ch);

    // Extend the keyword to match the length of the encrypted message
    while (keyword.length() < encryptedMessage.length()) {
        keyword += keyword[keywordIndex++];
        keywordIndex %= keyword.length();
    }

    // Decrypt the message using the Vigenere cipher
    for (int i = 0; i < encryptedMessage.length(); i++) {
        char ch = encryptedMessage[i];
        if (isalpha(ch)) {
            // Calculate the shift value based on the corresponding character in the keyword
            char keywordChar = keyword[i];
            int shift = (keywordChar - 'A') % 26;
            // Apply the Vigenere decryption formula
            ch = ((ch - 'A' - shift + 26) % 26) + 'A';
        }
        // Append the decrypted character to the decrypted message
        decryptedMessage += ch;
    }

    // Output the decrypted message
    cout << "Decrypted message: " << decryptedMessage << endl;
}

// Function to perform Rail Fence cipher encryption or decryption based on the choice provided
void Rail_fence(int choice) {
    int key;
    string s;

    // Ignore any previous input
    cin.ignore();

    // Perform encryption
    if (choice == 1) {
        cout << "Please enter the message to cipher : " << endl;
        getline(cin, s);
        // Calculate the size of the message excluding spaces
        int size = s.size() - count(all(s), ' ');
        // Remove spaces from the message
        remove(all(s), ' ');

        cout << "Please enter the Key : ";
        cin >> key;

        // Validate the key
        while (!(key <= size / 2)) {
            cout << "Please enter a valid Key : ";
            cin >> key;
        }

        // Vector to store rail fence pattern
        vector<string> v(key, "");

        // Initialize variables for traversing the rail fence
        int x = 0;
        bool flag = 1;

        // Fill the rail fence pattern
        for (int i = 0; i < size; i++) {
            v[x] += s[i];
            if (flag)
                x++;
            else
                x--;
            if (x == 0 || x == key - 1)
                flag = !flag;
        }

        // Output the cipher text
        cout << "Cipher text : ";
        for (int i = 0; i < key; i++) {
            cout << v[i];
        }
        cout << endl;
    }
    // Perform decryption
    else if (choice == 2) {
        cout << "Please enter the cipher text : " << endl;
        cin >> s;
        cout << "Please enter the Key : ";
        cin >> key;

        // Validate the key
        while (!(key <= s.size() / 2)) {
            cout << "Please enter a valid Key : ";
            cin >> key;
        }

        // Vector to represent the rail fence pattern
        vector<vector<char>> v(key, vector<char>(s.size(), '.'));

        string ans = "";
        bool flag = 0;
        int x = 0, y = 0;

        // Fill the rail fence pattern with spaces to represent the position of characters
        for (int i = 0; i < s.size(); i++) {
            if (x == 0)
                flag = 1;
            else if (x == key - 1)
                flag = 0;
            v[x][y] = ' ';
            y++;
            if (flag)
                x++;
            else
                x--;
        }

        // Fill the rail fence pattern with characters
        int position = 0;
        for (int i = 0; i < key; i++) {
            for (int j = 0; j < s.size(); j++) {
                if (v[i][j] == ' ') {
                    if (position < s.size()) {
                        v[i][j] = s[position];
                        position++;
                    }
                }
            }
        }

        x = 0; y = 0;
        for (int i = 0; i < s.size(); i++) {
            if (x == 0)
                flag = 1;
            else if (x == key - 1)
                flag = 0;
            if (v[x][y] != '.')
                ans += v[x][y++];
            if (flag)
                x++;
            else
                x--;
        }
        // Output the decrypted message
        cout << "Cipher text is : " << ans << endl;
    }
}

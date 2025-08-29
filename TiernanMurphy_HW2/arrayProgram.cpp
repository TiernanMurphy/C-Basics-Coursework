#include "arrayProgram.h"

void runProgram() {
    const string FILE_NAME = "data.dat";
    const int ARRAY_LENGTH = 7;
    int arr[ARRAY_LENGTH];
    bool run = true; // loop for user input
    readFromFile(FILE_NAME, arr, ARRAY_LENGTH); // reads 'data.dat' into array
    while(run == true) {
        printMenu();
        int userChoice = getUserChoice(); // gets and calls function based on user input
        if(userChoice == 1) {
            printArray(arr, ARRAY_LENGTH);
        }
        else if(userChoice == 2) {
            printArrayChars(arr, ARRAY_LENGTH);
        }
        else if(userChoice == 3) {
            printMemoryMap(arr, ARRAY_LENGTH);
        }
        else if(userChoice == 4) {
            cout << "Exiting program...\n"; // breaks while loop
            run = false;
        }
        else {
            cout << "please enter one of the available options\n";
        }
        }
    }

// prints four menu options
void printMenu() {
    cout << "-------------------------------------\n"
            "Program Options:\n"
            "-------------------------------------\n"
            "1. Print the array\n2. Print the array as chars\n3. Print memory map\n4. Exit\n";
}

// get user's choice, send to runProgram()
int getUserChoice() {
    string input;
    int userChoice;
    while(true) {
        cout << "Enter a choice: ";
        getline(cin, input);
        try {
            userChoice = stoi(input);
            return userChoice;
        }
        catch (const invalid_argument& e) {
            cout << "--Error: Invalid choice! try again.\n";
        }
        catch (const out_of_range& e) {
            cout << "--Error: Invalid choice! try again.\n";
        }
    }
}

// read data.dat into array
void readFromFile(const string FILE_NAME, int arr[], const int ARRAY_LENGTH) {
    // open file
    ifstream iFile;
    iFile.open(FILE_NAME);
    // check if successfully opened
    cout << "--------------File Read--------------\n"
            "--Reading from file: \"data.dat\"\n";
    if(iFile) {
        cout << "--Successfully read 7 values from file.\n"
                "-------------------------------------\n";
    }
    else {
        cout << "--Failed to read from \"data.dat\".\n"
                "-------------------------------------\n";
    }
    // store numbers in array
    int num = 0;
    string line;
    for(int i = 0; i < 7; i++) {
        getline(iFile, line);
        num = stoi(line);
        arr[i] = num;
        }
    // close file
    iFile.close();
}

// first option for user
void printArray(int * arr, const int ARRAY_LENGTH) {
    for(int i = 0; i < ARRAY_LENGTH; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// second option for user
void printArrayChars(int * arr, const int ARRAY_LENGTH) {
    for(int i = 0; i < ARRAY_LENGTH; i++) {
        int key = arr[i];
        int * ptr = &key;
        char value = static_cast<char>(*ptr);
        cout << value << " ";
    }
    cout << endl;
}

// third option for user
void printMemoryMap(int * arr, const int ARRAY_LENGTH) {
    cout << "ptr address --> address of value | value\n\n";
    for(int i = 0; i < ARRAY_LENGTH; i++) {
        int * initialPtr = &arr[0];
        int * currentPtr = &arr[i];
        cout << initialPtr << " --> " << currentPtr << " | " <<arr[i] << endl;
    }
}
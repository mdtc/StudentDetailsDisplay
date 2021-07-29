#include <iostream>
#include <string>
#include <fstream>
#include <thread>

using namespace std;
//using namespace this_thread;

//Declaring the struct 
//and the name and space of the array 
struct record{
    string name;
    int age;
    string ID;
    string program;
}newRecords[2];



//This functions get the data from the users 
string getName(){

    string newName;

    cout << "\n" << "Please enter student name: " << endl;
    cin >> newName;

    return newName;
}

int getAge(){

    int newAge;

    cout << "Please enter student age: " << endl;
    cin >> newAge;

    return newAge;
}

string getID(){

    string newID;

    cout << "Please enter student ID: " << endl;
    cin >> newID;

    return newID;
}

string getProgram(){

    string newProgram;

    cout << "Please enter student program: " << endl;
    cin >> newProgram;

    return newProgram;
}


//Creating the variable to populate the new strcuture with the data from the users 
record recordCreate(){

    record NewStd;
    NewStd.name = getName();
    NewStd.age = getAge();
    NewStd.ID = getID();
    NewStd.program = getProgram();

    return NewStd;

};

// function to print out the data obtained  from the struct 


void printRecord(record NewStd){

    cout << "\n" << "Your information is: " << "\n" << endl;
    cout << NewStd.name << endl;
    cout << NewStd.age << endl;
    cout << NewStd.ID << endl;
    cout << NewStd.program << endl;


};


//Calling the variable into the main function.

int main(){

    //This loop asks for the data to the user and save it into the array 
    for(int i = 0; i <= 2; i++){   
        
        record NewS = recordCreate();
        newRecords[i] = NewS;
        printRecord(newRecords[i]);
    };

    ofstream fileTxt("USQRecords.txt");

    cout << "\n" "The content of the array is: " << endl;
    
    for(int i = 0; i <=2; i++){

    cout << "\n" "Student " << i + 1 << endl;    
    fileTxt << "\n" << "Student " << i + 1 << endl;  
    cout << newRecords[i].name << endl;
    fileTxt << newRecords[i].name << endl;
    cout << newRecords[i].age << endl;
    fileTxt << newRecords[i].age << endl;
    cout << newRecords[i].ID << endl;
    fileTxt << newRecords[i].ID << endl;
    cout << newRecords[i].program << endl;
    fileTxt << newRecords[i].program <<endl;
   
    };

    fileTxt.close();

    ifstream MyFile("USQRecords.txt");
    cout << "\n" << "Savind data into USQRecord.txt ...." << endl;
    //sleep_for(50000ns);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    cout << "\n" << "USQRecord.txt created" << endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    cout << "\n" << "Opening and reading file...." << endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    //sleep_for(30000ns);

    string textFromFile;

    cout << "\n" "The content of the document is: " << endl << "\n";

    while(getline(MyFile, textFromFile)){
        cout << textFromFile << endl;
    };

    MyFile.close();





 
    
    return 0;
    
};


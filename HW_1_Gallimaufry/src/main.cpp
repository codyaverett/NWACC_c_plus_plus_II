#include <iostream>
#include <fstream>

#include "service.h";

using namespace std;

const string INPUT_FILE = "results.csv";
const string OUT_DIR = "../dist/";

void write_file( string file_name ) {
    ofstream file;

    try {
        file.open( file_name, ios_base::out);

        if(file.is_open()) {
            cout << "File Opened successfully" << endl;
            file << "Text" << endl;
            file << "text 2" << endl;
            cout << "Finished writing to file" << endl;
            file.close();
        } else {
            throw "Could not open file: " + file_name; 
        }
        
    } catch(string error) {
        cout << "ERROR: " + error << endl;
    }
}

void read_file( string file_name ) {
    ifstream file;
    file.open(file_name, ios_base::in);

    try {
        if(file.is_open()) {
            cout << "file opened" << endl;
            string fileContents;

            while(file.good()) {
                getline(file, fileContents);
                cout << fileContents << endl;
            }
        } else {
            throw "Could not open file: " + file_name;
        }
    } catch(string error) {
        cout << "ERROR: " + error << endl;
    }

    cout << "Finished reading file " << endl;
    file.close();
}

int main() {

    write_file(INPUT_FILE);
    read_file(INPUT_FILE);

    const Service my_service = Service("Cody", "Bloop", 84.53, "7/11/2019");

    return 0;
}
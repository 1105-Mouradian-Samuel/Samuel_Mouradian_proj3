//Programming Project 3 - Due 11.30.2023
//Computer Science 219 - Seciton 1001
//Author - Samuel Mouradian
//Version - 1.0


#include <iostream>
#include <fstream>
using namespace std;


#define FILENAME "Programming-Project-2.txt"
#define MAXLINE 40

//Operations:
void ADD_ADDS(ifstream&, char);
void AND_ANDS(ifstream&, char);
void ASR_ASRS(ifstream&, char);
void LSR_LSRS(ifstream&, char);
void LSL_LSLS(ifstream&, char);
void NOT_NOTS(ifstream&, char);
void ORR_ORRS(ifstream&, char);
void SUB_SUBS(ifstream&, char);
void XOR_XORS(ifstream&, char);

int main(){
    ifstream txtFile;
    txtFile.open(FILENAME);

    char e;

    for(int i = 0; i < MAXLINE; i++){
        if(txtFile.good()){
            long int hexVal1, hexVal2;
            string operand;

            txtFile >> operand;

            if(operand == "ADD" || operand == "ADDS"){
                cout << operand;
                ADD_ADDS(txtFile, e);
            }
            else if(operand == "AND" || operand == "ANDS"){
                cout << operand;
                AND_ANDS(txtFile, e);
            }
            else if(operand == "ASR" || operand == "ASRS"){
                cout << operand;
                ASR_ASRS(txtFile, e);
            }
            else if(operand == "LSR" || operand == "LSRS"){
                cout << operand;
                LSR_LSRS(txtFile, e);
            }
            else if(operand == "LSL" || operand == "LSLS"){
                cout << operand;
                LSL_LSLS(txtFile, e);
            }
            else if(operand == "NOT" || operand == "NOTS"){
                cout << operand;
                NOT_NOTS(txtFile, e);
            }
            else if(operand == "ORR" || operand == "ORRS"){
                cout << operand;
                ORR_ORRS(txtFile, e);
            }
            else if(operand == "SUB" || operand == "SUBS"){
                cout << operand;
                SUB_SUBS(txtFile, e);
            }
            else if(operand == "XOR" || operand == "XORS"){
                cout << operand;
                XOR_XORS(txtFile, e);
            }
        }
    }
    txtFile.close();
    return 0;
}

void ADD_ADDS(ifstream& hexFile, char end){
    long int hexVal1, hexVal2;

    hexFile >> hex >> hexVal1;
    hexFile >> hex >> hexVal2;

    cout << "        0x" << hex << hexVal1 << "       0x" << hex << hexVal2 << endl;

    cout << "Result:    0x" << hex << hexVal1 + hexVal2 << endl << endl;
}

void AND_ANDS(ifstream& hexFile, char end){
    long int hexVal1, hexVal2;

    hexFile >> hex >> hexVal1;
    hexFile >> hex >> hexVal2;

    cout << "        0x" << hex << hexVal1 << "       0x" << hex << hexVal2 << endl;

    cout << "Result:    0x" << hex << (hexVal1 & hexVal2) << endl << endl;
}

void ASR_ASRS(ifstream& hexFile, char end){
    long int hexVal1, val1;

    hexFile >> hex >> hexVal1;
    hexFile >> val1;

    cout << "        0x" << hex << hexVal1 << "       " << val1 << endl;

    if(val1 > 1){
        for(int i = 0; i < val1; i++){
            hexVal1 = (hexVal1 >> 1);
        }
        cout << "Result:    0x" << hex << hexVal1 << endl << endl;
    }
    else if(val1 == 1){
        cout << "Result:    0x" << hex << (hexVal1 >> val1) << endl << endl;
    }
}

void LSR_LSRS(ifstream& hexFile, char end){
    long int hexVal1, val1;

    hexFile >> hex >> hexVal1;
    hexFile >> val1;

    cout << "        0x" << hex << hexVal1 << "       " << val1 << endl;

    if(val1 > 1){
        for(int i = 0; i < val1; i++){
            hexVal1 = (hexVal1 >> 1);
        }
        cout << "Result:    0x" << hex << hexVal1 << endl << endl;
    }
    else if(val1 == 1){
        cout << "Result:    0x" << hex << (hexVal1 >> val1) << endl << endl;
    }
}

void LSL_LSLS(ifstream& hexFile, char end){
    long int hexVal1, val1;

    hexFile >> hex >> hexVal1;
    hexFile >> val1;

    cout << "        0x" << hex << hexVal1 << "       " << val1 << endl;

    if(val1 > 1){
        for(int i = 0; i < val1; i++){
            hexVal1 = (hexVal1 << 1);
        }
        cout << "Result:    0x" << hex << hexVal1 << endl << endl;
    }
    else if(val1 == 1){
        cout << "Result:    0x" << hex << (hexVal1 << val1) << endl << endl;
    }
}

void NOT_NOTS(ifstream& hexFile, char end){
    long int hexVal1;

    hexFile >> hex >> hexVal1;

    cout << "        0x" << hex << hexVal1 << endl;

    hexVal1 = hexVal1 - 4294967296;

    cout << "Result:    0x" << hex << ~(hexVal1) << endl << endl;
}

void ORR_ORRS(ifstream& hexFile, char end){
    long int hexVal1, hexVal2;

    hexFile >> hex >> hexVal1;
    hexFile >> hex >> hexVal2;

    cout << "        0x" << hex << hexVal1 << "       0x" << hex << hexVal2 << endl;

    cout << "Result:    0x" << hex << (hexVal1 | hexVal2) << endl << endl;
}

void SUB_SUBS(ifstream& hexFile, char end){
    long int hexVal1, hexVal2;

    hexFile >> hex >> hexVal1;
    hexFile >> hex >> hexVal2;

    cout << "        0x" << hex << hexVal1 << "       0x" << hex << hexVal2 << endl;

    cout << "Result:    0x" << hex << (hexVal1 - hexVal2) << endl << endl;
}

void XOR_XORS(ifstream& hexFile, char end){
    long int hexVal1, hexVal2;

    hexFile >> hex >> hexVal1;
    hexFile >> hex >> hexVal2;

    cout << "        0x" << hex << hexVal1 << "       0x" << hex << hexVal2 << endl;

    cout << "Result:    0x" << hex << (hexVal1 ^ hexVal2) << endl << endl;
}
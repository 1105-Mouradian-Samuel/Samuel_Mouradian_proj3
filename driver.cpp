//Programming Project 3 - Due 11.30.2023
//Computer Science 219 - Seciton 1001
//Author - Samuel Mouradian
//Version - 2.0


#include <iostream>
#include <fstream>
using namespace std;


#define FILENAME "Programming-Project-3.txt"
#define MAXLINE 15

//Operations - Programming Project 2:
void ADD_ADDS(ifstream&, char);
void AND_ANDS(ifstream&, char);
void ASR_ASRS(ifstream&, char);
void LSR_LSRS(ifstream&, char);
void LSL_LSLS(ifstream&, char);
void NOT_NOTS(ifstream&, char);
void ORR_ORRS(ifstream&, char);
void SUB_SUBS(ifstream&, char);
void XOR_XORS(ifstream&, char);


//Operations - Programming Project 3:
void MOV(string, long int, long int, long int, long int, long int, long int, long int, long int, long int, int, int, int, int);

int main(){
    ifstream txtFile;
    txtFile.open(FILENAME);

    char e;
    long int r0, r1, r2, r3, r4, r5, r6, r7;
    int N, Z, C, V;

    for(int i = 0; i < MAXLINE; i++){
        if(txtFile.good()){
            long int hexVal1, hexVal2, movVar;

            string operand, regWrite, regRead, regPull;
            
            int shift;

            txtFile >> operand;

            if(operand == "ADD" || operand == "ADDS" || operand == "add" || operand == "adds"){
                cout << operand;
                txtFile >> regWrite >> regRead >> regPull;
                cout << " " << regWrite << " " << regRead << " " << regPull << endl;

                ADD_ADDS(txtFile, e);
            }
            else if(operand == "AND" || operand == "ANDS" || operand == "and" || operand == "ands"){
                cout << operand;
                txtFile >> regWrite >> regRead >> regPull;
                cout << " " << regWrite << " " << regRead << " " << regPull << endl;

                AND_ANDS(txtFile, e);
            }
            else if(operand == "ASR" || operand == "ASRS" || operand == "asr" || operand == "asrs"){
                cout << operand;
                txtFile >> regWrite >> regRead >> shift;
                cout << " " << regWrite << " " << regRead << " " << shift << endl;

                ASR_ASRS(txtFile, e);
            }
            else if(operand == "LSR" || operand == "LSRS" || operand == "lsr" || operand == "lsrs"){
                cout << operand;
                txtFile >> regWrite >> regRead >> shift;
                cout << " " << regWrite << " " << regRead << " " << shift << endl;

                LSR_LSRS(txtFile, e);
            }
            else if(operand == "LSL" || operand == "LSLS" || operand == "lsl" || operand == "lsls"){
                cout << operand;
                txtFile >> regWrite >> regRead >> shift;
                cout << " " << regWrite << " " << regRead << " " << shift << endl;

                LSL_LSLS(txtFile, e);
            }
            else if(operand == "NOT" || operand == "NOTS" || operand == "not" || operand == "nots"){
                cout << operand << endl;
                NOT_NOTS(txtFile, e);
            }
            else if(operand == "ORR" || operand == "ORRS" || operand == "orr" || operand == "orrs"){
                cout << operand;
                txtFile >> regWrite >> regRead >> regPull;
                cout << " " << regWrite << " " << regRead << " " << regPull << endl;

                ORR_ORRS(txtFile, e);
            }
            else if(operand == "SUB" || operand == "SUBS" || operand == "sub" || operand == "subs"){
                cout << operand;
                txtFile >> regWrite >> regRead >> regPull;
                cout << " " << regWrite << " " << regRead << " " << regPull << endl;

                SUB_SUBS(txtFile, e);
            }
            else if(operand == "XOR" || operand == "XORS" || operand == "xor" || operand == "xors"){
                cout << operand;
                txtFile >> regWrite >> regRead >> regPull;
                cout << " " << regWrite << " " << regRead << " " << regPull << endl;

                XOR_XORS(txtFile, e);
            }
            else if(operand == "MOV" || operand == "mov"){
                cout << operand << " ";
                txtFile >> regWrite >> hex >> movVar;
                cout << regWrite << " " << "0x" << hex << movVar << endl;
                
                if(regWrite == "R0," || regWrite == "r0,"){

                }
                else if(regWrite == "R1," || regWrite == "r1,"){

                }
                else if(regWrite == "R2," || regWrite == "r2,"){

                }
                else if(regWrite == "R3," || regWrite == "r3,"){

                }
                else if(regWrite == "R4," || regWrite == "r4,"){

                }
                else if(regWrite == "R5," || regWrite == "r5,"){

                }
                else if(regWrite == "R6," || regWrite == "r6,"){

                }
                else if(regWrite == "R7," || regWrite == "r7,"){

                }
                MOV(regWrite, movVar, r0, r1, r2, r3, r4, r5, r6, r7, N, Z, C, V);
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
    string r1, r2, r3, r4, r5, r6, r7;

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

void MOV(string writeToReg, long int hexVal, long int reg0, long int reg1, long int reg2, long int reg3, long int reg4, long int reg5, long int reg6, long int reg7, int neg, int zero, int carry, int overflow){
    long int r0, r1, r2, r3, r4, r5, r6, r7;
    int N, Z, C, V;

    if(writeToReg == "R0," || writeToReg == "r0,"){
    }
    else if(writeToReg == "R1," || writeToReg == "r1,"){
    }
    else if(writeToReg == "R2," || writeToReg == "r2,"){
    }
    else if(writeToReg == "R3," || writeToReg == "r3,"){
    }
    else if(writeToReg == "R4," || writeToReg == "r4,"){
    }
    else if(writeToReg == "R5," || writeToReg == "r5,"){
    }
    else if(writeToReg == "R6," || writeToReg == "r6,"){
    }
    else if(writeToReg == "R7," || writeToReg == "r7,"){
    }
}

/*r0 = hexVal;
        r1 = reg1;
        r2 = reg2;
        r3 = reg3;
        r4 = reg4;
        r5 = reg5;
        r6 = reg6;
        r7 = reg7;

        N = neg;
        Z = zero;
        C = carry;
        V = overflow;

        cout << "R0: 0x" << hex << r0 << "  R1: 0x" << hex << r1 << "  R2: 0x" << hex << r2 << "  R3: 0x" << hex << r3 << "  R4: 0x" << hex << r4 << "  R5: 0x";
        cout << hex << r5 << "  R6: 0x" << hex << r6 << "  R7: 0x" << hex << r7 << endl;

        cout << "N = " << N << "  Z = " << Z << "  C = " << C << "  V = " << V << endl << endl;*/
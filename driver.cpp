//Programming Project 3 - Due 11.30.2023
//Computer Science 219 - Seciton 1001
//Author - Samuel Mouradian
//Version - 3.0


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
long int MOV(ifstream&, char);

int main(){
    ifstream txtFile;
    txtFile.open(FILENAME);

    char e;

    for(int i = 0; i < MAXLINE; i++){
        if(txtFile.good()){
            long int hexVal1, hexVal2;
            long int reg0, reg1, reg2, reg3, reg4, reg5, reg6, reg7;

            int flagN, flagZ, flagC, flagV;
            int shift;

            string operand, regWrite, regRead, regPull;

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
                txtFile >> regWrite >> hex >> hexVal1;
                cout << regWrite << " " << "0x" << hex << hexVal1 << endl;

                MOV(txtFile, e);
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

long int MOV(ifstream& hexFile, char end){
    string operand, reg;
    long int hexVal;

    long int r0, r1, r2, r3, r4, r5, r6, r7;

    int N, Z, C, V;


    hexFile >> operand >> reg >> hex >> hexVal;


    if(reg == "R0," || reg == "r0,"){
        r0 = hexVal;

        cout << "R0:0x" << r0 << "  R1:0x" << r1 << "  R2:0x" << r2 << "  R3:0x" << r3 << "  R4:0x" << r4 << "  R5:0x" << r5 << "  R6:0x" << r6 << "  R7:0x" << r7 << endl;
        cout << "N:" << N << "  Z:" << Z << "  C:" << C << "  V:" << V << endl << endl;

    }
    else if(reg == "R1," || reg == "r1,"){
        r1 = hexVal;

        cout << "R0:0x" << r0 << "  R1:0x" << r1 << "  R2:0x" << r2 << "  R3:0x" << r3 << "  R4:0x" << r4 << "  R5:0x" << r5 << "  R6:0x" << r6 << "  R7:0x" << r7 << endl;
        cout << "N:" << N << "  Z:" << Z << "  C:" << C << "  V:" << V << endl << endl;
    }
    else if(reg == "R2," || reg == "r2,"){
        r2 = hexVal;

        cout << "R0:0x" << r0 << "  R1:0x" << r1 << "  R2:0x" << r2 << "  R3:0x" << r3 << "  R4:0x" << r4 << "  R5:0x" << r5 << "  R6:0x" << r6 << "  R7:0x" << r7 << endl;
        cout << "N:" << N << "  Z:" << Z << "  C:" << C << "  V:" << V << endl << endl;
    }
    else if(reg == "R3," || reg == "r3,"){
        r3 = hexVal;

        cout << "R0:0x" << r0 << "  R1:0x" << r1 << "  R2:0x" << r2 << "  R3:0x" << r3 << "  R4:0x" << r4 << "  R5:0x" << r5 << "  R6:0x" << r6 << "  R7:0x" << r7 << endl;
        cout << "N:" << N << "  Z:" << Z << "  C:" << C << "  V:" << V << endl << endl;
    }
    else if(reg == "R4," || reg == "r4,"){
        r4 = hexVal;

        cout << "R0:0x" << r0 << "  R1:0x" << r1 << "  R2:0x" << r2 << "  R3:0x" << r3 << "  R4:0x" << r4 << "  R5:0x" << r5 << "  R6:0x" << r6 << "  R7:0x" << r7 << endl;
        cout << "N:" << N << "  Z:" << Z << "  C:" << C << "  V:" << V << endl << endl;
    }
    else if(reg == "R5," || reg == "r5,"){
        r5 = hexVal;

        cout << "R0:0x" << r0 << "  R1:0x" << r1 << "  R2:0x" << r2 << "  R3:0x" << r3 << "  R4:0x" << r4 << "  R5:0x" << r5 << "  R6:0x" << r6 << "  R7:0x" << r7 << endl;
        cout << "N:" << N << "  Z:" << Z << "  C:" << C << "  V:" << V << endl << endl;
    }
    else if(reg == "R6," || reg == "r6,"){
        r6 = hexVal;

        cout << "R0:0x" << r0 << "  R1:0x" << r1 << "  R2:0x" << r2 << "  R3:0x" << r3 << "  R4:0x" << r4 << "  R5:0x" << r5 << "  R6:0x" << r6 << "  R7:0x" << r7 << endl;
        cout << "N:" << N << "  Z:" << Z << "  C:" << C << "  V:" << V << endl << endl;
    }
    else if(reg == "R7," || reg == "r7,"){
        r7 = hexVal;

        cout << "R0:0x" << r0 << "  R1:0x" << r1 << "  R2:0x" << r2 << "  R3:0x" << r3 << "  R4:0x" << r4 << "  R5:0x" << r5 << "  R6:0x" << r6 << "  R7:0x" << r7 << endl;
        cout << "N:" << N << "  Z:" << Z << "  C:" << C << "  V:" << V << endl << endl;
    }

    return r0, r1, r2, r3, r4, r5, r6, r7, N, Z, C, V;
}
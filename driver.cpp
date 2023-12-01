//Programming Project 3 - Due 11.30.2023
//Computer Science 219 - Seciton 1001
//Author - Samuel Mouradian
//Version - FINAL


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


#define FILENAME "Programming-Project-2.txt"
#define MAXLINE 1
#define NUMREGISTERS 8


//Operations - Programming Project 3:
void MOV(uint32_t *, uint32_t, uint32_t);

int main(){
    const string filename = "Programming-Project-3.txt";
    uint32_t registers[NUMREGISTERS], Rd, Rn, Rm, IMM;
    string operand;


    for(int i = 0; i < NUMREGISTERS; i++){
        registers[i] = 0x0;
    }


    ifstream txtFile;
    txtFile.open(FILENAME);
    for(int k = 0; k < MAXLINE; k++){
        if(txtFile.good()){
            txtFile >> operand;
            
            if(operand == "ADD" || operand == "ADDS" || operand == "add" || operand == "adds"){
                registers[Rd] = (registers[Rn] + registers[Rm]);

                for(int i = 0; i < NUMREGISTERS; i++){
                    cout << "  R" << i << ":0x" << registers[i];
                }

                cout << endl << "N = 0  Z = 0  C = 0  V = 0" << endl << endl;
            }
            else if(operand == "AND" || operand == "ANDS" || operand == "and" || operand == "ands"){
                registers[Rd] = (registers[Rn] & registers[Rm]);

                for(int i = 0; i < NUMREGISTERS; i++){
                    cout << "  R" << i << ":0x" << registers[i];
                }

                cout << endl << "N = 0  Z = 0  C = 0  V = 0" << endl << endl;
            }
            else if(operand == "ASR" || operand == "ASRS" || operand == "asr" || operand == "asrs"){
                registers[Rd] = (registers[Rn] >> registers[Rm]);

                for(int i = 0; i < NUMREGISTERS; i++){
                    cout << "  R" << i << ":0x" << registers[i];
                }

                cout << endl << "N = 0  Z = 0  C = 0  V = 0" << endl << endl;
            }
            else if(operand == "LSR" || operand == "LSRS" || operand == "lsr" || operand == "lsrs"){
                registers[Rd] = (registers[Rn] >> registers[Rm]);

                for(int i = 0; i < NUMREGISTERS; i++){
                    cout << "  R" << i << ":0x" << registers[i];
                }
                
                cout << endl << "N = 0  Z = 0  C = 0  V = 0" << endl << endl;
            }
            else if(operand == "LSL" || operand == "LSLS" || operand == "lsl" || operand == "lsls"){
                registers[Rd] = (registers[Rn] << registers[Rm]);

                for(int i = 0; i < NUMREGISTERS; i++){
                    cout << "  R" << i << ":0x" << registers[i];
                }
        
                cout << endl << "N = 0  Z = 0  C = 0  V = 0" << endl << endl;
            }
            else if(operand == "NOT" || operand == "NOTS" || operand == "not" || operand == "nots"){
                registers[Rd] = ~(registers[Rd]);

                for(int i = 0; i < NUMREGISTERS; i++){
                    cout << "  R" << i << ":0x" << registers[i];
                }
                
                cout << endl << "N = 0  Z = 0  C = 0  V = 0" << endl << endl;
            }
            else if(operand == "ORR" || operand == "ORRS" || operand == "orr" || operand == "orrs"){
                registers[Rd] = (registers[Rn] | registers[Rm]);

                for(int i = 0; i < NUMREGISTERS; i++){
                    cout << "  R" << i << ":0x" << registers[i];
                }
                
                cout << endl << "N = 0  Z = 0  C = 0  V = 0" << endl << endl;
            }
            else if(operand == "SUB" || operand == "SUBS" || operand == "sub" || operand == "subs"){
                registers[Rd] = (registers[Rn] - registers[Rm]);

                for(int i = 0; i < NUMREGISTERS; i++){
                    cout << "  R" << i << ":0x" << registers[i];
                }
                
                cout << endl << "N = 0  Z = 0  C = 0  V = 0" << endl << endl;
            }
            else if(operand == "XOR" || operand == "XORS" || operand == "xor" || operand == "xors"){
                registers[Rd] = (registers[Rn] ^ registers[Rm]);

                for(int i = 0; i < NUMREGISTERS; i++){
                    cout << "  R" << i << ":0x" << registers[i];
                }
                
                cout << endl << "N = 0  Z = 0  C = 0  V = 0" << endl << endl;
            }
        }
        else{
            ifstream txt(filename);
            if(txt.is_open()){
                vector<string> outputs;
                string temp;
                
                while(getline(txt, temp)){
                    outputs.push_back(temp);
                }
                
                for (const auto& i : outputs){
                    cout << i << std::endl;
                }
            }
            txt.close();
        }
    }
    txtFile.close();
    return 0;
}

void MOV(uint32_t *registers, uint32_t Rd, uint32_t IMM){
    registers[Rd] = IMM;
}
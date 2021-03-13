#include <ostream>
#include <iostream>
#include "uControl.h"
using namespace std;

uControl::uControl()
{
}

uControl::~uControl()
{
    //dtor
}

void uControl::setOpcode(int op)
{
    opcode = op;
}


void uControl::resetSinal()
{
    PCWrite = 0;
    MemWrite = 0;
    IRWrite = 0;
    RegWrite = 0;
}


void uControl::setSinalEtapa1()
{
    resetSinal();
    MemRead = 1;
    IRWrite = 1;
    IorD = 0;
    ALUSrcA = 0;
    PCWrite = 1;

    ALUSrcB = 1;
    ALUOp = 0;
    PCSource = 0;

    state = 1;
}

void uControl::setSinalEtapa2()
{
    resetSinal();
    ALUSrcA = 0;
    ALUSrcB = 3;
    ALUOp = 0;
}


void uControl::setSinalEtapa3()
{
    resetSinal();
    switch(opcode)
    {
        case 0:
            cout<<"type r"<<endl;
            ALUSrcA = 1;
            ALUSrcB = 0;
            ALUOp = 2;
            break;
        case 2:
            cout<<"j"<<endl;
            PCWrite = 1;
            PCSource = 2;
            state = 0;
            isJal = 0;
            break;
        case 3:
            cout<<"jal"<<endl;
            PCWrite = 1;
            PCSource = 2;
            state = 0;
            isJal = 1;
            break;
        case 4:
            cout<<"beq"<<endl;
            ALUSrcA = 1;
            ALUSrcB = 0;
            ALUOp = 1;
            PCWriteCond = 1;
            PCSource = 1;
            isBNE = 0;
            state = 0;
            break;
        case 5:
            cout<<"bne"<<endl;
            ALUSrcA = 1;
            ALUSrcB = 0;
            ALUOp = 1;
            PCWriteCond = 1;
            PCSource = 1;
            isBNE = 1;
            state = 0;
            break;
        case 8:
            cout<<"add immediate"<<endl;
            ALUSrcA = 1;
            ALUSrcB = 2;
            ALUOp = 0;
            break;
        case 35:
            cout<<"lw"<<endl;
            ALUSrcA = 1;
            ALUSrcB = 2;
            ALUOp = 0;
            break;
        case 43:
            cout<<"sw"<<endl;
            ALUSrcA = 1;
            ALUSrcB = 2;
            ALUOp = 0;
            break;
        default:
            cout<<"opcode error"<<endl;
            break;
    }
}


void uControl::setSinalEtapa4()
{
    resetSinal();
    switch(opcode)
    {
        case 0:
            cout<<"type r"<<endl;
            RegDst = 1;
            RegWrite = 1;
            MemtoReg = 0;
            state = 0;
            break;
        case 8:
            cout<<"add immediate"<<endl;
            RegDst = 0;
            RegWrite = 1;
            MemtoReg = 0;
            state = 0;
            break;
        case 35:
            cout<<"lw"<<endl;
            MemRead = 1;
            IorD = 1;
            break;
        case 43:
            cout<<"sw"<<endl;
            MemWrite = 1;
            IorD = 1;
            state = 0;
            break;
        default:
            cout<<"opcode error"<<endl;
            break;
    }
}


void uControl::setSinalEtapa5()
{
    resetSinal();
    if(opcode == 35){
        cout<<"lw"<<endl;
        RegDst = 0;
        RegWrite = 1;
        MemtoReg = 1;
        state = 0;
    }
    else
        cout<<"opcode error"<<endl;
}

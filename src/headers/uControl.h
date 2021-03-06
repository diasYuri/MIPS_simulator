#ifndef UCONTROL_H
#define UCONTROL_H
using namespace std;


class uControl
{
    public:
        uControl();
        ~uControl();
        bool isJal;
        bool isBNE;
        void setOpcode(int op);
        void setSinalEtapa1();
        void setSinalEtapa2();
        void setSinalEtapa3(FILE *arq);
        void setSinalEtapa4(FILE *arq);
        void setSinalEtapa5(FILE *arq);

        int getALUSrcB(){ return ALUSrcB; };
        int getALUOp(){ return ALUOp; };
        int getPCSource(){ return PCSource; };
        bool getPCWriteCond(){ return PCWriteCond; };
        bool getPCWrite(){ return PCWrite; };
        bool getIorD(){ return IorD; };
        bool getMemRead(){ return MemRead; };
        bool getMemWrite(){ return MemWrite; };
        bool getMemtoReg(){ return MemtoReg; }; 
        bool getIRWrite(){ return IRWrite; };
        bool getALUSrcA(){ return ALUSrcA; };
        bool getRegwrite(){ return RegWrite; };
        bool getRegDst(){ return RegDst; };
        bool getState(){ return state; };


    private:
        int opcode;
        int ALUSrcB, ALUOp, PCSource;
        bool PCWriteCond, PCWrite, IorD, MemRead, MemWrite, MemtoReg, IRWrite, ALUSrcA, RegWrite, RegDst;
        bool state;

       void resetSinal();
};

#endif // UCONTROL_H

#include <iostream>
#include <map>
#include <vector>
#include <unistd.h>
using namespace std;

class Register
{
private:
    int val;
    string instrucction;

public:
    Register()
    {
        val = -1;
        instrucction = "No tiene nada";
    }
    Register(int c, string s)
    {
        val = c;
        instrucction = s;
    }
    void setVal(int c)
    {
        val = c;
    }
    int getVal()
    {
        return val;
    }
    void setInstrucction(string c)
    {
        instrucction = c;
    }
    string getInstrucction()
    {
        return instrucction;
    }
};

class ALU
{
private:
    Register A, B;

public:
    ALU() {}
    void setA(int val)
    {
        A.setVal(val);
    }
    void setB(int val)
    {
        B.setVal(val);
    }
    int add()
    {
        return A.getVal() + B.getVal();
    }
    int sub()
    {
        return A.getVal() - B.getVal();
    }
};

enum class State
{
    Initialize,
    Read,
    SET,
    LDR,
    ADD,
    INC,
    DEC,
    STR,
    SHW,
    PAUSE,
    END,
};
class VonNeuman
{
private:
    map<string, Register> memory;
    Register PC, MAR, ICR, MDR, acumulador, unitControl;
    State curState;
    ALU Alu;
    map<string, State> insMap;

public:
    VonNeuman() : curState(State::Initialize) {}
    void transition(State nextState)
    {
        curState = nextState;
        PC.setVal(PC.getVal() + 1);
    }
    void events()
    {
        switch (curState)
        {
        case State::Initialize:
            initialize(200);
            break;
        case State::Read:
            read();
            break;
        case State::SET:
            set();
            break;
        case State::LDR:
            ldr();
            break;
        case State::ADD:
            add();
            break;
        case State::INC:
            inc();
            break;
        case State::DEC:
            dec();
            break;
        case State::STR:
            str();
            break;
        case State::SHW:
            shw();
            break;
        case State::PAUSE:
            pause();
            break;
        case State::END:
            printf("The program finished correctly\n");
            break;
        }
    }

    void initialize(int memSize)
    {
        // Ininicializa las estructuras correspondientes
        PC.setVal(0);
        Register tmp;
        insMap = {
            {"SET", State::SET},
            {"LDR", State::LDR},
            {"ADD", State::ADD},
            {"INC", State::INC},
            {"DEC", State::DEC},
            {"STR", State::STR},
            {"SHW", State::SHW},
            {"PAUSE", State::PAUSE},
            {"END", State::END}};
        for (int i = 0; i < memSize; i++)
        {
            string key = "D" + to_string(i);
            memory[key] = tmp;
        }
        // printf("Hola");
        transition(State::Read);
        events();
    }

    void read()
    {
        string ins;
        cin >> ins;
        // cout << ins << endl;
        transition(insMap[ins]);
        ICR.setInstrucction(ins);
        unitControl.setInstrucction(ins);
        events();
    }
    void set()
    {
        string pos, null;
        int val;
        cin >> pos >> val >> null >> null;
        MAR.setInstrucction(pos);
        MDR.setVal(val);

        memory[MAR.getInstrucction()].setVal(MDR.getVal());

        transition(State::Read);
        events();
    }
    void ldr()
    {
        string pos, null;
        cin >> pos >> null >> null >> null;
        MAR.setInstrucction(pos);
        MDR.setVal(memory[pos].getVal());
        acumulador.setVal(MDR.getVal());
        transition(State::Read);
        events();
    }

    void add()
    {
        string pos0, pos1, pos2, null;
        cin >> pos0 >> pos1 >> pos2 >> null;
        if (pos2 != "NULL")
        {
            MAR.setInstrucction(pos2);
            MDR.setVal(memory[MAR.getInstrucction()].getVal());
            Alu.setA(memory[pos0].getVal());
            Alu.setB(memory[pos1].getVal());
            memory[pos2].setVal(Alu.add());
        }
        else if (pos1 != "NULL")
        {
            MAR.setInstrucction(pos1);
            MDR.setVal(memory[MAR.getInstrucction()].getVal());
            Alu.setA(memory[pos0].getVal());
            Alu.setB(memory[pos1].getVal());
            acumulador.setVal(Alu.add());
        }
        else
        {

            Alu.setA(acumulador.getVal());
            MAR.setInstrucction(pos0);
            MDR.setVal(memory[MAR.getInstrucction()].getVal());
            Alu.setB(MDR.getVal());
            acumulador.setVal(Alu.add());
        }
        transition(State::Read);
        // cout << Alu.add();
        events();
    }
    void inc()
    {
        string pos, null;
        cin >> pos >> null >> null >> null;
        Alu.setA(1);
        MAR.setInstrucction(pos);
        MDR.setVal(memory[MAR.getInstrucction()].getVal());
        Alu.setB(MDR.getVal());
        memory[pos].setVal(Alu.sub());
        transition(State::Read);
        events();
    }
    void dec()
    {
        string pos, null;
        cin >> pos >> null >> null >> null;
        Alu.setA(-1);
        MAR.setInstrucction(pos);
        MDR.setVal(memory[MAR.getInstrucction()].getVal());
        Alu.setB(MDR.getVal());
        memory[pos].setVal(Alu.sub());
        transition(State::Read);
        events();
    }
    void shw()
    {
        string pos, null;
        cin >> pos >> null >> null >> null;
        cout << "SHOW -> " << pos << ": ";
        if (pos == "ACC")
            cout << acumulador.getVal() << endl;
        else if (pos == "ICR")
            cout << ICR.getInstrucction() << endl;
        else if (pos == "MAR")
            cout << MAR.getInstrucction() << endl;
        else if (pos == "MDR")
            cout << MDR.getVal() << endl;
        else if (pos == "UC")
            cout << unitControl.getInstrucction() << endl;
        else if (pos == "PC")
            cout << PC.getVal() << endl;
        else
            cout << memory[pos].getVal() << endl;
        transition(State::Read);
        events();
    }
    void str()
    {
        string pos, null;
        cin >> pos >> null >> null >> null;
        memory[pos].setVal(acumulador.getVal());
        // cout << memory[pos].getVal() << endl;
        transition(State::Read);
        events();
    }
    void pause()
    {
        string null;
        cin >> null >> null >> null >> null;
        sleep(1);
        transition(State::Read);
        events();
    }
};

int main()
{
    VonNeuman simu;
    simu.events();

    return 0;
}
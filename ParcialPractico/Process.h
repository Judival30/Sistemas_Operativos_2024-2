#ifndef PROCESS
#define PROCESS
#include <iostream>

using namespace std;

class Process
{
public:
    int currTime;

    string ID;
    int qId, cont, AT, BT, ct, tat, rt, wt;
    bool visited;
    Process();
    Process(string id, int at, int bt, int qid, int c);

    bool operator<(Process &est);
    int setTime(int t);
    int complete();
    bool isFinished();
    int getQueveID();
    int getAT();
    void setCT(int n);
};
#endif
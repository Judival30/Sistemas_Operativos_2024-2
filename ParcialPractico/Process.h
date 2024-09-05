#ifndef PROCESS
#define PROCESS
#include <iostream>

using namespace std;

class Process
{
private:
    string ID;
    int AT, BT, priority, currTime;
    int ct, tat, rt, wt;

public:
    Process();
    Process(string id, int at, int bt, int p);

    bool operator<(Process &est);
    int setTime(int t);
    bool isFinished();
};
#endif
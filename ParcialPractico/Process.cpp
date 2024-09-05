#include "process.h"

Process::Process() {}

Process::Process(string id, int at, int bt, int p)
{
    ID = id;
    AT = at;
    BT = bt;
    priority = p;
    currTime = at;
}

bool Process::operator<(Process &est)
{
    return AT < est.AT;
}

int Process::setTime(int t)
{
    int ans = t;
    if (t >= currTime)
    {
        ans = currTime;
        currTime = 0;
    }
    else
    {
        currTime -= t;
    }
    return ans;
}

bool Process::isFinished()
{
    return currTime == 0;
}

#include "process.h"

Process::Process() {}

Process::Process(string id, int at, int bt, int qid, int c)
{
    ID = id;
    AT = at;
    BT = bt;
    currTime = bt;
    qId = qid;
    cont = c;
    visited = false;
}

bool Process::operator<(Process &est)
{
    if (AT != est.AT)
        return AT < est.AT;
    else
        return qId < est.qId;
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
int Process::complete()
{
    currTime = 0;
    return BT;
}
bool Process::isFinished()
{
    return currTime == 0;
}

int Process::getQueveID()
{
    return qId;
}

int Process::getAT()
{
    return AT;
}

void Process::setCT(int n)
{
    ct = n;
}

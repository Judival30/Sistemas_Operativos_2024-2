#include "FCFS.h"

FCFS::FCFS() {}

void FCFS::push(Process &p)
{
    q.push(p);
}

pair<Process, int> FCFS::pop()
{
    pair<Process, int> ans;
    Process tmp = q.front();
    q.pop();
    ans.first = tmp;
    ans.second = tmp.BT;
    ans.first.complete();
    return ans;
}

bool FCFS::empty()
{
    return q.empty();
}

#include "RoundRobin.h"

RoundRobin::RoundRobin() {}

RoundRobin::RoundRobin(vector<Process> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        q.push(v[i]);
    }
};

void RoundRobin::setQuantum(int q)
{
    quantum = q;
}
void RoundRobin::push(Process &p)
{
    q.push(p);
}

pair<Process, int> RoundRobin::pop()
{
    pair<Process, int> ans;
    Process tmp = q.front();
    q.pop();
    int timeUsed = tmp.setTime(quantum);
    ans.first = tmp;
    ans.second = timeUsed;
    return ans;
}

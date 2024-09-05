#ifndef ROUNDRIBIN
#define ROUNDRIBIN

#include <queue>
#include "Queue.h"
#include "process.h"
#include <vector>

class RoundRobin : public QueueP
{
private:
    int quantum;
    queue<Process> q;

public:
    RoundRobin();
    RoundRobin(vector<Process> &v);

    void setQuantum(int q);
    void push(Process &p) override;
    pair<Process, int> pop() override;
};

#endif
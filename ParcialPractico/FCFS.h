#ifndef FCFS_H
#define FCFS_H

#include <queue>
#include "Queue.h"
#include "process.h"
#include <vector>

class FCFS : public QueueP
{
private:
    queue<Process> q;

public:
    FCFS();
    void push(Process &p) override;
    pair<Process, int> pop() override;
    bool empty() override;
};

#endif

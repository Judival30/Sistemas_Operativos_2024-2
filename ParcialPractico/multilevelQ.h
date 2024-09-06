#ifndef MULTIQ
#define MULTIQ

#include "RoundRobin.h"
#include "FCFS.h"
#include "algorithm"

class MultiLevelQ
{
private:
    vector<QueueP *> arq;
    vector<Process> stats;
    string line;

public:
    MultiLevelQ();
    void pushNewQueue(QueueP *p);
    void MLQ(vector<Process> &vec);
    void MLFQ(vector<Process> &vec);
    void printResults();
    void printGrandChart();
};

#endif
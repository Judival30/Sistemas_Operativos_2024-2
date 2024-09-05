#ifndef MULTIQ
#define MULTIQ

#include "RoundRobin.h"

class MultiLevelQ
{
private:
    vector<QueueP *> arq;

public:
    MultiLevelQ();
    void pushNewQueue(QueueP *p);
    void MLQ();
};

#endif
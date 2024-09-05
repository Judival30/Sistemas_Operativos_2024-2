#ifndef QUEUE_H
#define QUEUE_H

#include "RoundRobin.h"
#include <utility>
#include "process.h"
class QueueP
{
public:
    virtual pair<Process, int> pop() = 0;
    virtual void push(Process &p) = 0;
};
#endif
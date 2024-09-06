#ifndef QUEUE_H
#define QUEUE_H

#include <utility>
#include "process.h"
class QueueP
{
public:
    virtual pair<Process, int> pop() = 0;
    virtual void push(Process &p) = 0;
    virtual bool empty() = 0;
};
#endif
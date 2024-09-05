#include "multilevelQ.h"

int main()
{
    string type;
    int n, num;
    cin >> num;
    MultiLevelQ colas;
    while (num--)
    {
        cin >> type;
        if (type == "RR")
        {
            cin >> n;
            RoundRobin *p = new RoundRobin();
            p->setQuantum(n);
            colas.pushNewQueue(p);
        }
        else
            n = 0;
    }

    return 0;
}
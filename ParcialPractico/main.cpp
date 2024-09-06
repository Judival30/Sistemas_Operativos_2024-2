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
        else if (type == "FCFS")
        {

            FCFS *p = new FCFS();
            colas.pushNewQueue(p);
        }
    }
    // Tipo de cola multinivel

    cin >> type;
    // Numero de procesos
    cin >> num;
    string id;
    int at, bt, qid;
    vector<Process> vec;
    int i = 0;
    while (num--)
    {
        cin >> id >> at >> bt >> qid;
        Process p(id, at, bt, qid, i);
        // cout << id << " " << at << endl;
        vec.push_back(p);
        i++;
    }
    if (type == "MLQ")
        colas.MLQ(vec);
    else
        colas.MLFQ(vec);
    colas.printGrandChart();
    colas.printResults();

    return 0;
}
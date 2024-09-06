#include "multilevelQ.h"

MultiLevelQ::MultiLevelQ() {}

void MultiLevelQ::pushNewQueue(QueueP *p)
{
    arq.push_back(p);
}

auto compQueveLevel = [](const Process &a, const Process &b)
{
    if (a.qId == b.qId)
        return a.cont > b.cont;
    if (a.qId != b.qId)
        return a.qId > b.qId;
    /* else
        return a.cont > b.cont; */
};

void MultiLevelQ::MLQ(vector<Process> &vec)
{
    sort(vec.begin(), vec.end());
    line = "";
    printf("Exec:\n| ID | currTime | Q |\n");
    int contInc = 0, curTime = 0, i = 1;
    pair<Process, int> tmp;
    priority_queue<Process, vector<Process>, decltype(compQueveLevel)> ready(compQueveLevel);
    Process p = vec[0];

    p = vec[0];
    ready.push(p);
    while (!ready.empty())
    {
        p = ready.top();
        if (!p.visited)
        {
            p.rt = curTime;
            p.visited = true;
        }
        ready.pop();
        arq[p.qId]->push(p);
        tmp = arq[p.qId]->pop();
        curTime += tmp.second;
        line += "|";
        for (int i = 0; i < tmp.second; i++)
            line += "-";

        cout << "| " << p.ID;
        printf(" |%10d|%3d|\n", curTime, p.qId);

        bool flag = true;
        while (i < vec.size() && flag)

        {
            if (curTime >= vec[i].getAT())
            {

                vec[i].cont = ++contInc;
                ready.push(vec[i]);
                // cout << "-- " << vec[i].ID << " " << vec[i].cont << endl;
                i++;
            }
            else
            {
                flag = false;
            }
        }

        if (!tmp.first.isFinished())
        {

            tmp.first.cont = ++contInc;
            ready.push(tmp.first);
        }
        else
        {
            tmp.first.setCT(curTime);
            stats.push_back(tmp.first);
        }
    }
}
auto name = [](const Process &a, const Process &b)
{
    return a.ID < b.ID;
};

void MultiLevelQ::printResults()
{
    sort(stats.begin(), stats.end(), name);
    printf(" ID | BT | AT | WT | RT | CT | TAT|\n");
    printf("-----------------------------------\n");
    double ctp = 0, tatp = 0, rtp = 0, wtp = 0, len = stats.size();
    for (int i = 0; i < stats.size(); i++)
    {
        cout << " " << stats[i].ID << " ";
        printf("|%4d|%4d|%4d|%4d|%4d|%4d|\n", stats[i].BT, stats[i].AT, stats[i].ct - stats[i].BT - stats[i].AT,
               stats[i].rt, stats[i].ct, stats[i].ct - stats[i].AT);
        ctp += stats[i].ct;
        tatp += stats[i].ct - stats[i].AT;
        rtp += stats[i].rt;
        wtp += stats[i].ct - stats[i].BT - stats[i].AT;
    }
    printf("\nProm: CT: %.2f, TAT: %.2f, WT: %.2f, RT: %.2f\n", ctp / len, tatp / len, wtp / len, rtp / len);
}
auto compLine = [](const Process &a, const Process &b)
{
    return a.ct < b.ct;
};
void MultiLevelQ::printGrandChart()
{
    cout << endl;
    sort(stats.begin(), stats.end(), compLine);
    int acum = 0, pos = 0;
    line += "|";

    cout << endl
         << "Grand Chart:\n"
         << line << endl;
    pos = 0;
    for (int i = 0; i < stats.size(); i++)
    {
        acum = (stats[i].ct - pos) / 2;
        for (int j = 0; j < acum; j++)
            cout << " ";
        cout << stats[i].ID;
        for (int j = 0; j < acum; j++)
            cout << " ";
        pos += stats[i].BT;
    }
    cout << endl
         << endl;
}
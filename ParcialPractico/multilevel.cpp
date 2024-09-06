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
    printf("Exec MLQ:\n| ID | currTime | Q |\n");
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

auto compArrival = [](const Process &a, const Process &b)
{
    return a.AT > b.AT;
};

void MultiLevelQ::MLFQ(vector<Process> &vec)
{
    line = "";
    printf("Exec MLFQ:\n| ID | Time | Q |\n");
    int currQ = 0, curTime = 0, i = 1;
    pair<Process, int> tmp;
    priority_queue<Process, vector<Process>, decltype(compArrival)> ready(compArrival);
    Process p;
    for (int i = 0; i < vec.size(); i++)
        ready.push(vec[i]);
    bool flag = true;
    int cont = 0;
    int contPfini = 0;
    while (flag)
    {
        currQ = 0;
        cont++;

        while (currQ < arq.size())
        {
            bool flagNewP = true;
            while (!ready.empty() && flagNewP)
            {
                // cout << curTime << " " << ready.top().AT << endl;
                if (curTime >= ready.top().AT)
                {
                    p = ready.top();
                    ready.pop();
                    arq[currQ]->push(p);
                }
                else
                    flagNewP = false;
            }
            if (arq[currQ]->empty())
                currQ++;
            else
            {
                tmp = arq[currQ]->pop();
                if (!tmp.first.visited)
                {
                    tmp.first.rt = curTime;
                    tmp.first.visited = true;
                }
                curTime += tmp.second;
                line += "|";
                for (int i = 0; i < tmp.second; i++)
                    line += "-";
                cout << "| " << tmp.first.ID;
                printf(" |%6d|%3d|\n", curTime, currQ);
                if (tmp.first.isFinished())
                {
                    tmp.first.setCT(curTime);
                    stats.push_back(tmp.first);
                    contPfini++;
                }
                else if (currQ + 1 < arq.size())
                    arq[currQ + 1]->push(tmp.first);
                else
                    arq[currQ]->push(tmp.first);
            }
        }

        if (contPfini == vec.size())
            flag = false;
    }
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
    if (line.size() / stats.size() > 10)
    {
        pos = 0;
        for (int i = 0; i < line.size(); i++)
        {
            if (i == stats[pos].ct)
            {
                cout << stats[pos].ID;
                if (pos + 1 < stats.size())
                    pos++;
            }
            else
                cout << " ";
        }
        cout << endl;
        /* for (int i = 0; i < stats.size(); i++)
        {
            acum = (stats[i].ct - pos) / 2;
            for (int j = 0; j < acum; j++)
                cout << " ";
            cout << stats[i].ID;
            for (int j = 0; j < acum; j++)
                cout << " ";
            pos += stats[i].BT;
        } */
    }
    cout << endl
         << endl;
}
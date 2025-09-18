// https://leetcode.com/problems/design-task-manager/?envType=daily-question&envId=2025-09-18

#include <bits/stdc++.h>
using namespace std;
class TaskManager
{
public:
    priority_queue<pair<int, int>> pq;
    unordered_map<int, int> tp;
    unordered_map<int, int> tu;
    TaskManager(vector<vector<int>> &ta)
    {
        for (int i = 0; i < ta.size(); i++)
        {
            int u = ta[i][0];
            int t = ta[i][1];
            int pr = ta[i][2];
            pq.push({pr, t});
            tp[t] = pr;
            tu[t] = u;
        }
    }

    void add(int u, int t, int p)
    {
        tp[t] = p;
        tu[t] = u;
        pq.push({p, t});
    }

    void edit(int t, int np)
    {
        tp[t] = np;
        pq.push({np, t});
    }

    void rmv(int t)
    {
        tp[t] = -1;
    }

    int execTop()
    {
        while (!pq.empty())
        {
            int t = pq.top().second;
            int p = pq.top().first;
            pq.pop();
            if (tp[t] == p)
            {
                tp[t] = -1;
                return tu[t];
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
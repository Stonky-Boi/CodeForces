#include <iostream>
#include <deque>
#include <stack>
#include <queue>
#include <sstream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> commands(n);
    vector<int> zeros;
    for (int i = 0; i < n; i++)
    {
        cin >> commands[i];
        if (commands[i] == 0)
            zeros.push_back(i);
    }
    zeros.push_back(n);
    vector<string> result(n);
    deque<int> deque;
    stack<int> stack;
    queue<int> queue;
    int zero_index = 0;
    for (int i = 0; i < n; i++)
    {
        if (commands[i] == 0)
        {
            int curr_zero = zero_index > 0 ? zeros[zero_index - 1] : -1;
            int next_zero = zeros[zero_index];
            vector<pair<int, int>> cur; // (value, index)
            for (int j = curr_zero + 1; j < next_zero; j++)
            {
                if (commands[j] != 0)
                    cur.emplace_back(commands[j], j);
            }
            if (cur.empty())
                result[i] = "0";
            else if (cur.size() == 1)
            {
                result[cur[0].second] = "pushStack";
                stack.push(cur[0].first);
                result[i] = "1 popStack";
            }
            else if (cur.size() == 2)
            {
                sort(cur.rbegin(), cur.rend());
                result[cur[0].second] = "pushStack";
                result[cur[1].second] = "pushQueue";
                stack.push(cur[0].first);
                queue.push(cur[1].first);
                result[i] = "2 popStack popQueue";
            }
            else
            {
                int x = -1, y = -1, z = -1;
                for (int j = 0; j < cur.size(); j++)
                {
                    if (x == -1 || cur[j].first > cur[x].first)
                        x = j;
                }
                for (int j = 0; j < cur.size(); j++)
                {
                    if (j != x && (y == -1 || cur[j].first > cur[y].first))
                        y = j;
                }
                for (int j = 0; j < cur.size(); j++)
                {
                    if (j != x && j != y && (z == -1 || cur[j].first > cur[z].first))
                        z = j;
                }
                for (int j = 0; j < cur.size(); j++)
                {
                    if (j == x)
                    {
                        result[cur[j].second] = "pushStack";
                        stack.push(cur[j].first);
                    }
                    else if (j == y)
                    {
                        result[cur[j].second] = "pushQueue";
                        queue.push(cur[j].first);
                    }
                    else if (j == z)
                    {
                        result[cur[j].second] = "pushFront";
                        deque.push_front(cur[j].first);
                    }
                    else
                    {
                        result[cur[j].second] = "pushBack";
                        deque.push_back(cur[j].first);
                    }
                }
                result[i] = "3 popStack popQueue popFront";
            }
            while (!stack.empty())
                stack.pop();
            while (!queue.empty())
                queue.pop();
            while (!deque.empty())
                deque.pop_front();
            zero_index++;
        }
    }
    if (zero_index > 0 && zeros[zero_index - 1] + 1 < n)
    {
        for (int i = zeros[zero_index - 1] + 1; i < n; i++)
        {
            result[i] = "pushQueue";
            queue.push(commands[i]);
        }
    }
    else if (zero_index == 0 && n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            result[i] = "pushQueue";
            queue.push(commands[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!result[i].empty())
            cout << result[i] << endl;
    }
    return 0;
}
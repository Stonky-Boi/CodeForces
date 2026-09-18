#include <iostream>
#include <vector>
using namespace std;

// naive approach
// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> p(n + 1);
//     for (int i = 1; i <= n; i++)
//         cin >> p[i];
//     for (int i = 1; i <= n; i++)
//     {
//         vector<bool> visited(n + 1, false);
//         int curr = i;
//         while (!visited[curr])
//         {
//             visited[curr] = true;
//             curr = p[curr];
//         }
//         cout << curr;
//         if (i != n)
//             cout << " ";
//     }
//     cout << endl;
//     return 0;
// }

vector<int> p, state, answer;

void dfs(int node)
{
    state[node] = 1;
    int next = p[node];
    if (state[next] == 0)
        dfs(next);
    else if (state[next] == 1)
    {
        int curr = next;
        do
        {
            answer[curr] = curr;
            curr = p[curr];
        } while (curr != next);
    }
    if (answer[node] == 0)
        answer[node] = answer[p[node]];
    state[node] = 2;
}

int main()
{
    int n;
    cin >> n;
    p.assign(n + 1, 0);
    state.assign(n + 1, 0);
    answer.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
        if (state[i] == 0)
            dfs(i);
    for (int i = 1; i <= n; i++)
    {
        cout << answer[i];
        if (i != n)
            cout << " ";
    }
    cout << endl;
    return 0;
}
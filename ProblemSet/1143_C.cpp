#include <iostream>
#include <vector>
using namespace std;

struct vertex
{
    int parent;
    int respect;
    vector<int> children;
};

int main()
{
    int n;
    cin >> n;
    vector<vertex> vertices(n + 1);
    int root = -1;
    for (int i = 1; i <= n; i++)
    {
        cin >> vertices[i].parent >> vertices[i].respect;
        if (vertices[i].parent == -1)
            root = i;
        else
            vertices[vertices[i].parent].children.push_back(i);
    }
    vector<int> deleted;
    for (int i = 1; i <= n; i++)
    {
        if (i == root || vertices[i].respect == 0)
            continue;
        bool all_disrespect = true;
        for (const int &child : vertices[i].children)
        {
            if (vertices[child].respect == 0)
            {
                all_disrespect = false;
                break;
            }
        }
        if (all_disrespect)
            deleted.push_back(i);
    }
    if (deleted.empty())
        cout << -1 << endl;
    else
    {
        for (const int &i : deleted)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
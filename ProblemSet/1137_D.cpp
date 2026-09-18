#include <iostream>
#include <vector>
using namespace std;

vector<string> read_groups()
{
    int k;
    cin >> k;
    vector<string> groups(k);
    for (auto &i : groups)
        cin >> i;
    return groups;
}

int main()
{
    while (true)
    {
        cout << "next 0 1" << endl;
        vector<string> g1 = read_groups();
        cout << "next 1" << endl;
        vector<string> g2 = read_groups();
        bool same_group = false;
        for (auto g : g2)
            if (g.find('0') != string::npos && g.find('1') != string::npos)
                same_group = true;
        if (same_group)
            break;
    }
    while (true)
    {
        cout << "next 0 1 2 3 4 5 6 7 8 9" << endl;
        vector<string> g = read_groups();
        bool all_together = false;
        for (auto i : g)
            if ((int)i.size() == 10)
                all_together = true;
        if (all_together)
            break;
    }
    cout << "done" << endl;
    return 0;
}
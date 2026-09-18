#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string task_order;
        cin >> n >> task_order;
        bool alphabet[26] = {false};
        char last_task = task_order[0];
        alphabet[last_task - 'A'] = true;
        bool suspicious = false;
        for (int i = 1; i < n; i++)
        {
            if (task_order[i] != last_task)
            {
                if (alphabet[task_order[i] - 'A'])
                {
                    suspicious = true;
                    break;
                }
                alphabet[last_task - 'A'] = true;
                last_task = task_order[i];
            }
        }
        if (suspicious)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int x[3], y[3];
    int idx[3] = {0, 1, 2};
    cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];
    for (int i = 0; i < 3; i++)
    {
        if (x[i] > y[i])
            swap(x[i], y[i]);
    }
    int area = x[0] * y[0] + x[1] * y[1] + x[2] * y[2];
    int length = sqrt(area);
    if (length * length != area)
    {
        cout << "-1" << endl;
        return 0;
    }
    if (y[0] == length && y[1] == length && y[2] == length)
    {
        cout << length << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < x[i]; j++)
            {
                for (int k = 0; k < length; k++)
                    cout << char('A' + i);
                cout << endl;
            }
        }
        return 0;
    }
    sort(idx, idx + 3, [&](int a, int b)
         { return y[a] > y[b]; });
    if (y[idx[0]] != length)
    {
        cout << "-1" << endl;
        return 0;
    }
    if (y[idx[1]] == y[idx[2]] && x[idx[1]] + x[idx[2]] == length)
    {
        cout << length << endl;
        for (int j = 0; j < x[idx[0]]; j++)
        {
            for (int k = 0; k < length; k++)
                cout << char('A' + idx[0]);
            cout << endl;
        }
        for (int j = 0; j < length - x[idx[0]]; j++)
        {
            for (int k = 0; k < x[idx[1]]; k++)
                cout << char('A' + idx[1]);
            for (int k = 0; k < x[idx[2]]; k++)
                cout << char('A' + idx[2]);
            cout << endl;
        }
        return 0;
    }
    if (x[idx[1]] == x[idx[2]] && y[idx[1]] + y[idx[2]] == length)
    {
        cout << length << endl;
        for (int j = 0; j < x[idx[0]]; j++)
        {
            for (int k = 0; k < length; k++)
                cout << char('A' + idx[0]);
            cout << endl;
        }
        for (int j = 0; j < length - x[idx[0]]; j++)
        {
            for (int k = 0; k < y[idx[1]]; k++)
                cout << char('A' + idx[1]);
            for (int k = 0; k < y[idx[2]]; k++)
                cout << char('A' + idx[2]);
            cout << endl;
        }
        return 0;
    }
    if (y[idx[1]] == x[idx[2]] && x[idx[1]] + y[idx[2]] == length)
    {
        cout << length << endl;
        for (int j = 0; j < x[idx[0]]; j++)
        {
            for (int k = 0; k < length; k++)
                cout << char('A' + idx[0]);
            cout << endl;
        }
        for (int j = 0; j < length - x[idx[0]]; j++)
        {
            for (int k = 0; k < x[idx[1]]; k++)
                cout << char('A' + idx[1]);
            for (int k = 0; k < y[idx[2]]; k++)
                cout << char('A' + idx[2]);
            cout << endl;
        }
        return 0;
    }
    if (x[idx[1]] == y[idx[2]] && y[idx[1]] + x[idx[2]] == length)
    {
        cout << length << endl;
        for (int j = 0; j < x[idx[0]]; j++)
        {
            for (int k = 0; k < length; k++)
                cout << char('A' + idx[0]);
            cout << endl;
        }
        for (int j = 0; j < length - x[idx[0]]; j++)
        {
            for (int k = 0; k < y[idx[1]]; k++)
                cout << char('A' + idx[1]);
            for (int k = 0; k < x[idx[2]]; k++)
                cout << char('A' + idx[2]);
            cout << endl;
        }
        return 0;
    }
    cout << "-1" << endl;
    return 0;
}
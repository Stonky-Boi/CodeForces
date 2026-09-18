#include <iostream>
using namespace std;

int main()
{
    string guest_name, residence_host, letter_pile;
    cin >> guest_name >> residence_host >> letter_pile;
    for (int i = 0; i < letter_pile.size(); i++)
    {
        for (int j = 0; j < guest_name.size(); j++)
        {
            if (letter_pile[i] == guest_name[j])
            {
                letter_pile[i] = 0;
                guest_name[j] = 0;
                continue;
            }
        }
        for (int j = 0; j < residence_host.size(); j++)
        {
            if (letter_pile[i] == residence_host[j])
            {
                letter_pile[i] = 0;
                residence_host[j] = 0;
                continue;
            }
        }
    }
    bool permutable = true;
    for (int i = 0; i < letter_pile.size(); i++)
    {
        if (letter_pile[i] != 0)
        {
            permutable = false;
            break;
        }
    }
    for (int i = 0; i < guest_name.size(); i++)
    {
        if (guest_name[i] != 0)
        {
            permutable = false;
            break;
        }
    }
    for (int i = 0; i < residence_host.size(); i++)
    {
        if (residence_host[i] != 0)
        {
            permutable = false;
            break;
        }
    }
    if (permutable)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
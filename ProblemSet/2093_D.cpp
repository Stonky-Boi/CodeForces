#include <iostream>
#include <utility>
using namespace std;

long long int get_number(int size, long long int x, long long int y, long long int start)
{
    if (size == 1)
    {
        if (x == 1 && y == 1)
            return start;
        if (x == 2 && y == 2)
            return start + 1;
        if (x == 2 && y == 1)
            return start + 2;
        if (x == 1 && y == 2)
            return start + 3;
    }
    long long int half = 1LL << (size - 1);
    long long int cells = half * half;
    if (x <= half && y <= half)
        return get_number(size - 1, x, y, start);
    else if (x > half && y > half)
        return get_number(size - 1, x - half, y - half, start + cells);
    else if (x > half && y <= half)
        return get_number(size - 1, x - half, y, start + 2 * cells);
    else
        return get_number(size - 1, x, y - half, start + 3 * cells);
}

pair<long long int, long long int> get_position(int size, long long int target, long long int start, long long int base_x, long long int base_y)
{
    if (size == 1)
    {
        if (start == target)
            return {base_x + 1, base_y + 1};
        if (start + 1 == target)
            return {base_x + 2, base_y + 2};
        if (start + 2 == target)
            return {base_x + 2, base_y + 1};
        if (start + 3 == target)
            return {base_x + 1, base_y + 2};
    }
    long long int half = 1LL << (size - 1);
    long long int cells = half * half;
    if (target <= start + cells - 1)
        return get_position(size - 1, target, start, base_x, base_y);
    else if (target <= start + 2 * cells - 1)
        return get_position(size - 1, target, start + cells, base_x + half, base_y + half);
    else if (target <= start + 3 * cells - 1)
        return get_position(size - 1, target, start + 2 * cells, base_x + half, base_y);
    else
        return get_position(size - 1, target, start + 3 * cells, base_x, base_y + half);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        while (q--)
        {
            string query;
            cin >> query;
            if (query == "->")
            {
                long long int x, y;
                cin >> x >> y;
                long long int number = get_number(n, x, y, 1);
                cout << number << endl;
            }
            else
            {
                long long int d;
                cin >> d;
                auto [x, y] = get_position(n, d, 1, 0, 0);
                cout << x << " " << y << endl;
            }
        }
    }
    return 0;
}
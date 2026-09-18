#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

bool all_eatable(const vector<int> &packmen, deque<int> food, int time)
{
    for (int p : packmen)
    {
        vector<int> left_side;
        while (!food.empty() && food.front() < p)
        {
            left_side.push_back(food.front());
            food.pop_front();
        }
        if (left_side.empty())
            while (!food.empty() && food.front() - p <= time)
                food.pop_front();
        else
        {
            int left_distance = p - left_side[0];
            if (left_distance > time)
                return false;
            int right_time = time - 2 * left_distance;
            int left_first_count = -1;
            while (left_first_count + 1 < (int)food.size() && food[left_first_count + 1] - p <= right_time)
                left_first_count++;
            right_time = time - left_distance;
            int right_first_count = -1;
            while (right_first_count + 1 < (int)food.size() && 2 * (food[right_first_count + 1] - p) <= right_time)
                right_first_count++;
            int eat_count = max(left_first_count, right_first_count) + 1;
            for (int i = 0; i < eat_count; i++)
                if (!food.empty())
                    food.pop_front();
        }
        if (food.empty())
            return true;
    }
    return food.empty();
}

int main()
{
    int n;
    cin >> n;
    string field;
    cin >> field;
    vector<int> packmen;
    deque<int> food;
    for (int i = 0; i < n; i++)
    {
        if (field[i] == 'P')
            packmen.push_back(i);
        else if (field[i] == '*')
            food.push_back(i);
    }
    int l = 0;
    int r = n * 2;
    int time = -1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (all_eatable(packmen, food, m))
        {
            time = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    cout << time << endl;
}
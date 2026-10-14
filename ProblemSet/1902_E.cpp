#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
    int child[26];
    int count;

    node()
    {
        fill(child, child + 26, -1);
        count = 0;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<node> trie(1);
    vector<string> s(n);
    long long sum = 0;
    for (string &i : s)
    {
        cin >> i;
        sum += i.size();
        reverse(i.begin(), i.end());
        int u = 0;
        for (const char &ch : i)
        {
            int c = ch - 'a';
            if (trie[u].child[c] == -1)
            {
                trie[u].child[c] = trie.size();
                trie.push_back(node());
            }
            u = trie[u].child[c];
            trie[u].count++;
        }
    }
    long long common = 0;
    for (const string &i : s)
    {
        int u = 0;
        for (int j = i.size() - 1; j >= 0; j--)
        {
            int c = i[j] - 'a';
            if (trie[u].child[c] == -1)
                break;
            u = trie[u].child[c];
            common += trie[u].count;
        }
    }
    cout << 2ll * n * sum - 2ll * common << endl;
    return 0;
}
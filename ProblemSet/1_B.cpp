#include <iostream>
using namespace std;

int string_to_int(string str)
{
    int result = 0;
    for (int i = 0; i < str.length(); i++)
        result = result * 10 + (str[i] - '0');
    return result;
}

int main()
{
    long long int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        if (s[0] == 'R' && isdigit(s[1]) && s.find('C') != string::npos)
        {
            int p = s.find('C');
            string row_s = s.substr(1, p - 1);
            string col_s = s.substr(p + 1);
            int row = string_to_int(row_s);
            int col = string_to_int(col_s);
            string column = "";
            while (col > 0)
            {
                col--;
                column = char('A' + (col % 26)) + column;
                col /= 26;
            }
            cout << column << row << endl;
        }
        else
        {
            int p = 0;
            while (isalpha(s[p]))
                p++;
            string col_s = s.substr(0, p);
            string row_s = s.substr(p);
            int row = string_to_int(row_s);
            int column = 0;
            for (int i = 0; i < col_s.length(); i++)
                column = column * 26 + (col_s[i] - 'A' + 1);
            cout << "R" << row << "C" << column << endl;
        }
    }
    return 0;
}
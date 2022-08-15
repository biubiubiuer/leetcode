#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int x;
int main()
{
    cin >> x;
    if (x % 11 == 0) 
    {
        cout << "True" << endl;
        return 0;
    }

    int one_num = 0;
    while (x)
    {
        int v = x % 10;
        if (v == 1) one_num++;
        if (one_num >= 2) 
        {
            cout << "True" << endl;
            return 0;
        }
        x /= 10;
    }
    cout << "False" << endl;
    return 0;
}
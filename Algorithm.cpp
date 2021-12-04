#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
static int g_n;

void SubsetBySet(string str, int len, int* _set)
{
    if (!len) {
        for (int i = 0; i < g_n; i++)
            if (str[i] == '1')
                cout << _set[i] << " ";
        cout << endl;
        return;
    }
    SubsetBySet(str + '0', len - 1, _set);
    SubsetBySet(str + '1', len - 1, _set);
}

int main()
{
    int* _set;
    int* _set3;
    g_n = 3;

    _set3 = new int[g_n];
    cout << "Set for 3" << endl;
    for (int i = 0; i < g_n; i++) {
        _set3[i] = i + 1;
        cout << _set3[i] << " ";
    }
    cout << endl;

    cout << "Subset";
    SubsetBySet("", g_n, _set3);

    cout << "O(n)"<< endl;


    cout << "n = ";
    cin >> g_n;

    _set = new int[g_n];
    cout << "Set" << endl;
    for (int i = 0; i < g_n; i++) {
        _set[i] = i + 1;
        cout << _set[i] << " ";
    }
    cout << endl;

    cout << "Subset";
    SubsetBySet("", g_n, _set);
    delete[] _set;
    delete[] _set3;

    return 0;
}

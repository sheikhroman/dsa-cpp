#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size;
    cin >> size;
    int array[size];
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    char c;
    cout << "Do you want to search: (Y/N)" << endl;
    cin >> c;
    while (toupper(c) == 'Y')
    {
        int CheckValue;
        cout << "Please enter the value : ";
        cin >> CheckValue;
        int flag = 0;
        for (int i = 0; i < size; i++)
        {
            if (array[i] == CheckValue)
            {
                flag = 1;
                cout << "index no:" << i << " Position :" << i + 1 << endl;
            }
        }
        if (flag == 0)
        {
            cout << "Value not found" << endl;
        }
        cout << "Do you want to continue searching (Y/N)" << endl;
        cin>>c;
    }
    return 0;
}
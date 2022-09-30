#include <bits/stdc++.h>
using namespace std;

int bianarySearch(int array[], int x, int lb, int ub)
{
    if (lb <= ub)
    {
        // x== array[mid]
        int mid = (lb + ub) / 2;
        if (x == array[mid])
        {
            return mid;
        }

        // arrar mid
        else if (x > array[mid])
            bianarySearch(array, x, mid + 1, ub);

        // x<array[mid]
        else
            bianarySearch(array, x, lb, mid - 1);
    }
    else
        return -1;
}

int main()
{
    int size;
    cin >> size;
    int array[size];
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    int checkValue;
    cout << "Please enter value to search : ";
    cin >> checkValue;
    int indexNumber;
    indexNumber = bianarySearch(array, checkValue, 0, size - 1);
    if (indexNumber != -1)
    {
        cout << "Index number: " << indexNumber << " Position number: " << indexNumber + 1 << endl;
    }
    else
    {
        cout << "Value not found" << endl;
    }
    return 0;
}
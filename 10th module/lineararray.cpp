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
  cout << "Do u want to search (Y/N)" << endl;
  cin >> c;
  while (toupper(c) == 'Y')
  {
    int CheckValue;
    cout << "Please enter the value you want to check: ";
    cin >> CheckValue;
    int flag = 0;

    for (int i = 0; i < size; i++)
    {
      if (array[i] == CheckValue)
      {
        flag = 1;
        cout << "Index no : " << i << " Position " << i + 1 << endl;
        break;
      }
    }

    if (flag == 0)
    {
      cout << "Value not found" << endl;
    }
    cout << "Do u want to contiune searching (Y/N)" << endl;
  }
  return 0;
}
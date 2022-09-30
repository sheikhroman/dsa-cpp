#include <bits/stdc++.h>
using namespace std;

void printArray(int array[], int n){
    for (int i = 0; i < n; i++){
        cout<< array[i] << "";
    }
    cout << endl;
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
    cout << "Before Sort: ";
    printArray(array, size);
    //step 1 Finding Max
    int max = INT_MIN;
    for (int i = 0; i < size; i++){
        if(array[i]>max)
            max = array[i];
    }
    // step 2 Init og Count
    int count[max + 1];
    for (int i = 0; i <=max;i++){
        count[i] = 0;
    }
    // step 3  Frequancy Calculation
    for (int i = 0; i < size; i++){
        count[array[i]]++;
    }
    cout << "Frequancy: ";
    printArray(count, max + 1);
    //step 4 Cumulative sum
    for (int i = 1; i < size; i++){
        count[i] += count[i - 1];
    }
    cout << "Cumulative sum: ";
    printArray(count, max + 1);
    // step 5 Final array
    int final[size];
    for (int i = size - 1; i >= 0; i--){
        count[array[i]]--;
        int k = count[array[i]];
        final[k] = array[i];
    }
    cout << "After Sort: ";
    printArray(final, size);
        return 0;
}
#include<bits/stdc++.h>
using namespace std;

void PrintArray(int array[], int size){
    for (int i = 0; i < size; i++){
    cout<<array[i]<<" ";
    }
    cout << endl;
}

int main(){
    int array[50];
    int size;
    cin >> size;
    for (int i = 0; i < size;i++){
        cin >> array[i];
    }
    cout << "Given Array ";
    PrintArray(array, size);

    //size-1 ----> position
    int pos,value;
    cout << "Position of the Deletion: ";
    cin >>pos;
    //cout<<"Value of the Deletion: ";
    //cin >> value;
    if(pos<0||pos>size){
        cout << "Invalid Index";
    } else{
        
    }
       //Deletion
       if(pos==size-1)           
       size--;
        else{
        // pos+1___> size-1
        for (int i = pos + 1; i < size; i++)
        {
            array[i - 1] = array[i];
        }
        size--;
    }
    cout << "Array after the delation: ";
    PrintArray(array, size);
    return 0;
}
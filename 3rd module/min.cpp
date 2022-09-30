#include<bits/stdc++.h>
using namespace std;
int main(){
    // int a = 10, b = 20;
    // int mn;
    // mn=max(a,b);
    // cout<<mn<<endl;

    // int a=10, b=30, c=20;
    // int mn;
    // mn=min(a,min(b,c));
    // cout<<mn<<endl;
    
    //array min max
    // int arr[5]={2,3,1,4,5};
    // int mn=arr[0];
    // for (int i = 1; i < 5; i++){
    //     if(arr[i]<mn){
    //         mn=arr[i];
    //     }
    // }
    // cout<<mn<<endl;

    //min max arr of
    int arr[5]={5,2,3,1,4};
    int mn=arr[0];
    for (int i = 1; i < 5; i++){
        mn = min(mn, arr[i]);
        cout<<"index - "<<i<<"->"<<mn<<endl;
    }
    cout<<mn<<endl;

        return 0;
}
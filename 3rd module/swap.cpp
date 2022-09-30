#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[]={2,3,1,4,5,} ,n=5;
    for (int i = 0; i<n-1; i++){
        for (int j = i + 1; j < n; j++){
            if(a[i]>a[j]){
                swap(a[i],a[j]);
            }
        }
        }
        for (int i = 0; i < n;i++){
            cout<<a[i]<<endl;
        }
}
#include<bits/stdc++.h>
using namespace std;
void print(int *x){
    *x = 2500;
}
int main(){
    int a = 10;
    int *ptr = &a;
    print(ptr);
    cout<<a<<endl;
    return 0;
}
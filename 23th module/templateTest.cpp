#include<bits/stdc++.h>
using namespace std;

template<typename T> T myMax(T a, T b){
    return(a > b) ?a : b;
}
int main (){
    cout << myMax<int>(3, 7) << endl;
    cout << myMax<float>(3.5, 7.9) << endl;
    cout << myMax<char>('a','f') << endl;
}
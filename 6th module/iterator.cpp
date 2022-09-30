#include<bits/stdc++.h>
using namespace std;

int main(){
    string st = "abcdefghij";
    for (auto it = st.rbegin(); it != st.rend(); it++){
        cout << *it << endl;
    }
    return 0;
}
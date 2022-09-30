#include<bits/stdc++.h>
#include "myqueue.h"
using namespace std;
typedef pair<char, int> mytype;
int main(){
    Queue<mytype> q;
    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        char c1;
        int c2;
        cin >> c1>>c2;
        q.push(make_pair(c1,c2));
    }
        // while(!q.empty()){
        //     mytype chk;
        //     chk = q.pop();
        //     cout << chk.first<<" | "<<chk.second <<endl;
        // }
        cout << endl << endl;
        if(!q.empty()){
            mytype chk;
            chk = q.Front();
            cout << chk.first<<" | "<<chk.second <<endl;
        }
        if(!q.empty()){
            mytype chk;
            chk = q.Back();
            cout << chk.first<<" | "<<chk.second <<endl;
        }

    return 0;
}
#include<bits/stdc++.h>
#include"myStack.h"
#include"myqueue.h"
using namespace std;

/*
11 3
1 2 3 4 5 6 7 8 9 10 11
-->3 2 1 6 5 4 9 8 7 11 10

10 5
10 20 30 40 50 60 70 80 90 100
--> 10 5
10 20 30 40 50 60 70 80 90 100

*/

void reverseKElements(int n, int k, Queue<int>&q){
    int x = n / k;
    int y = n % k;
    Stack<int> st;
    while(x>0){
        int chk = k;
        while(chk>0){
            st.push(q.pop());
            chk--;
        }
        while(!st.empty()){
            q.push(st.pop());
        }
        x--;
    }
    while(y>0){
        y--;
        st.push(q.pop());
        }
        while(!st.empty()){
            q.push(st.pop());
        }
}

int main(){
    int n, k;
    cin >> n >> k;
    Queue<int> q;
    for (int i = 0; i < n;i++){
        int val;
        cin >> val;
        q.push(val);
    }
    reverseKElements(n,k,q);
    while(!q.empty()){
        cout << q.pop()<< " ";
    }
    cout << endl
         << endl;

    return 0;
}
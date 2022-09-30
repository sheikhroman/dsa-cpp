#include<bits/stdc++.h>
#include "myStack.h"
using namespace std;

int prefixEveluation(string chk){
    Stack<int> st;
    for (int i = chk.length() - 1; i >= 0; i--){
        //chk[i] 0 to 9 --> operand
        if(chk[i]>= '0' && chk[i]<='9'){
            st.push(chk[i] - '0');
        }
        //chk[i]--> operator
        else{
            int a = st.pop();
            int b = st.pop();
            switch (chk[i])
            {
            case '+':
                st.push(a + b);
                break;
            case '-':
                st.push(a - b);
                break;
            case '*':
                st.push(a * b);
                break;
            case '/':
                st.push(a / b);
                break;
            case '^':
                st.push(pow(a, b));
                break;            
            default:
                break;
            }
        }

    }
    return st.Top();
}
//+*423
//-+7*45+20

int main(){
    cout << prefixEveluation("-+7*45+20")<<endl <<endl;

    return 0;
}
#include <bits/stdc++.h>
#include "myStack.h"
using namespace std;

bool balanceParenthesis(string s)
{
    int n = s.size();
    Stack<char> st;
    bool isBalance = true;
    if (s[0] == ')' || s[0] == '}' || s[0] == ']')
    {
        return false;
    }

    for (int i = 0; i < n; i++)
    {
        // Opening Braket ->({[
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        // Closing Braket ->)}]

        //-> ( st.top==(st.pop else isBalance = false break
        else if (s[i] == ')')
        {
            if (st.Top() == '(')
            {
                st.pop();
            }
            else
            {
                isBalance = false;
                break;
            }
        }

        else if (s[i] == '}')
        {
            if (st.Top() == '{')
            {
                st.pop();
            }
            else
            {
                isBalance = false;
                break;
            }
        }

        else if (s[i] == ']')
        {
            if (st.Top() == '[')
            {
                st.pop();
            }
            else
            {
                isBalance = false;
                break;
            }
        }
    }
    if (!st.empty())
    {
        isBalance = false;
    }
    return isBalance;
}
int main()
{
    string chk;
    cin >> chk;
    if (balanceParenthesis(chk))
        cout << "YES";
    else
        cout << "NO";
    cout << endl;
    return 0;
}
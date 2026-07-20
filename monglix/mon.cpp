#include <iostream>
#include <stack>
#include <string>
using namespace std;

int longestValidParentheses(string s)
{
    stack<int> st;
    st.push(-1);

    int maxLength = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else
        {
            st.pop();
            if (st.empty())
            {
                st.push(i);
            }
            else
            {
                int length = i - st.top();
                if (length > maxLength)
                {
                    maxLength = length;
                }
            }
        }
    }

    return maxLength;
}

int main()
{
    string s;
    cin >> s;

    cout << longestValidParentheses(s);

    return 0;
}
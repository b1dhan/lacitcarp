#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string str;
    stack<char> st;
    bool bStarted = false;
    bool valid = true;
    int aCount = 0, bCount = 0;

    cout << "Enter the string: ";
    cin >> str;

    for (char ch : str)
    {
        if (ch != 'a' && ch != 'b')
        {
            cout << "String not accepted.\nPlease enter a string over {a,b}" << endl;
            return 0;
        }

        if (ch == 'a')
        {
            if (bStarted)
            {
                valid = false;
                break;
            }
            st.push('a');
            aCount++;
        }
        else
        {
            bStarted = true;
            bCount++;

            if (st.empty())
            {
                valid = false;
                break;
            }

            st.pop();
        }
    }

    if (valid && st.empty() && aCount > 0 && bCount > 0 && aCount == bCount)
        cout << "String accepted" << endl;
    else
        cout << "String not accepted" << endl;

    return 0;
}

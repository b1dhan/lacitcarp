#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    int state = 0; 

    cout << "Enter the string: ";
    cin >> str;

    for (char ch : str)
    {
        if (ch != 'a' && ch != 'b')
        {
            cout << "String not accepted.\nPlease enter a string over {a,b}" << endl;
            return 0;
        }

        
        if (state == 0)
        {
            if (ch == 'a')
                state = 1;
            else
                state = 0; 
        }
        else if (state == 1)
        {
            if (ch == 'a')
                state = 1; 
            else
                state = 2; 
        }
        else if (state == 2)
        {
            if (ch == 'a')
                state = 1;
            else
                state = 0;
        }
    }

    if (state == 0 || state == 1)
        cout << "String accepted" << endl;
    else
        cout << "String not accepted" << endl;

    return 0;
}

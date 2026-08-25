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
if (ch != '0' && ch != '1')
{
cout << "String not accepted.\nPlease enter a string over {0,1}" << endl;
return 0;
}

if (state == 0) {
if (ch == '1') state = 1;
else state = 0;
}
else if (state == 1) {
if (ch == '1') state = 2; 
else state = 0; 
}
else if (state == 2) {
if (ch == '1') state = 2; 
else state = 0; 
}
}

if (state == 2)
cout << "String accepted" << endl;
else
cout << "String not accepted" << endl;

return 0;
}

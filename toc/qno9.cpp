#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// The 5 exact states from the transition table
enum State {
Q0, // Initial / Mark 'a' -> X
Q1, // Find 'b' -> Y
Q2, // Rewind left to X
Q3, // Verify remaining Y's
Q4 // Accept (Halt)
};

class TuringMachine {
private:
string tape;
int head;
State state;

public:
TuringMachine(const string& input)
: tape(input + 'B'), head(0), state(Q0) {}

// Converts state enum to string for clean output printing
string getStateName(State s) const {
switch (s) {
case Q0: return "q0";
case Q1: return "q1";
case Q2: return "q2";
case Q3: return "q3";
case Q4: return "q4";
default: return "REJECT";
}
}

// Prints the instantaneous description (ID) of the tape: e.g., Xa[q1]bb
void printTapeID() const {
for (int i = 0; i < tape.length(); i++) {
if (i == head) {
cout << "[" << getStateName(state) << "]";
}
cout << tape[i];
}
cout << endl;
}

bool run(bool verbose = true) {

if (verbose) cout << "Step-by-step execution trace:\n";

while (true) {
if (verbose) printTapeID();

// Accept condition
if (state == Q4) {
return true;
}

char currentSymbol = tape[head];

// Transition Table Logic
switch (state) {

case Q0:
if (currentSymbol == 'a') {
tape[head] = 'X'; head++; state = Q1;
} else if (currentSymbol == 'Y') {
tape[head] = 'Y'; head++; state = Q3;
} else {
return false; // Invalid transition -> REJECT
}
break;

case Q1:
if (currentSymbol == 'a') {
tape[head] = 'a'; head++; state = Q1;

} else if (currentSymbol == 'Y') {
tape[head] = 'Y'; head++; state = Q1;
} else if (currentSymbol == 'b') {
tape[head] = 'Y'; head--; state = Q2;
} else {
return false; // Missing matching 'b'
}
break;

case Q2:
if (currentSymbol == 'a') {
tape[head] = 'a'; head--; state = Q2;
} else if (currentSymbol == 'Y') {
tape[head] = 'Y'; head--; state = Q2;
} else if (currentSymbol == 'X') {
tape[head] = 'X'; head++; state = Q0;
} else {
return false;
}
break;

case Q3:
if (currentSymbol == 'Y') {
tape[head] = 'Y'; head++; state = Q3;
} else if (currentSymbol == 'B') {
tape[head] = 'B'; head++; state = Q4; // Reached end, ACCEPT
} else {
return false; // Found extra unexpected symbol (e.g. extra 'b')

}
break;

default:
return false;
}
}
}
};

int main() {
string input;
cout << "Enter input string (containing 'a' and 'b'): ";
cin >> input;

TuringMachine tm(input);
bool accepted = tm.run(true);

cout << "\n----------------------------------------\n";
if (accepted) {
cout << "Result: ACCEPTED! String belongs to L = {a^n b^n | n >= 1}\n";
} else {
cout << "Result: REJECTED! String does not match L = {a^n b^n | n >= 1}\n";
}
cout << "----------------------------------------\n";

return 0;
}

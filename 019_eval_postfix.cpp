/*
TODO: 1. Add support for expressions with parenthesis.
      2. Add support for other operations.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <stack>

inline bool isOperand(const std::string &expr)
{
    return expr.find_first_not_of("0123456789") == std::string::npos;
}

// Expression must contain only integers.
// Performs integer divisions, so result may not be exact.
// Allowed operations are: + , - , * and /
int evalPostfix(const std::string &expr)
{
    using namespace std;
    stringstream ss{expr};
    string token;
    stack<int> ops;
    while (ss >> token) // When stream is empty, its state changes.
    {
        if (isOperand(token))
        {
            ops.push(stoi(token));
        }
        else
        {
            int op2 = ops.top();
            ops.pop();
            int op1 = ops.top();
            ops.pop();

            if      (token == "+")  ops.push(op1 + op2);
            else if (token == "-")  ops.push(op1 - op2);
            else if (token == "*")  ops.push(op1 * op2);
            else if (token == "/")  ops.push(op1 / op2);
        }
    }

    return ops.top();
}

int main()
{
    using namespace std;

    string postfixExp{"2 3 + 4 5 * 6 / -"};   // 2 + 3 - 4 * 5 / 6 = 2
    cout << "Result: " << evalPostfix(postfixExp) << endl;

    return 0;
}

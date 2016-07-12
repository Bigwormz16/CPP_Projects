#include <iostream>
#include <sstream>
#include <string>
#include <stack>

inline bool isOperand(const std::string &expr)
{
    return expr.find_first_not_of("0123456789") == std::string::npos;
}

int evalPrefix(const std::string &expr)
{
    using namespace std;

    stack<string> tokens;
    stringstream ss{expr};
    string tk;
    while (ss >> tk)    // When stream is empty, its state changes.
    {
        tokens.push(tk);
    }

    stack<int> ops;
    // Traverse the tokens of the expression from right to left.
    while (!tokens.empty())
    {
        string token = tokens.top();
        tokens.pop();
        if (isOperand(token))
        {
            ops.push(stoi(token));
        }
        else
        {
            int op1 = ops.top();
            ops.pop();
            int op2 = ops.top();
            ops.pop();

            if      (token == "+")   ops.push(op1 + op2);
            else if (token == "-")   ops.push(op1 - op2);
            else if (token == "*")   ops.push(op1 * op2);
            else if (token == "/")   ops.push(op1 / op2);
        }
    }

    return ops.top();
}

int main()
{
    using namespace std;

    string prefixExp{"- + 2 3 / * 4 5 6"};   // 2 + 3 - 4 * 5 / 6 = 2
    cout << "Result: " << evalPrefix(prefixExp) << endl;

    return 0;
}

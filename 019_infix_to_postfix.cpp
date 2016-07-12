/*
TODO: 1. Add support for expressions with parenthesis.
      2. Add support for associativity
      3. Strip any leading or trailing whitespace.
      4. Add support for more operations.
*/

#include <string>
#include <iostream>
#include <sstream>
#include <stack>

// std::string inToPost_withParen(const std::string &infixExp)
// {
//     using namespace std;
//
//     string postfixExp;
// }

bool hasParen(const std::string &exp)
{
    using namespace std;
    if (exp.find('(') != string::npos ||
        exp.find('[') != string::npos ||
        exp.find('{') != string::npos)
        return true;
    else
        return false;
}

inline bool isOperand(const std::string &str)
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}

/* Warning: This is a custom precedence comparison function tailored to this program. */
// If a has higher precedence than b.
// In case of same precedence, return true (for left to right associativity).
bool hasHigherPrec(const std::string &first, const std::string &second)
{
    char a = first[0];
    char b = second[0];
    if (a == b)
    {
        // If same operators, assuming left->right associativity applies because
        // we are assigning the operators that have come before to 'a' and the
        // current token to 'b'.
        return true;
    }
    switch (a)
    {
        case '+':
            switch (b)
            {
                case '-':   return true;
                case '*':   return false;
                case '/':   return false;
            }
        case '-':
            switch (b)
            {
                case '+':   return true;
                case '*':   return false;
                case '/':   return false;
            }
        case '*':
            switch (b)
            {
                case '+':   return true;
                case '-':   return true;
                case '/':   return true;
            }
        case '/':
            switch (b)
            {
                case '+':   return true;
                case '-':   return true;
                case '*':   return true;
            }
    }
}

std::string inToPost(const std::string &infixExp)
{
    using namespace std;

    string postfixExp;
    // if (hasParen(infixExp))
    // {
    //     postfixExp = inToPost_withParen(infixExp);
    // }
    // else
    // {
        stack<string> operators;
        stringstream ss{infixExp};
        string currentToken;
        while (ss >> currentToken)  // When stream is empty, its state changes.
        {
            if (isOperand(currentToken))
            {
                postfixExp.append(currentToken + " ");
            }
            else    // if currentToken is an operator
            {
                // Check if the stack has any operator of higher precedence than
                // the currentToken
                while (!operators.empty() && hasHigherPrec(operators.top(), currentToken))
                {
                    postfixExp.append(operators.top() + " ");
                    operators.pop();
                }

                // Push the currentToken onto the stack because we haven't seen
                // which operators lie after of the currentToken.
                operators.push(currentToken);
            }
        }

        // After we've reached the end of the expression, pop any remaining
        // operators from the stack and append them at the end of the postfixExp.
        while (!operators.empty())
        {
            postfixExp.append(operators.top() + " ");
            operators.pop();
        }
    // }
    // strip trailing whilespace

    return postfixExp;
}

int main()
{
    using namespace std;

    // Using 'space' as the delimeter.
    // 2 + 3 * 5 / (9 - 7) + [3 * 5]
    string infixExp{"2 + 3 * 5 / 9 - 7 + 3 * 5"};   // 2 3 5 * 9 / + 7 - 3 5 * +
    //getline(cin, infixExp);
    cout << "The postfix representation is:\n" << inToPost(infixExp) << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

/**
 *
 * Project : Converting Infix to Postfix & Evaluating Postfix Expression.
 * author  : Mohamed Abdalazez Abdallah Mohamed
 *
 **/

int precedence(char c)
{
  if (c == '(')
    return 0;
  if (c == '+' || c == '-')
    return 1;
  if (c == '*' || c == '/' || c == '%')
    return 2;
  return -1;
}

int operation(int b, int a, string c)
{
  if (c == "+")
    return b + a;
  else if (c == "-")
    return b - a;
  else if (c == "*")
    return b * a;
  else if (c == "/")
  {
    if (a != 0)
      return b / a;
    else
      return -1;
  }
  else if (c == "%")
    return b % a;
  else
    return -1;
}

bool isOperand(string c)
{
  return (c == "+" || c == "-" || c == "*" || c == "/" || c == "%" ? true : false);
}

vector<string> convertFromInfixToPostfix(string s)
{
  string number = "";
  char Operator;
  vector<string> Postfix;
  stack<char> op, temp;
  for (auto it : s)
  {
    if (isdigit(it))
    {
      number += it;
    }
    else
    {
      if (number != "")
      {
        Postfix.push_back(number);
        Postfix.push_back(" ");
        number = "";
      }
      if (it != ' ')
      {
        Operator = it;
        if (Operator == ')')
        {
          while (op.top() != '(')
          {
            string symbol = "";
            symbol += op.top();
            Postfix.push_back(symbol);
            Postfix.push_back(" ");
            op.pop();
          }
          op.pop();
          continue;
        }
        if (op.empty() || Operator == '(' || precedence(Operator) > precedence(op.top()))
        {
          op.push(Operator);
        }
        else
        {
          if (precedence(Operator) <= precedence(op.top()))
          {
            while (precedence(Operator) <= precedence(op.top()))
            {

              string symbol = "";
              symbol += op.top();
              Postfix.push_back(symbol);
              Postfix.push_back(" ");
              op.pop();
              if (op.empty())
                break;
            }
            op.push(Operator);
          }
        }
      }
    }
  }
  if (number != "")
  {
    Postfix.push_back(number);
    Postfix.push_back(" ");
    number = "";
  }
  if (!op.empty())
  {
    while (!op.empty())
    {
      string symbol = "";
      symbol += op.top();
      Postfix.push_back(symbol);
      Postfix.push_back(" ");
      op.pop();
    }
  }
  return Postfix;
}

int Evaluating_A_PostfixExpression(vector<string> Post)
{
  int ans = 0;
  stack<int> operand, temp;
  for (auto it : Post)
  {

    if (!isOperand(it) && !it.empty())
    {
      // cout << "hi : " << it << endl;
      stringstream conv(it);
      int num = -1;
      conv >> num;
      if (num != -1)
        operand.push(num);
    }
    if (isOperand(it))
    {
      int a, b, sum;
      a = operand.top();
      operand.pop();
      b = operand.top();
      operand.pop();
      if (a == 0 && it == "/")
      {
        ans = -1;
        goto done;
      }
      sum = operation(b, a, it);
      operand.push(sum);
      if (!operand.empty())
        ans = operand.top();
    }
  }
done:
  return ans;
}

int main()
{
  string s;
  printf("Type an infix expression and press Enter\n");
  getline(cin, s);
  int value = Evaluating_A_PostfixExpression(convertFromInfixToPostfix(s));
  if (value == -1)
  {
    cout << "Math ERROR\n";
  }
  else
  {
    printf("The Postfix form is\n");
    for (auto it : convertFromInfixToPostfix(s))
      cout << it;
    printf("\n");
    printf("Its value is : ");
    cout << value << endl;
  }
  return 0;
}

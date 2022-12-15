#include "stack.hpp"
#include <string>
#define MAX_STRLEN 256


class Converter
{
protected:
  Stack<char> stack;

  int precedence(char ch)
  {
    switch (ch)
    {
    case '^':
      return 5;
      break;
    case '/':
    case '%':
      return 4;
      break;
    case '*':
      return 3;
      break;
    case '+':
      return 2;
      break;
    case '-':
      return 1;
      break;
    }
    return -1;
  }

  void swap(char &a, char &b)
  {
    char t = b;
    b = a;
    a = t;
    return;
  }

  void reverseStr(string &str)
  {
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
      swap(str[i], str[n - i - 1]);
    return;
  }

public:
  void infixToPostfix(string &infixString, string &postfixString)
  {
    char ch;
    postfixString.clear();
    int length = infixString.length();
    for (int i = 0; i < length; i++)
    {
      if (infixString[i] == ' ')
        continue;
      else if (isalnum(infixString[i]))
        postfixString += infixString[i];
      else if (infixString[i] == '(')
        this->stack.push('(');
      else if (infixString[i] == ')')
      {
        while (!this->stack.isEmpty() && this->stack.top() != '(')
          postfixString += this->stack.pop();
        if (this->stack.top() == '(')
          ch = this->stack.pop();
      }
      else
      {
        while (!this->stack.isEmpty() &&
               precedence(infixString[i]) <= precedence(this->stack.top()))
          postfixString += this->stack.pop();
        this->stack.push(infixString[i]);
      }
    }
    while (!this->stack.isEmpty())
      postfixString += this->stack.pop();
    return;
  }

  void infixToPrefix(string &infixString, string &prefixString)
  {
    prefixString.clear();
    int length = infixString.length();
    reverseStr(infixString);
    for (int i = 0; i < length; i++)
    {
      if (infixString[i] == '(')
        infixString[i] = ')';
      else if (infixString[i] == ')')
        infixString[i] = '(';
    }
    this->infixToPostfix(infixString, prefixString);
    reverseStr(prefixString);
    return;
  }

  bool postfixToInfix(string &postfixString, string &infixString)
  {
    string op1, op2;
    infixString.clear();
    Stack<string> infixStack;
    int length = postfixString.length();
    for (int i = 0; i < length; i++)
    {
      if (isalnum(postfixString[i]))
        infixStack.push(string(1, postfixString[i]));
      else
      {
        op1 = infixStack.pop();
        op2 = infixStack.pop();
        infixStack.push("(" + op2 + postfixString[i] + op1 + ")");
      }
    }
    infixString = infixStack.pop();
    if(infixStack.isEmpty()){
    	return true;
	}
    return false;
  }

  bool prefixToInfix(string &prefixString, string &infixString)
  {
    string op1, op2;
    infixString.clear();
    Stack<string> infixStack;
    int length = prefixString.length();
    for (int i = length - 1; i >= 0; i--)
    {
      if (isalnum(prefixString[i]))
        infixStack.push(string(1, prefixString[i]));
      else
      {
        op1 = infixStack.pop();
        op2 = infixStack.pop();
        infixStack.push("(" + op1 + prefixString[i] + op2 + ")");
      }
    }
    infixString = infixStack.pop();
    if(infixStack.isEmpty()){
    	return true;
	}
    return false;
  }
};

int main(void)
{
  int choice;
  Converter convert;
  bool t=true;
  string str = "", str1 = "";
  do
  {
    cout << "\tMain Menu\n"
         << "==========================\n"
         << "  (1) Infix to Postfix\n"
         << "  (2) Infix to Prefix\n"
         << "  (3) Postfix to Infix\n"
         << "  (4) Prefix to Infix\n"
         << "  (0) Exit\n\n"
         << "Enter Choice: ";
    cin >> choice;
    cin.ignore();
    switch (choice)
    {
    case 1:
      cout << "Enter Infix Expression: ";
      getline(cin, str);
      convert.infixToPostfix(str, str1);
      cout << "Postfix Expression: " << str1 << endl;
      break;
    case 2:
      cout << "Enter Infix Expression: ";
      getline(cin, str);
      convert.infixToPrefix(str, str1);
      cout << "Prefix Expression: " << str1 << endl;
      break;
    case 3:
      cout << "Enter Postfix Expression: ";
      getline(cin, str);
      t=convert.postfixToInfix(str, str1);
      if(t){

      cout << "Infix Expression: " << str1 << endl;
	  }
	  else
	  {
	  	cout<<"error in expression "<<endl;
	  }
      break;
    case 4:
      cout << "Enter Prefix Expression: ";
      getline(cin, str);
      t=convert.prefixToInfix(str, str1);
      if(t){

      cout << "Infix Expression: " << str1 << endl;
	  }
	  else
	  {
	  	cout<<"error in expression "<<endl;
	  }
      break;
    }
  } while (choice != 0);
  return 0;
}


#include <iostream>
using namespace std;
const int MAX = 20; // Increased size to handle larger expressions
char Exp[MAX]; // Input infix expression
char opstack[MAX]; // Stack for operators
int top1 = -1; // Top of the operator stack
// Function to push an operator onto the stack
void oppush(char val1) {
if (top1 >= MAX - 1)
cout << "Stack Overflow" << endl;
else {
top1++;
opstack[top1] = val1;
}
}
// Function to pop an operator from the stack
char oppop() {
if (top1 <= -1) {
cout << "Stack Underflow" << endl;
return '\0'; // Return a null character to indicate an error
} else {
return opstack[top1--];
}
}
// Function to get the precedence of operators
int prec(char c) {
if (c == '^')
return 3;
else if (c == '/' || c == '*')
return 2;
else if (c == '+' || c == '-')
return 1;
else
return -1;
}
// Function to get the length of the expression
int size(const char* str) {
int length = 0;
while (str[length] != '\0') {
length++;
}
return length;
}
// Function to reverse the string in place
void reverseString(char* str) {
int start = 0;
int end = size(str) - 1;
char temp;
while (start < end) {
temp = str[start];
str[start] = str[end];
str[end] = temp;
start++;
end--;
}
}
// Function to convert infix expression to postfix
void infixToPostfix(const char* expression, char* postfix) {
top1 = -1; // Reset stack for new conversion
int pIndex = 0;
for (int i = 0; i < size(expression); i++) {
char c = expression[i];
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
postfix[pIndex++] = c;
} else if (c == '(') {
oppush(c);
} else if (c == ')') {
while (top1 != -1 && opstack[top1] != '(') {
postfix[pIndex++] = oppop();
}
if (top1 != -1 && opstack[top1] == '(')
oppop(); // Remove '('
} else {
while (top1 != -1 && prec(opstack[top1]) >= prec(c)) {
postfix[pIndex++] = oppop();
}
oppush(c);
}
}
// Pop and append all the operators left in the stack
while (top1 != -1) {
postfix[pIndex++] = oppop();
}
postfix[pIndex] = '\0'; // Null-terminate the postfix expression
}
// Function to convert infix expression to prefix notation
void infixToPrefix() {
char reversedExp[MAX];
char postfix[MAX];
char prefix[MAX];
// Copy Exp to reversedExp
int length = size(Exp);
for (int i = 0; i < length; i++) {
reversedExp[i] = Exp[i];
}
reversedExp[length] = '\0';
// Reverse the expression
reverseString(reversedExp);
// Replace '(' with ')' and vice versa
for (int i = 0; i < length; i++) {
if (reversedExp[i] == '(')
reversedExp[i] = ')';
else if (reversedExp[i] == ')')
reversedExp[i] = '(';
}
// Convert reversed infix to postfix
infixToPostfix(reversedExp, postfix); // Convert the reversed expression
// Reverse the postfix expression to get the prefix expression
reverseString(postfix);
// Copy postfix to prefix
int pLength = size(postfix);
for (int i = 0; i < pLength; i++) {
prefix[i] = postfix[i];
}
prefix[pLength] = '\0';
cout << "Prefix Expression: " << prefix << endl;
}
int main() {
cout << "Enter infix expression: ";
cin >> Exp; // Input the infix expression
int choice;
do {
cout << "Menu:\n";
cout << "1. Convert Infix to Postfix\n";
cout << "2. Convert Infix to Prefix\n";
cout << "3. Exit\n";
cout << "Enter your choice: ";
cin >> choice;
switch (choice) {
case 1:
{
char postfix[MAX];
infixToPostfix(Exp, postfix);
cout << "Postfix Expression: " << postfix << endl;
}
break;
case 2:
infixToPrefix();
break;
case 3:
cout << "Exiting...\n";
break;
default:
cout << "Invalid choice! Please enter a number between 1 and 3.\n";
break;
}
} while (choice != 3);
return 0;
}
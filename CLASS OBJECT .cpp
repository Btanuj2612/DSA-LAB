#include <bits/stdc++.h>
using namespace std;
class abcd {
  int st[5], n = 5, top = -1, val;

public:
  void push() {
    if (top >= n - 1)
      cout << "stack overflow" << endl;
    else {
      top++;
      st[top] = val;
    }
  }
  void pop() {
    if (top <= -1)
      cout << "stack under flow" << endl;
    else {
      cout << "The popped element is" << st[top] << endl;
      top--;
    }
  }

  void display() {
    if (top >= 0) {
      cout << "stack element are:";
      for (int i = top; i >= 0; i++)
        cout << st[i] << endl;
    } else
      cout << "stack is empty";
  }
};
int main() {
  int ch, val;
  abcd s1;

  cout << "1) Push in stack" << endl;
  cout << "2) Pop from stack" << endl;
  cout << "3) Display stack" << endl;
  cout << "4) Exit" << endl;

  do {
    cout << "enter the choice:";

    cin >> ch;

    switch (ch) {
    case 1: {
      cout << "Enter the value to be pushed:" << endl;
      cin >> val;
      s1.push();
      break;
    }
    case 2: {
      s1.pop();
      break;
    }
    case 3: {
      s1.display();
      break;
    }
    case 4: {
      cout << "exit:" << endl;
      break;
    }
    default: {
      cout << "Invalid choice" << endl;
    }
    }
  } while (ch != 4);
  return 0;
}
#include <iostream>
#include <string.h>
using namespace std;

int get_precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '(')
        return 0;
    return 0;
}

class Stack {
private:
    int size;
    int tos;
    char **arr;

public:
    Stack(int _size) {
        size = _size;
        arr = new char*[size];
        for (int i = 0; i < size; i++) {
            arr[i] = new char[100];
        }
        tos = -1;
    }

    void stack_push(const string &name) {   // make parameter const ref
        if (tos < size - 1) {
            strcpy(arr[++tos], name.c_str());
        } else {
            cout << "Stack is full\n";
        }
    }

    char* stack_pop() {
        if (tos > -1) {
            return arr[tos--];
        } else {
            return nullptr;
        }
    }


    bool isEmpty() {
        return tos == -1;
    }

    char* stack_top() {
    if (tos > -1) {
        return arr[tos];
    } else {
        return nullptr;
    }
}

    ~Stack() {
        for (int i = 0; i < size; i++)
            delete[] arr[i];
        delete[] arr;
    }
};

int main() {
    Stack s1(100);
    Stack s2(100);
    string temp = "";
    char num;
    string postfix = "";

    cout << "Enter infix expression: ";

    while (cin.get(num) && num != '\n') {
        if (isdigit(num)) {
            temp += num;
        } else {
            if (!temp.empty()) {
                s1.stack_push(temp);
                postfix += temp + " ";
                temp = "";
            }

            if (num == '(') {
                string t(1, num);//string(size_t n, char c);
                s2.stack_push(t);
            } else if (num == ')') {
                // pop until '('
                while (!s2.isEmpty() && *s2.stack_top()!= '(') {//because its return address so we make *s2.stack_top()
                    postfix += s2.stack_pop();
                    postfix += " ";
                }
                s2.stack_pop(); // pop '('
            } else if (num == '+' || num == '-' || num == '*' || num == '/') {
                while (!s2.isEmpty() && get_precedence(*s2.stack_top()) >= get_precedence(num)) {
                    postfix += s2.stack_pop();
                    postfix += " ";
                }
                string t(1, num);
                s2.stack_push(t);
            }
        }
    }

    if (!temp.empty()) {
        s1.stack_push(temp);
        postfix += temp + " ";
    }

    while (!s2.isEmpty()) {
        postfix += s2.stack_pop();
        postfix += " ";
    }

    cout << "\nPostfix expression: " << postfix << endl;

    return 0;
}

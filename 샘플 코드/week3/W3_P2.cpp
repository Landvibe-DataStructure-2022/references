#include <iostream>
#include <string>

using namespace std;

int t;

class Stack {
private:
    int arr[100]{};
    int size;

public:
    Stack() {
        size = 0;
    }

    bool empty() const {
        if (size == 0) {
            return true;
        } else {
            return false;
        }
    }

    void push(int x) {
        arr[size] = x;
        size++;
    }

    int pop() {
        size--;
        return arr[size];
    }

    int top() {
        return arr[size - 1];
    }
};

int main() {
    cin >> t;
    while (t--) {
        string str;
        Stack st = Stack();
        cin >> str;

        for (int i = 0; i < str.length(); i++) {
            if (str[i] - '0' >= 0 && str[i] - '0' <= 9) {
                st.push(str[i] - '0');
            } else {
                int num2 = st.pop();
                int num1 = st.pop();

                if (str[i] == '+') {
                    st.push((num1 + num2));
                } else if (str[i] == '-') {
                    st.push((num1 - num2));
                } else if (str[i] == '*') {
                    st.push((num1 * num2));
                }
            }
        }
        cout<<st.pop() % 10<<"\n";
    }
    return 0;
}
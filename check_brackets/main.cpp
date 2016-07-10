#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Bracket {
    Bracket(char type, int position):
            type(type),
            position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            Bracket current_stack(next, position);
            opening_brackets_stack.push(current_stack);
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            if (opening_brackets_stack.empty()) {
                std::cout << position + 1;
                return 0;
            }

            else {
                Bracket current_stack = opening_brackets_stack.top();
                if (current_stack.Matchc(next)) {
                    opening_brackets_stack.pop();
                }

                else {
                    std::cout << position+1;
                    return 0;
                }

            }
        }
    }

    if (opening_brackets_stack.empty())
        cout << "Success";
    else{
        Bracket current_stack = opening_brackets_stack.top();
        cout << current_stack.position+1;
    }

    return 0;
}

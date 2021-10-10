#include <string>
#include <sstream>
#include <set>
#include <exception>
#include "linkedlist.h"

using std::string;

static const string OPERATOR_DIVIDE = "/";
static const string OPERATOR_MULTIPLY = "*";
static const string OPERATOR_ADD = "+";
static const string OPERATOR_SUBTRACT = "-";

static const std::set<string> OPERATORS {
    OPERATOR_DIVIDE,
    OPERATOR_MULTIPLY,
    OPERATOR_ADD,
    OPERATOR_SUBTRACT
};

int apply_operation(string operation, int a, int b);

int evaluate_rpn(string expression) {
    SingleLinkedList sll;
    std::istringstream ss(expression);

    string token;
    while (ss >> token) {
        if (OPERATORS.find(token) == OPERATORS.end()) {
            sll.push_front(std::stoi(token));
            continue;
        }
        auto b = sll.pop_front();
        auto a = sll.pop_front();
        if (!(a && b)) {
            throw std::invalid_argument("Need two operands for an operator");
        }
        int result = apply_operation(token, a.get(), b.get());
        sll.push_front(result);
    }

    // Should have a single element left on it
    return sll.pop_front().get();
}

int apply_operation(string operation, int a, int b) {
    if (operation == "/") {
        return a / b;
    } else if (operation == "*") {
        return a * b;
    } else if (operation == "+") {
        return a + b;
    } else if (operation == "-") {
        return a - b;
    }
    throw std::invalid_argument("invalid operation" + operation);
}
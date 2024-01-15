#include <iostream>
#include <cctype> //se utiliza para verificar si un carácter es un dígito
using namespace std;

// Creación de los nodos
struct Node {
    char op;
    double value;
    Node* left;
    Node* right;

    // Constructor para operadores
    Node(char _op, Node* _left, Node* _right)
        : op(_op), value(0.0), left(_left), right(_right) {}

    // Constructor para números
    Node(double _value)
        : op('0'), value(_value), left(nullptr), right(nullptr) {}
};

// Función para crear un nodo de operador
Node* createNode(char op, Node* left, Node* right) {
    return new Node(op, left, right);
}

// Función para crear un nodo de número
Node* createNode(double value) {
    return new Node(value);
}

// Función para construir el AST a partir de una expresión matemática
Node* createAST(const std::string& expression, size_t& pos, int precedence);

// Función para construir un nodo de número en el AST
Node* createASTNumber(const std::string& expression, size_t& pos) {
    double value = 0.0;

    while (pos < expression.size() && (isdigit(expression[pos]) || expression[pos] == '.')) {
        value = value * 10 + (expression[pos] - '0');
        pos++;
    }

    return createNode(value);
}

// Función principal para construir el AST
Node* createAST(const std::string& expression, size_t& pos, int precedence) {
    Node* left = createASTNumber(expression, pos);

    while (pos < expression.size()) {
        char op = expression[pos];
        int opPrecedence;

        if (op == '+' || op == '-') {
            opPrecedence = 1;
        } else if (op == '*' || op == '/') {
            opPrecedence = 2;
        } else {
            break;  // No es un operador válido
        }

        if (opPrecedence <= precedence) {
            break;  // No es necesario continuar con este nivel de precedencia
        }

        pos++;

        Node* right = createAST(expression, pos, opPrecedence);

        left = createNode(op, left, right);
    }

    return left;
}

// Función para liberar la memoria del AST recursivamente
void freeAST(Node* root) {
    if (root == nullptr) {
        return;
    }
    freeAST(root->left);
    freeAST(root->right);
    delete root;
}

// Función para evaluar el AST recursivamente
double evaluateAST(Node* root) {
    if (root->op == '0') {
        return root->value;
    }

    double left_result = evaluateAST(root->left);
    double right_result = evaluateAST(root->right);

    if (root->op == '+') {
        return left_result + right_result;
    } else if (root->op == '-') {
        return left_result - right_result;
    } else if (root->op == '*') {
        return left_result * right_result;
    } else if (root->op == '/') {
        return left_result / right_result;
    } else {
        cerr << "Error: Operador desconocido." << endl;
        exit(EXIT_FAILURE);
    }
}

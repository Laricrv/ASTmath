#include <iostream>
#include <cctype> //se utiliza para verificar si un carácter es un dígito
#include "ASTfunciones.hpp" 
using namespace std;


// Función principal
int main() {
    string expression;
    cout << "Ingrese una expresión matemática: ";
    getline(cin, expression);

    size_t pos = 0;
    // Crear el AST a partir de la expresión ingresada
    Node* ast = createAST(expression, pos, 0);

    // Evaluar el AST y mostrar el resultado
    double result = evaluateAST(ast);
    cout << "Resultado: " << result << endl;

    // Liberar la memoria del AST
    freeAST(ast);

    return 0;
}

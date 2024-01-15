# ASTmath
# Calculadora Simple con Árbol de Sintaxis Abstracta (AST)

Este proyecto implementa una calculadora simple en C++ que utiliza un Árbol de Sintaxis Abstracta (AST) para analizar y evaluar expresiones matemáticas. La calculadora admite operaciones básicas como suma, resta, multiplicación y división.

## Estructura del proyecto

    main.cpp ---> Función principal, Contiene el código principal del programa, incluyendo la entrada del usuario, la construcción y evaluación del AST, y la liberación de la memoria.

    ASTfunciones.hpp ---> Contiene la definición de la estructura Node y las funciones relacionadas con la manipulación del AST, como la creación, evaluación y liberación de memoria.

##  Tecnologías utilizadas

    C++

## Uso

Al ejecutar el programa, se te pedirá que ingreses una expresión matemática. La calculadora analizará y evaluará la expresión utilizando un AST, y luego mostrará el resultado en la pantalla.

    Ingrese una expresión matemática: 5*5-6/10+2-4
    Resultado: 22.4


## Proceso de resolución

### Estructura del Nodo (Node):

    -Se define una estructura Node que representa un nodo en el AST.

    -Cada nodo puede ser un operador (op), un valor numérico (value), y tiene punteros a los nodos izquierdo (left) y derecho (right).

### Constructores del Nodo (createNode):

    -Se definen dos constructores para la estructura Node: uno para operadores y otro para números.

    -createNode(char op, Node* left, Node* right) crea un nodo para operadores.

    -createNode(double value) crea un nodo para números.

### Construcción del AST (createAST):

    -La función createAST toma una expresión matemática como entrada y crea el AST correspondiente.
    
    -Utiliza un enfoque de descenso recursivo, analizando la expresión de izquierda a derecha.
    
    -Maneja números y operadores, construyendo el AST en el proceso.

### Evaluación del AST (evaluateAST):

    -La función evaluateAST realiza una evaluación recursiva del AST.

    -Si un nodo es un número, simplemente devuelve ese valor.

    -Si es un operador, evalúa recursivamente los nodos izquierdo y derecho según la operación correspondiente.

### Entrada del Usuario (main):

    -En la función principal (main), se solicita al usuario que ingrese una expresión matemática.
    
    -La entrada del usuario se almacena en la variable expression.

### Creación y Evaluación del AST (createAST y evaluateAST):

    -Se llama a createAST con la expresión y se obtiene el puntero a la raíz del AST (ast).
    
    -Se llama a evaluateAST con la raíz del AST y se obtiene el resultado de la evaluación.

### Impresión del Resultado (std::cout):

    - Se imprime el resultado de la evaluación en la pantalla.

### Liberación de Memoria (freeAST):

    -Se llama a freeAST para liberar la memoria utilizada por los nodos del AST.
    -La función freeAST se encarga de liberar la memoria de manera recursiva, asegurándose de que todos los nodos del AST, incluyendo sus descendientes, sean eliminados correctamente.

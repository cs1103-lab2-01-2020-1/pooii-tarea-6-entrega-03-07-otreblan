Construir un arbol a partir de arrays en inorder y preorder
--

Dado 2 arrays de inorder y preorder traversal. Construir
un arbol e imprimir el postorder traversal.

Entrada:
--
La primera linea consiste de T casos de prueba. La primera linea
de cada caso de prueba consiste de N, representando el numero de
elementos en el array. El segundo array y tercera linea de cada
caso de prueba consiste en inorder y  preorder traversal del arbol.


Salida
--
Para cada caso de prueba, imprimir el postorder traversal en cada linea.

Tarea
--
La tarea a completar es crear una funcion llamada builTreePOSTOrd() el cual
tome 3 argumentos (inorder traversal array, preorder traversal array,
y el tamaño del arbol n) y retorna el root node del arbol construido.
No es necesario imprimir nada.

Complejidad: O(N*N)

Auxiliary Space: O(N)

Ejemplo:
--
    Input:
    2
    4
    1 6 8 7
    1 6 7 8
    6
    3 1 4 0 5 2
    0 1 3 4 2 5

    Output:
    8 7 6 1
    3 4 1 5 2 0

Explicación:
--
Test Case 2: El arbol construido será

            0
           / \
          1   2
        / \  /
       3  4 5

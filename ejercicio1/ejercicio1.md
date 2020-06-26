Inorder Traversal:
--
Dado un binary tree, encontrar el In-Order
traversal.

Entrada:
--
Primera linea de entrada contiene el numero
de casos de prueba T. Para cada caso de prueba, tenemos
solamente una linea de entrada el cual es un string
representado el arbol descrito abajo.

1.- Los valores en el string estan inorder level traversal del arbol
donde, numeros representan nodes, y el caracter "N" representan
hijos nulos.

2.- Ejemplo

![](img1.png?raw=true)

Para el arbol de arriba, la cadena va a ser: 1 2 3 N N 4 6 N 5 N N 7 N


Salida:
--
Para cada caso de prueba, en una nueva linea, imprimir inorder traversal.


Realizarlo en tiempo computacional O(N) y
Espacio Auxialiar: O(N)

Restricciones:
--
1 <= T <= 30
1 <= Numero de nodos <= 10^5


Ejemplo:
--
    Entrada:
    2
    1 3 2
    10 20 30 40 60 50


    Salida:
    3 1 2
    40 20 60 10 50 30

Explicación:
--
Caso de prueba 1:

        1
      /   \
     3     2

Entonces, inorder será: 3 1 2


Caso de prueba 2:

            10
          /    \
         20    30
        /  \   /
       40  60 50

Entonces, inorder será: 40 20 60 10 50 30

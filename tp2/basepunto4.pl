digitos(X) :- X < 10, write(X).
digitos(X) :- X > 9, Y is X mod 10 ,Z is X//10,digitos(Z),write(-), write(Y).  

sumaDigitos(X, X) :- X < 10.
sumaDigitos(X, Y) :- X > 9, A is X mod 10, Z is X//10, sumaDigitos(Z, B), Y is B + A.

digitosPares(X) :- X < 10, 0 is X mod 2.
digitosPares(X) :- X > 9, A is X mod 10, Z is X//10, digitosPares(Z), 0 is A mod 2.

digitoMayorValor(X,X) :- X < 10.
digitoMayorValor(X,Y) :- X > 9, A is X mod 10, Z is X//10, digitoMayorValor(Z, Mayor), Y is max(A,Mayor). 

listaDeNNumeros(N, Lista) :- findall(X, between(1, N, X), Lista).

cantidadElementos([], 0). 
cantidadElementos([_|Resto], N) :- cantidadElementos(Resto, N1), N is N1 + 1.

elementosOrdenados([]) :- true.
elementosOrdenados([_]) :- true.
elementosOrdenados([X|[Y|Z]]) :- X =< Y, elementosOrdenados([Y|Z]).
  

contadorXElemento(X,[],0). %CASO LISTA VACIA
contadorXElemento(X, [X|Resto], Contador) :- contadorXElemento(X, Resto, ContadorNuevo), Contador is ContadorNuevo + 1. %Esto funciona de manera que
%al ser recursivo la funcion se llama hasta que este vacio, luego, recursivamente resuelve uno a uno, es decir primero hace Contador es 0 + 1, luego recursivamente
%hace Contador is 1 + 1, suponiendo que tiene varios elementos, sigue Contador is 2 + 1, Contador is 3 + 1 y la ultima se resuelve con el total de veces que coincida
contadorXElemento(X, [Y|Resto],Contador) :- X \= Y,contadorXElemento(X, Resto, Contador).% en este caso la cabeza de la lista no coincide con X por lo que el contador%es el que ya venia
 
eliminarXOcurrencias(X, [], []). %caso lsita vacia
eliminarXOcurrencias(X, [X|Resto], Valores) :- eliminarXOcurrencias(X, Resto, Valores).
eliminarXOcurrencias(X, [Y|Resto], [Y|Valores]) :- X \= Y, eliminarXOcurrencias(X, Resto, Valores). 

cambiarOcurrencias(X,Y,[],[]). %caso lista vacia
cambiarOcurrencias(X,Y,[X|Resto],[Y|Valores]) :- cambiarOcurrencias(X,Y,Resto,Valores).
cambiarOcurrencias(X,Y,[Z|Resto],[Z|Valores]) :- X \= Z, cambiarOcurrencias(X,Y,Resto,Valores).

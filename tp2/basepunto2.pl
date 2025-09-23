cursa(calculo, juan).
cursa(calculo , pedro).
cursa(calculo, maria).
cursa(algebra, juan).
cursa(algebra, patricia).
cursa(estadistica, lucas).
cursa(elementos, pedro).
cursa(elementos, luisa).
cursa(elementos, ana).

%alumnoRegular(X) :- findall(Y, cursa(Y, X), Lista), length(Lista,2).

alumnoRegular(X) :-cursa(A,X), cursa(B,X), A \= B.     
companieros(X, Y) :-cursa(A,X), cursa(A, Y), X \= Y.

% EN PROLOG ¿Cuáles son los alumnos regulares? es alumnoRegular(X),
% ¿Qué materias tiene alumnos en común con cálculo? es cursa(calculo,X), cursa(A,X), A \= calculo.
%  ¿Quiénes son los alumnos que cursan una sola materia? cursa(A, X), cursa

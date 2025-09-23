progenitor(homer, bart).
progenitor(marge, bart).
progenitor(homer, lisa).
progenitor(marge, lisa).
progenitor(homer, maggie).
progenitor(marge, maggie).
progenitor(abraham, homer).
progenitor(mona, homer).
progenitor(abraham, herb).
progenitor(mona, herb).
progenitor(clancy, marge).
progenitor(jackie, marge).
progenitor(clancy, selma).
progenitor(jackie, selma).
progenitor(clancy, patty).
progenitor(jackie, patty).
progenitor(selma,ling).

femenino(maggie).
femenino(lisa).
femenino(ling).
femenino(marge).
femenino(patty).
femenino(selma).
femenino(jackie).
femenino(mona).
masculino(bart).
masculino(herb).
masculino(abraham).
masculino(homer).
masculino(clancy).

padreDe(X, Y) :- progenitor(X, Y), masculino(X).
madreDe(X, Y) :- progenitor(X, Y), femenino(X).
hijoDe(X, Y) :- (padreDe(Y, X) ; madreDe(Y, X)), masculino(X).
hijaDe(X, Y) :- (padreDe(Y, X) ; madreDe(Y, X)), femenino(X).
abuelo(X, Y) :- (padreDe(X, Z); madreDe(X, Z)),padreDe(Z, Y).
abuela(X, Y) :- (padreDe(X, Z); madreDe(X, Z)),madreDe(Z, Y).
hermanos(X, Y) :-  ((padreDe(Z, X), padreDe(Z, Y));(madreDe(Z, X), madreDe(Z, Y))),X \= Y. %me da algunos pares 2 veces,nada que hacerle
tio(X, Y) :- (padreDe(Z, Y); madreDe(Z, Y)), hermanos(X, Z), masculino(X). 		%me da algunos pares 2 vecs, nada que hacerle
tia(X, Y) :- (padreDe(Z, Y); madreDe(Z, Y)), hermanos(X, Z), femenino(X). 
primo(X, Y) :- (tio(Z, Y); tia(Z, Y)), hijoDe(X, Z).					%me da algunos pares 2 vecs, nada que hacerle
prima(X, Y) :- (tio(Z, Y); tia(Z, Y)), hijaDe(X, Z).					%me da algunos pares 2 vecs, nada que hacerle
bisabueloDe(X, Y) :- abuelo(Z, Y), padreDe(Z, X).






















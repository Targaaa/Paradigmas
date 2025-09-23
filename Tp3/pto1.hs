misterio1 n
 | n == 0 = 1
 | n == 1 = 3
 | otherwise = 9 * misterio1 (n - 2)

 -- esta funcion lo que hace es que al ingresar un numero n y te devuelve la potencia de 3 elevado a ese numero

misterio2 0 = 1
misterio2 n = (mod n 10) * misterio2 (div n 10)

--esta funcion da la multiplicacion de los digitos

--a. productoPorSumasSucesivas que reciba dos números naturales y realice el producto entre
--dichos números mediante sumas sucesivas.

productoPorSumasSucesivas n m  
 | n == 0 = 0
 | m == 0 = 0
 | otherwise = n + productoPorSumasSucesivas n (m-1)  

--sumaDigitosPares que reciba un número positivo y devuelva la suma de los dígitos pares que contiene.

sumaDigitosPares n
 | n < 0 = 0
 | n==0 = 0
 | mod n 2 == 0 = mod n 10 + sumaDigitosPares(div n 10)
 | otherwise = sumaDigitosPares(div n 10)

--c. contarMenores que dada una lista de números enteros cuente cuantos elementos de la lista son menores que 10.
--i. Realice una versión con Guards
--ii. Realice una versión con Pattern Matching
--iii. Realice una versión con List Comprehension

contarMenores xs 
 | null xs = 0
 | head xs < 10 = 1 + contarMenores(tail xs)
 | otherwise = contarMenores(tail xs) 

contarMenores2 [] = 0
contarMenores2 (x:xs) = if x < 10 then 1 + contarMenores2(xs) else contarMenores2(xs)

contarMenores3 z = length([x | x <- z, x < 10])

--eliminarIgualesX que reciba una lista y un número X y elimine de la lista todos los elementos iguales a X.
--i. Realice una versión con Guards
--ii. Realice una versión con Pattern Matching
--iii. Realice una versión con List Comprehension

eliminarIgualesX xs y
 | null xs = []
 | head xs == y = eliminarIgualesX (drop 1 xs) y
 | otherwise = head xs : eliminarIgualesX (drop 1 xs) y

eliminarIgualesX2 [] y = []
eliminarIgualesX2 (x:xs) y = if x == y then eliminarIgualesX2 xs y else x : eliminarIgualesX2 xs y  

eliminarIgualesX3 z y = [x| x <- z, x /= y]

--e. diferencia que reciba dos listas y devuelva los elementos de la primer lista que no se encuentran en la segunda lista.

diferencia xs ys
 | null xs = []
 | null ys = xs
 | head xs `elem` ys = diferencia (tail xs) ys  
 | otherwise = head xs : diferencia (tail xs) ys 

diferencia2 (x:xs) [] = (x:xs)
diferencia2 [] (y:ys) = []
diferencia2 (x:xs) (y:ys) = if x `elem` (y:ys) then diferencia2 xs (y:ys) else x : diferencia2 xs (y:ys) 

diferencia3 z y = [a | a<- z, not (elem a y)] --elem a y == False,es otra forma de hacerlo

--f. subLista1 que reciba una lista y un número natural n y retorne una lista sin los primeros n 
--elementos de la lista dada. No utilice drop. subLista1

subLista1 xs y
 | null xs = []
 | y > 0  = subLista1(tail xs) (y-1)
 |otherwise = head xs : subLista1(tail xs) y

subLista2 [] y = []
subLista2 (x:xs) y = if y > 0 then subLista2(xs) (y-1) else x : subLista2 (xs) y 

subLista3 z y = [x | (i,x) <-  zip [0..] z, i >= y]

--g. transformar que reciba como parámetros una función f (de un argumento) y una lista y devuelva
--como resultado la lista recibida en la que cada uno de sus elementos haya sido transformado con la función f.

--ejemplo
f h a xs 
 | null xs = []
 | a <=0 = [] 
 | otherwise = h (head xs) : f h (a-1) (tail xs)

transformar f xs
 | null xs = []
 | otherwise = f (head xs) : transformar f (tail xs)

transformar2 f [] = []
transformar2 f (x:xs) = f x : transformar2 f xs 

transformar3 f z = [f x | x <- z]

--h. tablaDePares que, dado un número natural n, construya una lista que contenga los números pares
--que se encuentran en el intervalo [ 0,n]. Use List Comprehension.

tablaDePares n = [x | x <- [0..n], (mod x 2) == 0]

-- paresOrdenados que construya una lista con todos los pares ordenados (x,y) posibles teniendo
--en cuenta que x corresponde a todos los números pares e y a los números impares entre 0 y 5
--donde se cumple la condición que x+y es menor a un valor Z dado. Use List Comprehension.

paresOrdenados z = [(x,y) | x <- [0..5], y <- [0..5], (mod x 2) == 0, (mod y 2) == 1, x+y < z]

--j. verificar que recibe un predicado p (un predicado es una función que devuelve un valor booleano)
--y una lista de elementos xs y devuelve True si todos los elementos de la lista satisfacen el
--predicado, caso contrario retorna False.
--i. Realice una versión con Guards
--ii. Realice una versión con Pattern Matching
--iii. Realice una versión con List Comprehension

verificar p xs
 | null xs = True
 | p (head xs) = verificar p (tail xs)
 | otherwise = False  

verificar2 p [] = True
verificar2 p (x:xs) = p x && verificar2 p xs 

verificar3 p z = null [x | x <- z, not (p x)]

--k. combinar que reciba una función f y dos listas y retorne una nueva lista que resulta de la
--combinación las listas aplicando la función f. La función f debe recibir como parámetro un elemento
--de cada lista a combinar por vez. Utilice la siguiente definición de tipo para su función:
--combinarCon :: (a -> b -> c) -> [a] -> [b] -> [c]
--i. Realice una versión con Guards
--ii. Realice una versión con Pattern Matching
--iii. Realice una versión con List Comprehension

combinar1 f xs ys 
 | null xs || null ys = []
 | otherwise = f (head xs) (head ys) : combinar1 f (tail xs) (tail ys)

combinar2 f _ [] = []
combinar2 f [] _ = []
combinar2 f (x:xs) (y:ys) = f x y : combinar2 f xs ys 

combinar3 f xs ys = [f x y| (x,y) <- zip xs ys]

--l. filtrarLista que reciba un predicado y una lista y luego regresa la lista de elementos que satisfacen
--el predicado. La signatura de la función debería ser:
--filtrarLista :: (a -> Bool) -> [a] -> [a]
--i. Realice una versión con guards
--ii. Realice una versión con list comprehension

filtrarLista p xs
 | null xs = []
 | p (head xs) = head xs : filtrarLista p (tail xs)
 | otherwise = filtrarLista p (tail xs) 

filtrarLista2 p z = [x | x <- z, p x]

--m. subLista2 que reciba una lista, un elemento x y un número natural n y retorne una lista sin los
--primeros n elementos de la lista dada que sean mayores que x. Utilice Pattern Matching.

--subLista2 [] y = []
--subLista2 (x:xs) y = if y > 0 then subLista2(xs) (y-1) else x : subLista2 (xs) y  -- ya lo tenia hecho arriba

--n. insertarLista: función que recibe dos listas y un número natural n y retorna la primer lista a la que
--se le agregaron los elementos de la segunda lista a partir de la posición n. Utilice Guards.

insertarLista xs ys n
 | n <= 0 = ys ++ xs
 | null xs = ys
 | otherwise =  head xs : insertarLista (tail xs) ys (n-1)
print ("inicio del proceso")
from random import randint
numeros_aleatorios = [randint(-100,100)for _ in range(23)]
print (numeros_aleatorios)
numeros_negativos = filter(lambda n: n < 0, numeros_aleatorios)
print(list(numeros_negativos))
print (" fin del proceso")
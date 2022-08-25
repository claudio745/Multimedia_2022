print ("Inicio del proceso, calculadora de impares")
m= int(input("Ingrese cuantos numeros desea ingresar"))
a = []*(m+1)
numeros_impares1 = []
for i in range (1, m+1,1):
    numeros_impares = int(input("Ingrese numero impar"))
    if numeros_impares % 2 == 0:
        print ("Error --> Deberia ser un numero impar")
        numeros_impares = int(input("Ingrese numero impar"))
    else:
        numeros_impares1.append (numeros_impares)


print (" Sus números son:", numeros_impares1)

def sumar (numeros_impares1):
    suma = 0
    for elemento in numeros_impares1:
        suma += elemento
    return suma
print ("La suma de sus numeros es:", sumar(numeros_impares1))
print ("Fin del proceso")
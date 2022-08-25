print ("inicio del programa")


numeros_impares = 0
numeros_impar = []
for i in range (1, 20):
    x = int(input("ingrese numero"))
    if x % 2 != 0:
        numeros_impares += 1
        numeros_impar.append (x)

    


resultado = numeros_impares
    
print ("los numeros impares ingresados son:", resultado)
print ("sus numeros fueron:", numeros_impar)

print (" fin del programa")

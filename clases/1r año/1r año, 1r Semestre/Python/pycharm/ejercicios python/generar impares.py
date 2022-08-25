print ("inicio del proceso")


def generar_numeros_impares(n=10):
    impares = []
    contador = 0
    numero = 0
    while contador < n:
        if numero % 2 !=0:
            impares.append(numero)
            contador += 1

        numero += 1
    return impares
n = int(input("escriba la cantidad de impares positivos a imprimir"))
if n > 0:
    impares = generar_numeros_impares()

    print (impares)
    print ("cantidad de impares: ", len(impares))
else:
    print ("el numero debe ser positivo")

print (" fin del proceso")

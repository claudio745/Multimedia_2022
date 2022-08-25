print ("inicio del proceso") 

def contar_pares_impares(lista):
    pares,impares = 0,0
    for n in lista:
        if n % 2 ==0:
            pares += 1
        else:
            impares += 1

    return pares, impares

numeros = [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,47,38,39,40,41,42,43,44,45,46,47,48,49,50]
resultado = contar_pares_impares(numeros)

print (numeros)
print ("la cantidad de pares es: %i" % resultado[0])
print ("la cantidad de impares es: %i" % resultado[1])

print ("fin del proceso")
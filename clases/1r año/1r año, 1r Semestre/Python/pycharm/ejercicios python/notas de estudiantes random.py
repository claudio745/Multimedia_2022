print("inicio del proceso")

lista = []
f = []
cantidad = 29
media = 30
aprobado = 0
reprobado = 0
mujer = 0
hombre = 1
x = 1
j = 1
while (cantidad > 0):
    import random
    azar = random.randint (0,1)
    numero = azar
    lista.append(numero)
    x = x + 1
    cantidad = cantidad - 1
    if numero < 1:
        mujer +=1
    else:
        numero > 0
        hombre += 1
while (media > 0):
    import random
    notas = random.randint(1,7)
    r= notas
    lista.append(r)
    j= j + 1
    media= media - 1
    if r<4:
        reprobado += 1
    else:
        aprobado += 1

print ("Reprobados:",reprobado,"aprobado:", aprobado)
print("mujer:", mujer, "hombres:", hombre)

print (" fin del proceso")

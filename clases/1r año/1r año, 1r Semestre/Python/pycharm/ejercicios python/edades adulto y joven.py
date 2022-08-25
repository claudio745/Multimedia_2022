
print (" inicio del proceso")
import random
x=0
while True:
    magia = random.randint (1,50) 
    edad = magia
    if edad > 28:
        print ("adultos:", edad, "saludos", x)
        break
    else: edad < 29
    x += 1
    print ("edades:", edad)
print (" fin del proceso")
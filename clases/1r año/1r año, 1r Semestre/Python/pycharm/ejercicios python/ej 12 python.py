print ("Inicio del proceso")
m= int(input("Ingrese numeros"))
numeros_ingresados = []
while True:
    if 0 < m < 6:
        print ("ciclo acabado, usted ha ingresado un numero entre 1 y 5")
        numeros_ingresados.append (m)
        break
    else:
        print ("continue ingresando numeros")
        m = int(input("Ingrese numeros"))
       
    
print ("los numeros que usted ha ingresado es:", numeros_ingresados)
print (" Fin del proceso")

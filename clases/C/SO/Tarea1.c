#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
int suma=0;
int turno=0; 

/**********hilo 1****************/
void *hilo1(void *arg) 
{
   
   for(int i = 1;i<30;i++) {
        while(turno !=0); /* no hacer bada si no es su turno */
        printf("A");
        turno=1;       
   }

}
  /**********hilo 2****************/
void *hilo2(void *arg) 
{
   for(int i = 1;i<30;i++) {
        while(turno !=1); /* no hacer bada si no es su turno */
        printf("B");
        turno=2;       
   }
}
/*******Main**********/
int main() {
   pthread_t tid1;
   pthread_create(&tid1, NULL, hilo1, NULL);
   pthread_t tid2;
   pthread_create(&tid2, NULL, hilo2, NULL);
   for(int i = 1;i<30;i++) {
        while(turno !=2); /* no hacer bada si no es su turno */
        printf("C\n");
        turno=0;       
   }
   pthread_join(tid1,NULL);
   pthread_join(tid2,NULL);
   
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

//Tratamiento en bits del bitwise
typedef struct Neural
{
    float x[2];
    float w[2];
    struct Neural *nextn;
} neural;

neural * new_neural();
void NOT(neural **Inicio);

int main()
{
    neural *Inicio, *temp;
    Inicio = new_neural();
    //printf("%d\n", Inicio->id);
    NOT(&Inicio);
}

neural *new_neural()
{
    //printf("%d", id);
    neural *temp;
    temp = (neural *)malloc(sizeof(neural));
    temp->nextn = NULL;
    return temp;
}

void NOT(neural **Inicio)
{
    float n = 0, E = 0, Y , Yp = 0, Z = 0;
    neural *temp;
    temp = *Inicio;
    n = 0.5;

    temp->w[0] = 0.5;

    while (1)
    {
        printf("Inserta tu entrada(0 o 1):\n");
        scanf("%f", &temp->x[0]);

        if(temp->x[0]==0){
          Y=1;
          temp->x[0]=0.01;
        } else {
          Y=0;
        }
        Z = temp->w[0] * temp->x[0];
        Yp = (1) / (1 + exp(Z));
        E = (Yp-Y);

        temp->w[0] = temp->w[0] + (n * E * temp->x[0]);

        //printf("w -> %f\n\n", temp->w[0]);
        printf("salida -> %f\n", Yp);
        if(Yp<0.2){
          //se guardan las w
          printf("final 0 \n");
        }
        if (Yp>0.8) {
          printf("final 1 \n");
        }
        //printf("Error -> %f\n", E);
    }
}

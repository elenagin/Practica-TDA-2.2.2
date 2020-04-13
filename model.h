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

neural *new_neural()
{
    //printf("%d", id);
    neural *temp;
    temp = (neural *)malloc(sizeof(neural));
    temp->nextn = NULL;
    return temp;
}

void OR(neural **Inicio)
{
    float n = 0, E = 0, Y, Yp = 0, Z = 0;
    int i = 0;
    neural *temp;
    temp = *Inicio;
    n = 0.5;

    temp->w[0] = 0.5;
    temp->w[1] = 0.5;

    printf("Inserta tu 1era entrada(0 o 1):\n");
    scanf("%f", &temp->x[0]);
    printf("Inserta tu 2nda entrada(0 o 1):\n");
    scanf("%f", &temp->x[1]);

    if (temp->x[0] == 0)
        temp->x[0] = 0.001;
    if (temp->x[1] == 0)
        temp->x[1] = 0.001;

    while (i <= 500)
    {
        if ((temp->x[0] == 0.001) && (temp->x[1] == 0.001))
            Y = 0;
        else if ((temp->x[0] == 0.001) && (temp->x[1] == 1))
            Y = 1;
        else if ((temp->x[0] == 1) && (temp->x[1] == 0.001))
            Y = 1;
        else if ((temp->x[0] == 1) && (temp->x[1] == 1))
            Y = 1;

        Z = (temp->w[0] * temp->x[0]) + (temp->w[1] * temp->x[1]);
        Yp = (1) / (1 + exp(Z));
        E = (Yp - Y);
        temp->w[0] = temp->w[0] + (n * E * temp->x[0]);
        temp->w[1] = temp->w[1] + (n * E * temp->x[1]);
        printf("%d salida -> %f\n", i, Yp);
        if (Yp < 0.2)
        {
            //se guardan las w
            printf("final 0 \n");
        }
        if (Yp > 0.8)
        {
            printf("final 1 \n");
        }
        i++;
    }
}

void AND(neural **Inicio)
{
    float n = 0, E = 0, Y, Yp = 0, Z = 0;
    int i = 0;
    neural *temp;
    temp = *Inicio;
    n = 0.5;

    temp->w[0] = 0.5;
    temp->w[1] = 0.5;

    printf("Inserta tu 1era entrada(0 o 1):\n");
    scanf("%f", &temp->x[0]);
    printf("Inserta tu 2nda entrada(0 o 1):\n");
    scanf("%f", &temp->x[1]);

    if (temp->x[0] == 0)
        temp->x[0] = 0.001;
    if (temp->x[1] == 0)
        temp->x[1] = 0.001;

    while (i <= 500)
    {
        if ((temp->x[0] == 0.001) && (temp->x[1] == 0.001))
            Y = 0;
        else if ((temp->x[0] == 0.001) && (temp->x[1] == 1))
            Y = 0;
        else if ((temp->x[0] == 1) && (temp->x[1] == 0.001))
            Y = 0;
        else if ((temp->x[0] == 1) && (temp->x[1] == 1))
            Y = 1;

        Z = (temp->w[0] * temp->x[0]) + (temp->w[1] * temp->x[1]);
        Yp = (1) / (1 + exp(Z));
        E = (Yp - Y);
        temp->w[0] = temp->w[0] + (n * E * temp->x[0]);
        temp->w[1] = temp->w[1] + (n * E * temp->x[1]);
        printf("%d salida -> %f\n", i, Yp);
        if (Yp < 0.2)
        {
            //se guardan las w
            printf("final 0 \n");
        }
        if (Yp > 0.8)
        {
            printf("final 1 \n");
        }
        i++;
    }
}

void XOR(neural **Inicio)
{
    printf("XOR");
}

void NOT(neural **Inicio)
{
    float n = 0, E = 0, Y, Yp = 0, Z = 0;
    int i = 0;
    neural *temp;
    temp = *Inicio;
    n = 0.5;

    temp->w[0] = 0.5;

    printf("Inserta tu entrada(0 o 1):\n");
    scanf("%f", &temp->x[0]);

    while (i <= 500)
    {
        if (temp->x[0] == 0)
        {
            Y = 1;
            temp->x[0] = 0.01;
        }
        else
        {
            Y = 0;
        }
        Z = temp->w[0] * temp->x[0];
        Yp = (1) / (1 + exp(Z));
        E = (Yp - Y);

        temp->w[0] = temp->w[0] + (n * E * temp->x[0]);

        printf("%d salida -> %f\n", i, Yp);
        if (Yp < 0.2)
        {
            //se guardan las w
            printf("final 0 \n");
        }
        if (Yp > 0.8)
        {
            printf("final 1 \n");
        }
        i++;
    }
}

void XNOR(neural **Inicio)
{
    printf("XNOR");
}
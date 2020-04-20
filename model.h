#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

typedef struct Neural
{
    float x[2];
    float w[2];
    struct Neural *nextn;
} neural;

neural *new_neural()
{
    neural *temp;
    temp = (neural *)malloc(sizeof(neural));
    temp->nextn = NULL;
    return temp;
}

void OR(neural **Inicio)
{
    system("clear");
    float n = 0, E = 0, Y, Yp = 0, Z = 0;
    int i = 0;

    neural *temp;
    temp = *Inicio;
    n = 0.5;
    temp->w[0] = 0.5;
    temp->w[1] = 0.5;
    printf("Inserta tu 1era entrada(0 o 1): ");
    scanf("%f", &temp->x[0]);
    printf("Inserta tu 2nda entrada(0 o 1): ");
    scanf("%f", &temp->x[1]);

    if ((temp->x[0] == 0) && (temp->x[1] == 0))
    {
        Y = 0;
        temp->x[0] = 0.1;
        temp->x[1] = 0.1;
        //printf("primer if yey");
    }
    else if ((temp->x[0] == 0) && (temp->x[1] == 1))
    {
        Y = 1;
        temp->x[0] = 0.1;
        //printf("if 0 y 1");
    }
    else if ((temp->x[0] == 1) && (temp->x[1] == 0))
    {
        Y = 1;
        temp->x[1] = 0.1;
        //printf("if 1 y 0");
    }
    else if ((temp->x[0] == 1) && (temp->x[1] == 1))
    {
        Y = 1;
        //printf("if 1 y 1");
    }

    while (i <= 500)
    {
        Z = (temp->w[0] * temp->x[0]) + (temp->w[1] * temp->x[1]);
        Yp = (1) / (exp(-1 * Z) + 1);
        E = (Y - Yp);
        temp->w[0] = temp->w[0] + (n * E * temp->x[0]);
        temp->w[1] = temp->w[1] + (n * E * temp->x[1]);
        //printf("%d salida -> %f\nE %f\n", i, Yp, Y);

        i++;
    }
    if (Yp < 0.2)
        printf("0 \n");

    if (Yp > 0.8)
        printf("1 \n");
}

void AND(neural **Inicio)
{
    system("clear");
    float n = 0, E = 0, Y, Yp = 0, Z = 0;
    int i = 0;

    neural *temp;
    temp = *Inicio;
    n = 0.5;
    temp->w[0] = 0.5;
    temp->w[1] = 0.5;
    printf("Inserta tu 1era entrada(0 o 1): ");
    scanf("%f", &temp->x[0]);
    printf("Inserta tu 2nda entrada(0 o 1): ");
    scanf("%f", &temp->x[1]);

    if ((temp->x[0] == 0) && (temp->x[1] == 0))
    {
        Y = 0;
        temp->x[0] = 0.1;
        temp->x[1] = 0.1;
    }
    else if ((temp->x[0] == 0) && (temp->x[1] == 1))
    {
        Y = 0;
        temp->x[0] = 0.1;
    }
    else if ((temp->x[0] == 1) && (temp->x[1] == 0))
    {
        Y = 0;
        temp->x[1] = 0.1;
    }
    else if ((temp->x[0] == 1) && (temp->x[1] == 1))
    {
        Y = 1;
    }

    while (i <= 500)
    {
        Z = (temp->w[0] * temp->x[0]) + (temp->w[1] * temp->x[1]);
        Yp = (1) / (exp(-1 * Z) + 1);
        E = (Y - Yp);
        temp->w[0] = temp->w[0] + (n * E * temp->x[0]);
        temp->w[1] = temp->w[1] + (n * E * temp->x[1]);
        //printf("%d salida -> %f\n", i, Yp);

        i++;
    }

    if (Yp < 0.2)
        printf("0 \n");

    if (Yp > 0.8)
        printf("1 \n");
}

void XOR(neural **Inicio, neural **Inicio2)
{
    system("clear");
    float n1 = 0, n2 = 0, E = 0, Y, Yp1 = 0, Yp2 = 0, Z1 = 0, Z2 = 0, Ew0 = 0, Ew1 = 0;
    int i = 0;

    neural *temp[2];

    temp[0] = *Inicio;
    temp[1] = *Inicio2;
    n1 = 0.5;
    n2 = 0.5;
    temp[0]->w[0] = 0.5;
    temp[0]->w[1] = 0.5;
    temp[1]->w[0] = 0.5;
    temp[1]->w[1] = 0.5;
    printf("Inserta tu 1era entrada(0 o 1): ");
    scanf("%f", &temp[0]->x[0]);
    printf("Inserta tu 2nda entrada(0 o 1): ");
    scanf("%f", &temp[0]->x[1]);

    if ((temp[0]->x[0] == 0) && (temp[0]->x[1] == 0))
    {
        Y = 0;
        temp[0]->x[0] = 0.1;
        temp[0]->x[1] = 0.1;
    }
    else if ((temp[0]->x[0] == 0) && (temp[0]->x[1] == 1))
    {
        Y = 1;
        temp[0]->x[0] = 0.1;
    }
    else if ((temp[0]->x[0] == 1) && (temp[0]->x[1] == 0))
    {
        Y = 1;
        temp[0]->x[1] = 0.1;
    }
    else if ((temp[0]->x[0] == 1) && (temp[0]->x[1] == 1))
    {
        Y = 0;
    }

    temp[1]->x[0] = temp[0]->x[0];

    while (i < 500)
    {
        Z1 = (temp[0]->w[0] * temp[0]->x[0]) + (temp[0]->w[1] * temp[0]->x[1]);
        Yp1 = (1) / (exp(-1 * Z1) + 1);
        temp[1]->x[1] = Yp1;
        Z2 = (temp[1]->w[0] * temp[1]->x[0]) + (temp[1]->w[1] * temp[1]->x[1]);
        Yp2 = (1) / (exp(-1 * Z2) + 1);
        E = Y - Yp2;
        Ew0 = (temp[0]->w[0] / (temp[0]->w[0] + temp[0]->w[1])) * E;
        Ew1 = (temp[0]->w[1] / (temp[0]->w[0] + temp[0]->w[1])) * E;

        temp[1]->w[0] = temp[1]->w[0] + (n1 * E * temp[1]->x[0]);
        temp[1]->w[1] = temp[1]->w[1] + (n1 * E * temp[1]->x[1]);
        temp[0]->w[0] = temp[0]->w[0] + (n1 * Ew0 * temp[0]->x[0]);
        temp[0]->w[1] = temp[0]->w[1] + (n1 * Ew1 * temp[0]->x[1]);

        //printf("%d salida -> %f\n", i, Yp2);

        i++;
    }
    if (Yp2 < 0.2)
        printf("0 \n");

    if (Yp2 > 0.8)
        printf("1 \n");
}

void NOT(neural **Inicio)
{
    system("clear");
    float n = 0, E = 0, Y, Yp = 0, Z = 0;
    int i = 0;

    neural *temp;
    temp = *Inicio;
    n = 0.9;
    temp->w[0] = 0.5;
    printf("Inserta tu entrada(0 o 1):\n");
    scanf("%f", &temp->x[0]);

    if (temp->x[0] == 0)
    {
        Y = 1;
        temp->x[0] = 0.1;
    }
    else
    {
        Y = 0;
    }

    while (i <= 500)
    {
        Z = temp->w[0] * temp->x[0];
        Yp = (1) / (exp(-1 * Z) + 1);
        E = (Y - Yp);
        temp->w[0] = temp->w[0] + (n * E * temp->x[0]);
        //printf("\n%d salida -> %f\n", i, Yp);

        i++;
    }
    if (Yp < 0.2)
        printf("0 \n");

    if (Yp > 0.8)
        printf("1 \n");
}

void XNOR(neural **Inicio, neural **Inicio2)
{
    system("clear");
    float n1 = 0, n2 = 0, E = 0, Y, Yp1 = 0, Yp2 = 0, Z1 = 0, Z2 = 0, Ew0 = 0, Ew1 = 0;
    int i = 0;

    neural *temp[2];

    temp[0] = *Inicio;
    temp[1] = *Inicio2;
    n1 = 0.5;
    n2 = 0.5;
    temp[0]->w[0] = 0.5;
    temp[0]->w[1] = 0.5;
    temp[1]->w[0] = 0.5;
    temp[1]->w[1] = 0.5;
    printf("Inserta tu 1era entrada(0 o 1): ");
    scanf("%f", &temp[0]->x[0]);
    printf("Inserta tu 2nda entrada(0 o 1): ");
    scanf("%f", &temp[0]->x[1]);

    if ((temp[0]->x[0] == 0) && (temp[0]->x[1] == 0))
    {
        Y = 1;
        temp[0]->x[0] = 0.1;
        temp[0]->x[1] = 0.1;
    }
    else if ((temp[0]->x[0] == 0) && (temp[0]->x[1] == 1))
    {
        Y = 0;
        temp[0]->x[0] = 0.1;
    }
    else if ((temp[0]->x[0] == 1) && (temp[0]->x[1] == 0))
    {
        Y = 0;
        temp[0]->x[1] = 0.1;
    }
    else if ((temp[0]->x[0] == 1) && (temp[0]->x[1] == 1))
    {
        Y = 1;
    }

    temp[1]->x[0] = temp[0]->x[0];

    while (i < 1300)
    {
        Z1 = (temp[0]->w[0] * temp[0]->x[0]) + (temp[0]->w[1] * temp[0]->x[1]);
        Yp1 = (1) / (exp(-1 * Z1) + 1);
        temp[1]->x[1] = Yp1;
        Z2 = (temp[1]->w[0] * temp[1]->x[0]) + (temp[1]->w[1] * temp[1]->x[1]);
        Yp2 = (1) / (exp(-1 * Z2) + 1);
        E = Y - Yp2;
        Ew0 = (temp[0]->w[0] / (temp[0]->w[0] + temp[0]->w[1])) * E;
        Ew1 = (temp[0]->w[1] / (temp[0]->w[0] + temp[0]->w[1])) * E;

        temp[1]->w[0] = temp[1]->w[0] + (n1 * E * temp[1]->x[0]);
        temp[1]->w[1] = temp[1]->w[1] + (n1 * E * temp[1]->x[1]);
        temp[0]->w[0] = temp[0]->w[0] + (n1 * Ew0 * temp[0]->x[0]);
        temp[0]->w[1] = temp[0]->w[1] + (n1 * Ew1 * temp[0]->x[1]);

        //printf("%d salida -> %f\n", i, Yp2);

        i++;
    }
    if (Yp2 < 0.2)
        printf("0 \n");

    if (Yp2 > 0.8)
        printf("1 \n");
}
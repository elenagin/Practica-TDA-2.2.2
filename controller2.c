#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "model.h"
#include "view.h"

int main()
{
    int op, num_inputs, temp = 0;

    op = 0;
    initial_menu();
    tipoElemento *Primero = NULL;

    bla(&num_inputs);
    inputs(&Primero, &num_inputs);
    while (temp != 6)
    {
        temp = main_menu(&num_inputs);

        switch (temp)
        {
        case 1:
            OR(Primero);
            Imprime(Primero);
            break;
        case 2:
            AND(Primero);
            Imprime(Primero);
            break;
        case 3:
            XOR(Primero);
            Imprime(Primero);
            break;
        case 4:
            NOT(Primero);
            Imprime(Primero);
            break;
        case 5:
            XNOR(Primero);
            Imprime(Primero);
            break;
        }
        final_menu();
    }
    return 0;
}
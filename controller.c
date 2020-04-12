#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "model.h"
#include "view.h"

int main()
{
    int op, num_inputs, switchOp = 0;

    op = 0;
    initial_menu();
    neural *Inicio, *temp;
    Inicio = new_neural();
    while (switchOp != 6)
    {
        switchOp = main_menu(&num_inputs);

        switch (switchOp)
        {
        case 1:
            OR();
            getchar();
            break;
        case 2:
            AND();
            getchar();
            break;
        case 3:
            XOR();
            getchar();
            break;
        case 4:
            NOT(&Inicio);
            getchar();
            break;
        case 5:
            XNOR();
            getchar();
            break;
        }
        final_menu();
    }
    return 0;
}
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
    neural *Inicio, *Inicio2;
    Inicio = new_neural();
    Inicio2 = new_neural();

    while (switchOp != 6)
    {
        switchOp = main_menu(&num_inputs);

        switch (switchOp)
        {
        case 1:
            OR(&Inicio);
            getchar();
            break;
        case 2:
            AND(&Inicio);
            getchar();
            break;
        case 3:
            XOR(&Inicio, &Inicio2);
            getchar();
            break;
        case 4:
            NOT(&Inicio);
            getchar();
            break;
        case 5:
            XNOR(&Inicio, &Inicio2);
            getchar();
            break;
        }
        final_menu();
    }
    return 0;
}
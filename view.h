void inputs(tipoElemento **Inicio, int *num_inputs)
{
    int i, temp;    

    for(i=0; i<*num_inputs; i++){
        printf("Inserta \"1\" ó \"0\": ");
        scanf("%d", &temp);
        InsertaInicio(Inicio, temp);        
    }
}

void bla(int *num_inputs)
{
    printf("¿Cuántas entradas vas a tener?\n\n");
    scanf("%d", num_inputs);
}

void initial_menu(){
    system("clear");
    printf("Bienvenido al sistema\n");
    printf("----------------------------\n");
    printf("\tMariana Carmona\n");
    printf("\tIván Guzmán\n");
    printf("\tElena Ginebra\n");
    printf("----------------------------\n");
    printf("Presione enter para comenzar...\n");
    getchar();
    system("clear");
}

void final_menu(){
    printf("Presione enter para continuar...\n");
    getchar(); 
}

int main_menu(int *num_inputs){
    int op;

    system("clear");
    printf("¿Qué compuerta quieres probar?\n");
    printf("1. OR\n");
    printf("2. AND\n");
    printf("3. XOR\n");
    printf("4. NOT\n");
    printf("5. XNOR\n");
    printf("6. Salir\n");
    printf("Opción: \n");
    scanf("%d", &op);
    return op;
}
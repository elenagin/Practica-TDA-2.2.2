typedef struct def_elemento
{
    int dato;
    struct def_elemento *sig;
} tipoElemento;


void InsertaInicio(tipoElemento **Inicio, int bin)
{
    tipoElemento *temp;
    temp = (tipoElemento *)malloc(sizeof(tipoElemento));
    temp->dato = bin;
    temp->sig = *Inicio;
    *Inicio = temp;
}

void Imprime(tipoElemento *Inicio)
{
    tipoElemento *temp;
    temp = Inicio;
    printf("Imprimiendo lista...\n");
    while (temp != NULL)
    {
        printf("\t%d\n", temp->dato);
        temp = temp->sig;
    }
    getchar();
}

void OR(tipoElemento *Inicio)
{
    tipoElemento *temp;
    int t;
    temp = Inicio;
    t = temp->dato;
    while (temp->sig != NULL)
    {
        if ((t == 0) && (temp->sig->dato == 0))
        {
            t = 0;
        }
        else if ((t == 0) && (temp->sig->dato == 1))
        {
            t = 1;
        }
        else if ((t == 1) && (temp->sig->dato == 0))
        {
            t = 1;
        }
        else if ((t == 1) && (temp->sig->dato == 1))
        {
            t = 1;
        }
        temp = temp->sig;
    }

    printf("t = %d\n", t);
}

void AND(tipoElemento *Inicio)
{
    tipoElemento *temp;
    int t;
    temp = Inicio;
    t = temp->dato;
    while (temp->sig != NULL)
    {
        if ((t == 0) && (temp->sig->dato == 0))
        {
            t = 0;
        }
        else if ((t == 0) && (temp->sig->dato == 1))
        {
            t = 0;
        }
        else if ((t == 1) && (temp->sig->dato == 0))
        {
            t = 0;
        }
        else if ((t == 1) && (temp->sig->dato == 1))
        {
            t = 1;
        }
        temp = temp->sig;
    }

    printf("t = %d\n", t);
}

void XOR(tipoElemento *Inicio)
{
    printf("XOR");
}

void NOT(tipoElemento *Inicio)
{
    printf("NOT");
}

void XNOR(tipoElemento *Inicio)
{
    printf("XNOR");
}
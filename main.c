#include "scanner.h"
#include <stdio.h>
#define EXIT_SUCCESS 0

int main (void) 
{
    char *cadenaLeida = NULL;

    token_t token;

    do 
    {
        token = get_token(cadenaLeida);
        switch (token) 
        {
            case FDT :
                printf("Fin De Texto:");
                break;
            case SEP :
                printf("Separador: %s",cadenaLeida);
                break;
            case CAD :
                printf("Cadena: %s",cadenaLeida);
                break;
            default:
                printf("Token Desconocido:");
                break;
        }

    } while (token != FDT);

    return EXIT_SUCCESS;
}
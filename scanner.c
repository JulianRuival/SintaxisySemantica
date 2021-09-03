#include <stdio.h>
#include "scanner.h"

token_t get_token( char *cadena ){

    char caracter;
    token_t token = FDT;
    int seguir = 1;
    caracter=getchar();


 
    do
    {
        caracter=getchar();
        if(token == CAD)
        {
           if(isspace())
           {
               seguir = 0;
           }
        }
        else
        {
            if(token == SEP)
            {
                
            }
        }

    } while (seguir == 0);

    return token;

}
#include "scanner.h"
#include <stdio.h>

token_t get_token( char *cadena )
{
    char caracter;
    token_t token = FDT;
    int seguir = 1;
    caracter=getchar();

    do
    {
        caracter=getchar();
        if(token == CAD)// si estamos leyendo una cadena
        {
           if(isspace(caracter)) // en caso de que le siga un espacio tenemos que arrancar un nuevo token
           {
               seguir = 1;
           }
           if(caracter == ',') // en caso de que le siga una coma al caracter tenemos que cortar la cadena y registrar el token SEP
           {
               seguir = 1 ;
               token = SEP;
           }
           if(caracter == EOF) // en caso de que sea el eof entonces cortamos la cadena y registramos el FDT
           {
               seguir = 1;
               token = FDT;
           }
           else // en el caso de que no sea una coma, ni un espacio, ni el eof, entonces es un caracter por lo que lo concatenamos a la cadena y seguimos leyendo
           {
               seguir = 0;
               cadena = cadena + caracter ;
           }
        }
        if ( token != CAD ) 
        {
            if ( ! isspace(caracter) && ! caracter == ',' )// En caso de que no sea una coma,ni un espacio, ni eof, entonces es una cadena
            { 
                token = CAD; 
                seguir = 0;  //para seguir leyendo la cadena
                ungetc(caracter,stdin); // para no perder el caracter con el que entramos a la cadena que no se incluyo en esta
            }
        }   
    } while (seguir == 0);

    return token;
}
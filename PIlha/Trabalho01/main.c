#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "Pilha.h"

int verifica_procedencia (int x) {

    if ( x == '(' ) {

        return 0;

    } else if ( x == '+' || x == '-' ) {

        return 1;

    } else if ( x == '*' || x == '/' ){

        return 2;

    }
}

void avalia_expressao( int tam, char *str ) {

    Pilha p2;

    int i = 0, aux1, aux2, x;
    char c;
    int resultado;

    inicializa_pilha( &p2, tam );

    while( str[i] != '\0' ) {

        c = str[i];

        if ( c >= 48 && c <= 57 ) {

            x = c - 48;

            empilha( &p2, x );

        } else {

            desempilha( &p2, &aux2 );
            desempilha( &p2, &aux1 );

            switch( c ) {

                case '+':
                    resultado = aux1 + aux2;
                    break;

                case '-':
                    resultado = aux1 - aux2;
                    break;

                case '*':
                    resultado = aux1 * aux2;
                    break;

                case '/':
                    resultado = aux1 / aux2;
                    break;
            }

            empilha( &p2, resultado );

        }

        i++;

    }

    printf("\n\nResultado: %d\n", resultado);

}

int main(int argc, char *argv[]) {

	setlocale(LC_ALL,NULL);

	Pilha p1;

	int tam, i;
	char c, x;

	printf("Digite o tamanho da expressão aritmética infixa: ");
	scanf("%d", &tam);

	char entrada[tam];
	char str[tam];
	char str_char[2];

	printf("\nDigite a expressão aritmética infixa: ");
	scanf("%s", &entrada);

	int deu_erro = 0;

	inicializa_pilha( &p1, strlen(entrada) );

	for ( i = 0; i < strlen(entrada) && deu_erro == 0; i++ ) {

		c = entrada[i];

		switch( c ) {

			case '0' ... '9':
			    str_char[0] = c;
			    str_char[1] = '\0';

				strcat(str, str_char);
				break;

			case '(':
				empilha( &p1, c );
				break;

			case ')':
			    while ( le_topo( p1, &x ) != ERRO_PILHA_VAZIA && ( x != '(' ) ) {

                    desempilha( &p1, &x );

                    str_char[0] = x;
                    str_char[1] = '\0';

                    strcat(str, str_char);

                }

                if (pilha_vazia( p1 )) {

                    printf("\n\nErro: ')' sem '('!");

                    deu_erro = 1;

                } else {

                    desempilha( &p1, &x );

                }
                break;

            case '+':
            case '-':
            case '*':
            case '/':

                le_topo( p1, &x );

                if ( pilha_vazia( p1 ) || x == '(' ) {

                    empilha( &p1, c );

                } else {

                    while ( le_topo( p1, &x ) != ERRO_PILHA_VAZIA && verifica_procedencia( x ) >= verifica_procedencia( c ) ) {

                        desempilha( &p1, &x );

                        str_char[0] = x;
                        str_char[1] = '\0';

                        strcat(str, str_char);

                    }
                }
                break;

            default:
                printf("\n\nErro: caractere inválido: %c!", c);
                deu_erro = 1;
                break;
		}
	}

	if ( !deu_erro ) {

        while ( le_topo( p1, &x ) != ERRO_PILHA_VAZIA && x != '(' ) {

            desempilha( &p1, &x );

            str_char[0] = x;
            str_char[1] = '\0';

            strcat(str, str_char);

        }

        if ( pilha_vazia( p1 ) ) {

        	strcat(str, "");

        	printf("\n\nString: %s", str);

        	avalia_expressao( strlen(entrada), str );

		} else {

			printf("\n\nErro: '(' não foi fechado!");

		}
	}

	desaloca_pilha( &p1 );

	return 0;
}

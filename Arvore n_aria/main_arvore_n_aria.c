#include <stdio.h>
#include <stdlib.h>
#include "arvore_n_aria.h"

int main_arvore(int argc, char *argv[])
{
     Arvore a;
     inicializa_Arvore( &a, 1 );

     insere_filho( a, 1, 2 );
     insere_filho( a, 1, 3 );
     insere_filho( a, 1, 4 );
     insere_filho( a, 2, 5 );
     insere_filho( a, 3, 6 );
     insere_filho( a, 3, 7 );
     insere_filho( a, 4, 8 );
     insere_filho( a, 5, 9 );
     insere_filho( a, 6, 10 );

     gera_xml( a );

     desaloca_arvore( &a );

     system("PAUSE");
     return 0;
}

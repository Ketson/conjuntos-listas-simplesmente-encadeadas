#ifndef _CONJ_
#define _CONJ_

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no{
    int num;
    struct no *prox;
}no;

/*recebe um numero, e cria um n� com o numero*/
no *criaNo(int valor);

/*imprime todos os valores*/
void imprimir(no *L);

/*fun��o que inserir, que recebe um conjunto e um numero e insere nesse conjunto
se o conjunto n�o existir no conjunto*/
no *inserirOrdenado(no *L, int valor);

/*fun��o que vai excluir o numero do conjunto, se o numero existir no conjunto*/
no *excluiOrd(no *L, int valor);

/*vai liberar o espa�o de memoria, excluindo todos os numeros que est�o no conjunto*/
no *limpaConjunto(no *L);

/*fun��o para verificar se um conjunto � vazio*/
void vazio(no *L);

/*fun��o busca elemento que recebe um conjunto e um numero inteiro
e vai procurar este numero no conjunto
*/
int busca(no *L, int valor);

/*verifica se um conjunto est� contido no outro*/
void contido(no *A, no *B);

/*vai verificar se um conjunto � igual o outro, e imprimir na tela*/
void igual(no *A, no *B);

/*verifica se um conjunto � subconjunto de outro*/
void subconjunto(no *A, no *B);

/*vai realizar a uni�o dos dois primeiros conjuntos, e tera um terceiro conjunto com a resposta*/
no *uniao(no *A, no *B, no *C);

/*fun��o vai receber tres conjuntos e realizar a interse��o dos dois primeiros conjuntos
*/
no *intersecao(no *A, no *B, no *C);

/*vai receber tres conjuntos e realizar a diferen�a dos dois primeiros
conjuntos, e depois ser retornado um terceiro conjunto com o conjunto resposta*/
no *complemento(no *A, no *B, no *C);

#endif

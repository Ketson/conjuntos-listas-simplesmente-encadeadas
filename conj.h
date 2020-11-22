#ifndef _CONJ_
#define _CONJ_

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no{
    int num;
    struct no *prox;
}no;

/*recebe um numero, e cria um nó com o numero*/
no *criaNo(int valor);

/*imprime todos os valores*/
void imprimir(no *L);

/*função que inserir, que recebe um conjunto e um numero e insere nesse conjunto
se o conjunto não existir no conjunto*/
no *inserirOrdenado(no *L, int valor);

/*função que vai excluir o numero do conjunto, se o numero existir no conjunto*/
no *excluiOrd(no *L, int valor);

/*vai liberar o espaço de memoria, excluindo todos os numeros que estão no conjunto*/
no *limpaConjunto(no *L);

/*função para verificar se um conjunto é vazio*/
void vazio(no *L);

/*função busca elemento que recebe um conjunto e um numero inteiro
e vai procurar este numero no conjunto
*/
int busca(no *L, int valor);

/*verifica se um conjunto está contido no outro*/
void contido(no *A, no *B);

/*vai verificar se um conjunto é igual o outro, e imprimir na tela*/
void igual(no *A, no *B);

/*verifica se um conjunto é subconjunto de outro*/
void subconjunto(no *A, no *B);

/*vai realizar a união dos dois primeiros conjuntos, e tera um terceiro conjunto com a resposta*/
no *uniao(no *A, no *B, no *C);

/*função vai receber tres conjuntos e realizar a interseção dos dois primeiros conjuntos
*/
no *intersecao(no *A, no *B, no *C);

/*vai receber tres conjuntos e realizar a diferença dos dois primeiros
conjuntos, e depois ser retornado um terceiro conjunto com o conjunto resposta*/
no *complemento(no *A, no *B, no *C);

#endif

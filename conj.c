#include "conj.h"

no *criaNo(int valor){
    no *novo = (no*)calloc(1,sizeof(no));

    if(novo == NULL){
        printf("ERRO: Memória não alocada.\n");
        exit(1);
    }
    novo -> num = valor;
    novo -> prox = NULL;
    return novo;
}

void imprimir(no *L){
    no *aux = L;

    if(L == NULL)
        printf("Vazio\n");
    else{
        while(aux != NULL){
            printf("%d",aux -> num);
            aux = aux -> prox;
        }
        printf("\n");
    }
}

//função que vai inserir um nó com o valor, e ja vai ordenando
no *inserirOrdenado(no *L, int valor){
    no *novo = criaNo(valor);
    no *aux = L;
    no *pred = NULL;

    if(busca(L,valor) >= 0){
        printf("\n===Valor já existe no conjunto===");
        return L;
    }

    if(L == NULL)
        return L = novo;

    if(aux -> num > novo -> num){
        novo -> prox = L;
        L = novo;
        return L;
    }

    while(aux -> prox != NULL && aux -> num <= valor){
        pred = aux;
        aux = aux -> prox;
    }
    if(aux -> prox == NULL && valor > aux -> num)
        aux -> prox = novo;

    else {
        novo -> prox = aux;
        pred -> prox = novo;
    }
    return L;
}

//função que vai excluir um elemento do conjunto
no *excluiOrd(no *L, int valor){
    no *aux = L;
    no *pred = NULL;

    if(L == NULL)
        return NULL;
    else{
        while((aux -> num < valor) && (aux != NULL)){
            pred = aux;
            aux = aux -> prox;
        }
        if((aux -> num == valor) && (aux != NULL)){
            if(pred == NULL)
                L = aux -> prox;
            else
                pred -> prox = aux -> prox;
            free(aux);
        }
        return L;
    }
}

no *limpaConjunto(no *L){
    if(L != NULL){
        no *aux = L;

        while(aux != NULL){
            L = L -> prox;
            free(aux);
            aux = L;
        }
    }
    return L;
}

//caso o conjunto é vazio
void vazio(no *L){
    if(L == NULL)
        printf("\nEsse conjunto está vazio.\n");
    else
        printf("\nNão vazio.\n");
}

int busca(no *L, int valor){
    no *aux = L;
    int i = 0;

    if(L == NULL)
        return -1;
    else{
        while(aux != NULL && aux -> num <= valor){
            if(aux -> num == valor) return i;
            aux = aux -> prox;
            i++;
        }
        return -1; //se não encontar o numero buscado na lista
    }
}

void contido(no *A, no *B){
    no *auxA = A, *auxB = B;
    int pesq = 0;

    if(A == NULL)
        printf("\n===Contido.===\n");
    else{
        while(auxA != NULL){
            auxB = B;
            pesq = 0;

            while(auxB != NULL){
                if(auxA -> num == auxB -> num){
                    pesq = 1;
                    break;
                }
                auxB = auxB -> prox;
            }
            if(pesq == 0){
                printf("===Não contido.===\n");
                break;
            }
            auxA = auxA -> prox;
        }
        if(pesq == 1)
            printf("\n===Contido===\n");
    }
}

//função para ver se o conjunto é igual a o outro
void igual(no *A, no *B){
    no *auxA = A;
    no *auxB = B;
    /*verifica se algum conjunto tem elementos e se o outro vazio*/
    if((A == NULL && B != NULL) || (A != NULL && B == NULL))
        printf("\n===Iguais.===\n");
    else{
        if((A == NULL) && (B == NULL))
            printf("\n===Iguais===");
        else{/*percorrer os dois conjuntos ao mesmo tempo
            e parar quando algum deles chegar ao �ltimo elemento*/
            while((auxA->prox != NULL && auxB -> prox != NULL) && (auxA -> num == auxB -> num)){
                auxA = auxA -> prox;
                auxB = auxB -> prox;
            }
            if((auxA -> prox != NULL) || (auxB -> prox != NULL))
                printf("\n===Não iguais===\n");
            else{
                if(auxA -> num == auxB -> num)
                    printf("\n===Iguais===\n");
                else
                    printf("\n===Não Iguais===\n");
            }
        }
    }
}

void subconjunto(no *A, no *B){
    no *auxA = A;
    no *auxB = B;
    int pesq = 0;

    if(A == NULL)
        printf("\n===É subconjunto.===\n");

    else{
        // caso um conjunto esteja contido em outro conjunto, ele é subconjunto do outro
        while(auxA != NULL){
            auxB = B;
            pesq = 0;
            while(auxB != NULL){
                if(auxA -> num == auxB -> num){
                    pesq = 1;
                    break;
                }
                auxB = auxB -> prox;
            }
            if(pesq == 0){
                printf("\n===Não é subconjunto===\n");
                break;
            }
            auxA = auxA->prox;
        }
        if(pesq == 1)
            printf("\n===É subconjunto===\n");
    }
}

//faz união dos dois conjuntos e retorna outro conjunto com a resposta
no *uniao(no *A, no *B, no *C){
    no *auxA = A;
    no *auxB = B;
    no *auxC = C;

    if(A == NULL)
        return B;
    if(B == NULL)
        return A;

    //pega todos os valores em comum dos dois conjuntos. Logo, primeiro adicionamos todos os valores de A em C
    while(auxA != NULL){
        C = inserirOrdenado(C,auxA->num);
        auxA = auxA->prox;
    }

    //verifica os valores de B que não estão em A, e adiciona
    while(auxB != NULL){
        auxC = C;
        int pesq = 0;
        while((auxC != NULL) && (auxB -> num >= auxC -> num)){
            if(auxB -> num == auxC -> num){
                pesq = 1;
                break;
            }
            auxC = auxC->prox;
        }
        if(pesq == 0)
            C = inserirOrdenado(C,auxB -> num);
        auxB = auxB -> prox;
    }
    return C;
}

//função que faz a interseção
no *intersecao(no *A, no *B, no *C){

    no *auxA = A;
    no *auxB = B;

    /*caso um dos conjuntos seja vazio, a interseção desse conjunto com qualquer outro conjunto também será vazio*/
    if(A == NULL || B == NULL)
        return C;
    /*caso os conjuntos estiver conteúdo, irpa verificar todos os valores iguais entre eles e adicionar no conjunto resposta C*/
    while(auxA != NULL){
        auxB = B;
        while((auxB != NULL) && (auxA -> num >= auxB -> num)){
            if(auxA -> num == auxB -> num){
                C = inserirOrdenado(C,auxA -> num);
                break;
            }
            auxB = auxB -> prox;
        }
        auxA = auxA -> prox;
    }
    return C;
}

no *complemento(no *A, no *B, no *C){ // realiza a diferença entre dois conjuntos e retorna um conjunto resposta

    no *auxA = A;
    no *auxB = B;

    if(A == NULL)
        return C;

    if(B == NULL)
        return A;

    while(auxA != NULL){
        int pesq = 0;
        auxB = B;

        while((auxB != NULL) && (auxA -> num >= auxB -> num)){
            if(auxA -> num == auxB -> num){
                pesq = 1;
                break;
            }
            auxB = auxB -> prox;
        }
        if(pesq == 0)
            C = inserirOrdenado(C,auxA -> num);

        auxA = auxA->prox;
    }
    return C;
}


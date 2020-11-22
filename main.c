#include "conj.h"

int main(){
    setlocale(LC_ALL,"portuguese");

    int opcao, num;
    no *A = NULL, *B = NULL, *C = NULL;

    do{
        printf("\n[1] Inserir um elemento");
        printf("\n[2] Remover um elemento");
        printf("\n[3] Esvaziar o conjunto");
        printf("\n[4] Verificar se o conjunto é vazio");
        printf("\n[5] Verificar se um elemento pertence a um conjunto");
        printf("\n[6] Verificar se um conjunto está contido em outro conjunto");
        printf("\n[7] Verificar se dois conjuntos são iguais");
        printf("\n[8] Verificar se um conjunto e subconjunto de outro conjunto");
        printf("\n[9] Fazer a união de dois conjuntos");
        printf("\n[10] Fazer a intersecao de dois conjuntos");
        printf("\n[11] Fazer o complemento relativo de um conjunto B em um conjunto A");
        printf("\n[0] Sair");
        printf("\n");
        printf("Opção: ");
        scanf("%d",&opcao);

        switch(opcao){
            case 1:
                printf("\nInserir um elemento.\n");

                do{
                    printf("\n Qual conjunto será utilizado?\n");
                    printf("\n[1] Conjunto A;");
                    printf("\n[2] Conjunto B.\n");
                    printf("\nOpção: ");
                    scanf("%d",&opcao);

                    if(opcao != 1 && opcao != 2)
                        printf("\nOpção inválida.\n");

                }while(opcao != 1 && opcao != 2);

                printf("\n Valor: ");
                scanf("%d",&num);

                if(opcao == 1)
                    A = inserirOrdenado(A,num);

                else
                    B = inserirOrdenado(B,num);

                printf("\nConjunto A:");
                imprimir(A);

                printf("\nConjunto B:");
                imprimir(B);

                break;

            case 2:
                printf("\nRemover um elemento.\n");

                do{
                    printf("\n Qual conjunto será utilizado?\n");
                    printf("\n[1] Conjunto A;");
                    printf("\n[2] Conjunto B.\n");
                    printf("\n Opção: ");
                    scanf("%d",&opcao);

                    if(opcao != 1 && opcao != 2)
                        printf("\n Opção inválida.\n");

                }while(opcao != 1 && opcao != 2);

                printf("\nValor: ");
                scanf("%d",&num);

                if(opcao == 1)
                    A = excluiOrd(A,num);
                else
                    B = excluiOrd(B,num);

                printf("\nConjunto A:");
                imprimir(A);

                printf("\nConjunto B:");
                imprimir(B);
                break;

            case 3:
                printf("\nEsvaziar o conjunto.\n");

                do{
                    printf("\nQual conjunto será utilizado?\n");
                    printf("\n[1] Conjunto A;");
                    printf("\n[2] Conjunto B.\n");
                    printf("\nOpção: ");
                    scanf("%d",&opcao);

                    if(opcao != 1 && opcao != 2)
                        printf("\nOpção inválida.\n");

                }while(opcao != 1 && opcao != 2);

                if(opcao == 1)
                    A = limpaConjunto(A);

                else
                    B = limpaConjunto(B);

                printf("\nConjunto A:");
                imprimir(A);

                printf("\nConjunto B:");
                imprimir(B);

                break;

            case 4:
                printf("\nVerificar se o conjunto é vazio.\n");

                do{
                    printf("\nQual conjunto será utilizado?\n");
                    printf("\n[1] Conjunto A;");
                    printf("\n[2] Conjunto B.\n");
                    printf("\nOpção: ");
                    scanf("%d",&opcao);

                    if(opcao != 1 && opcao != 2)
                        printf("\nOpção inválida.\n");

                }while(opcao != 1 && opcao != 2);

                if(opcao == 1)
                    vazio(A);

                else
                    vazio(B);
                break;

            case 5:
                printf("\nVerificar se um elemento pertence a um conjunto.\n");

                do{
                    printf("\n Qual conjunto será utilizado?\n");
                    printf("\n[1] Conjunto A;");
                    printf("\n[2] Conjunto B.\n");
                    printf("\nOpção: ");
                    scanf("%d",&opcao);

                    if(opcao != 1 && opcao != 2)
                        printf("\nOpção inválida.\n");

                }while(opcao != 1 && opcao != 2);

                printf("\nValor: ");
                scanf("%d",&num);

                if(opcao == 1){
                    if(busca(A,num) == -1)
                        printf("\nO elemento não está no conjunto A.\n");
                    else
                        printf("\nO elemento está no conjunto A.\n");
                }
                else{
                    if(busca(B,num) == -1)
                        printf("\nO elemento não está no conjunto B.\n");
                    else
                        printf("\nO elemento está no conjunto B.\n");
                }
                break;

            case 6:
                printf("\nVerificar se um conjunto está contido em outro conjunto.\n");

                do{
                    printf("\n Como deseja verificar?\n");
                    printf("\n[1] A contido em B;");
                    printf("\n[2] B contido em A.\n");
                    printf("\nOpção: ");
                    scanf("%d",&opcao);

                    if(opcao != 1 && opcao != 2)
                        printf("\nOpção inválida.\n");

                }while(opcao != 1 && opcao != 2);

                if(opcao == 1){
                    printf("\nConjunto A:");
                    imprimir(A);
                    printf("\nConjunto B:");
                    imprimir(B);
                    contido(A,B);
                }
                else{
                    printf("\nConjunto B:");
                    imprimir(B);
                    printf("\nConjunto A:");
                    imprimir(A);
                    contido(B,A);
                }
                break;

            case 7:
                printf("\nVerificar se dois conjuntos são iguais.\n");

                printf("\nConjunto A:");
                imprimir(A);
                printf("\nConjunto B:");
                imprimir(B);
                igual(A,B);

                break;

            case 8:
                printf("\nVerificar se um conjunto é subconjunto de outro conjunto.\n");

                do{
                    printf("\n Como deseja verificar?\n");
                    printf("\n[1] A é subconjunto de B;");
                    printf("\n[2] B é subconjunto de A.\n");
                    printf("\nOpção: ");
                    scanf("%d",&opcao);

                    if(opcao != 1 && opcao != 2)
                        printf("\nOpção inválida.\n");

                }while(opcao != 1 && opcao != 2);

                if(opcao == 1){
                    printf("\nConjunto A:");
                    imprimir(A);
                    printf("\nConjunto B:");
                    imprimir(B);
                    subconjunto(A,B);
                }
                else{
                    printf("\nConjunto B:");
                    imprimir(B);
                    printf("\nConjunto A:");
                    imprimir(A);
                    subconjunto(B,A);
                }

                break;

            case 9:
                printf("\nFazer a união de dois conjuntos.\n");

                printf("\nConjunto A:");
                imprimir(A);
                printf("\nConjunto B:");
                imprimir(B);

                C = uniao(A,B,C);

                printf("\nUnião dos conjuntos:");
                imprimir(C);

                C = limpaConjunto(C);

                break;

            case 10:
                printf("\nFazer a interseção de dois conjuntos.\n");

                printf("\nConjunto A:");
                imprimir(A);
                printf("\nConjunto B:");
                imprimir(B);

                C = intersecao(A,B,C);

                printf("\nInterseção dos conjuntos:");
                imprimir(C);

                C = limpaConjunto(C);

                break;

            case 11:
                printf("\nFazer o complemento reAtivo de um conjunto B em um conjunto A.\n");

                do{
                    printf("\n Como deseja realizar a operação?\n");
                    printf("\n[1](A - B);");
                    printf("\n[2](B - A).\n");
                    printf("\nOpção: ");
                    scanf("%d",&opcao);

                    if(opcao != 1 && opcao != 2)
                        printf("\nOpção inválida.\n");

                }while(opcao != 1 && opcao != 2);

                if(opcao == 1){
                    printf("\nConjunto A:");
                    imprimir(A);
                    printf("\nConjunto B:");
                    imprimir(B);

                    C = complemento(A,B,C);

                    printf("\n(A - B):");
                    imprimir(C);
                }
                else{
                    printf("\nConjunto B:");
                    imprimir(B);
                    printf("\nConjunto A:");
                    imprimir(A);

                    C = complemento(B,A,C);

                    printf("\n(B - A):");
                    imprimir(C);
                }

                C = limpaConjunto(C);

                break;

            case 0:
                printf("\nPrograma encerrado");
                break;

            default:
                printf("\nopção inválida.\n Insira um dos valores do menu.\n ");
                break;
        }

    }while(opcao != 0);

    A = limpaConjunto(A);
    B = limpaConjunto(B);

    printf("\n\n");
    return 0;
}


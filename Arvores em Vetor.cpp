#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

 
//Variables Global
int verificar = 0;
int verificar_mostrar = 0;
int interacoes = 0;
 
typedef struct filho1{
    int obj;
    int menor;
    int maior;
}tipo_filho1;
 
typedef struct filho2{
    int obj;
    int menor;
    int maior;
}tipo_filho2;
 
typedef struct arvore{
    int raiz;
    tipo_filho1 f1;
    tipo_filho2 f2;
}tipo_arvore;
tipo_arvore vetor[3];
 
void iniciar(){
    for(int a = 0; a < 3; a++){
        vetor[a].raiz = 0;
        //Son {1}
        vetor[a].f1.obj = 0;
        vetor[a].f1.maior = 0;
        vetor[a].f1.menor = 0;
        //Son {2}
        vetor[a].f2.obj = 0;
        vetor[a].f2.maior = 0;
        vetor[a].f2.menor = 0;
    }
}
 
//Show
void mostrar(){
    int tipo = 0;
    for(int b = 0; b < 3; b++){
        if(b == 0){
            printf("\narvore A\n");
        }else if(b == 1){
            printf("\n\narvore B\n");
        }else{
            printf("\n\narvore C\n");
        }
        //3 TAB
        if(verificar_mostrar == 0){
            printf("    Raiz   ---->            (%d)        \n", vetor[b].raiz);
            printf("                          /     \\     \n");
            printf("    Filhos ---->       [%d]       [%d]   \n", vetor[b].f1.obj, vetor[b].f2.obj);
            printf("                      /   \\     /   \\  \n");
            printf("    Filhos ---->    [%d]  [%d]  [%d]   [%d]    \n", vetor[b].f1.menor, vetor[b].f1.maior, vetor[b].f2.menor, vetor[b].f2.maior);
        }else{
            printf("    Raiz   ---->            (%d)        \n", vetor[b].raiz);
            //Conditions
            if(vetor[b].f1.obj == -9999){
                printf("                                \\     \n");
                printf("    Filhos ---->                  [%d]   \n", vetor[b].f2.obj);
                tipo = 4;
            }else if(vetor[b].f2.obj == -9999){
                printf("                          /          \n");
                printf("    Filhos ---->       [%d]          \n", vetor[b].f1.obj);
                tipo = 2;
            }else{
                printf("                          /     \\     \n");
                printf("    Filhos ---->       [%d]       [%d]   \n", vetor[b].f1.obj, vetor[b].f2.obj);
            }
 
            if(tipo == 0){
                if(vetor[b].f1.menor == -9999){
                    printf("                          \\     /   \\  \n");
                    printf("    Filhos ---->          [%d]  [%d]   [%d]    \n", vetor[b].f1.maior, vetor[b].f2.menor, vetor[b].f2.maior);
                }else if(vetor[b].f1.maior == -9999){
                    printf("                      /          /   \\  \n");
                    printf("    Filhos ---->    [%d]        [%d]   [%d]    \n", vetor[b].f1.menor, vetor[b].f2.menor, vetor[b].f2.maior);
                }else if(vetor[b].f2.menor == -9999){
                    printf("                      /   \\         \\  \n");
                    printf("    Filhos ---->    [%d]  [%d]         [%d]    \n", vetor[b].f1.menor, vetor[b].f1.maior, vetor[b].f2.maior);
                }else if(vetor[b].f2.maior == -9999){
                    printf("                      /   \\     /     \n");
                    printf("    Filhos ---->    [%d]  [%d]  [%d]   \n", vetor[b].f1.menor, vetor[b].f1.maior, vetor[b].f2.menor);
                }else{
                    printf("                      /   \\     /   \\  \n");
                    printf("    Filhos ---->    [%d]  [%d]  [%d]   [%d]    \n", vetor[b].f1.menor, vetor[b].f1.maior, vetor[b].f2.menor, vetor[b].f2.maior);
                }
            }else if(tipo == 4){
                if(vetor[b].f2.menor == -9999){
                    printf("                                     \\  \n");
                    printf("    Filhos ---->                       [%d]    \n", vetor[b].f2.maior);
                }else if(vetor[b].f2.maior == -9999){
                    printf("                                 /    \n");
                    printf("    Filhos ---->                [%d]  \n", vetor[b].f2.menor);
                }else{
                    printf("                                 /   \\  \n");
                    printf("    Filhos ---->                [%d]   [%d]    \n", vetor[b].f2.menor, vetor[b].f2.maior);
                }
            }else{
                if(vetor[b].f1.menor == -9999){
                    printf("                          \\     \n");
                    printf("    Filhos ---->          [%d]   \n", vetor[b].f1.maior);
                }else if(vetor[b].f1.maior == -9999){
                    printf("                      /   \n");
                    printf("    Filhos ---->    [%d]  \n", vetor[b].f1.menor);
                }else{
                    printf("                      /   \\     \n");
                    printf("    Filhos ---->    [%d]  [%d]   \n", vetor[b].f1.menor, vetor[b].f1.maior);
                }
            }
        }
        verificar_mostrar++;
    }
}
 
//Panel
void painel(){
    if(verificar == 0){
        printf(" >> arvore Binaria - Inseriu: %d vezes\n", interacoes);
    }else{
        printf("\n\n >> arvore Binaria - Inseriu: %d vezes\n", interacoes);
    }
    verificar++;
    printf("    1 - Mostrar\n");
    printf("    2 - Inserir\n");
    printf("    3 - Remover\n");
    printf("    4 - Sair\n\n");
}
 
//Insert
void inserir(int a, int b, int cc){
    //Default
    for(int c = 0; c < 3; c++){
        if(c == 0){
            vetor[c].raiz = a;
        }else if(c == 1){
            vetor[c].raiz = b;
        }else{
            vetor[c].raiz = cc;
        }
        //Son {1}
        vetor[c].f1.obj = vetor[c].raiz-2;
        vetor[c].f1.maior = vetor[c].f1.obj+1;
        vetor[c].f1.menor = vetor[c].f1.obj-1;
        //Son {2}
        vetor[c].f2.obj = vetor[c].raiz+1;
        vetor[c].f2.maior = vetor[c].f2.obj+3;
        vetor[c].f2.menor = vetor[c].f2.obj-1;
    }
}
 
//Remove
void remover(int raiz, int valor){
    if (raiz != 0 && raiz != 1 && raiz != 2){
        printf("\n >> Comando invalido");
    }else{
        //Son {1}
        if(vetor[raiz].f1.obj == valor){
            vetor[raiz].f1.obj = -9999;
        }
        if(vetor[raiz].f1.menor == valor){
            vetor[raiz].f1.menor = -9999;
        }
        if(vetor[raiz].f1.maior == valor){
            vetor[raiz].f1.maior = -9999;
        }
        //Son {2}
        if(vetor[raiz].f2.obj == valor){
            vetor[raiz].f2.obj = -9999;
        }
        if(vetor[raiz].f2.menor == valor){
            vetor[raiz].f2.menor = -9999;
        }
        if(vetor[raiz].f2.maior == valor){
            vetor[raiz].f2.maior = -9999;
        }
    }
}
 
int main()
{
    //Accentuation
    setlocale(LC_ALL,"");
 
    //Variables
    int count = 0;
    int comando;
 
    //Start
    iniciar();
 
    
        //Variables **
        int a = 0;
        int b = 0;
        int c = 0;
        int passar;
        int elem;
 
        //Panel
        painel();
 
        //Command's
        printf("Comando: ");
        fflush(stdin);
        scanf("%d", &comando);
 
        switch(comando){
            case 1:
                mostrar();
                break;
            case 2:
                printf(" >> Inserir");
                //A
                printf("\n      Raiz(arvore A) = ");
                scanf("%d", &a);
                //B
                printf("\n      Raiz(arvore B) = ");
                scanf("%d", &b);
                //C
                printf("\n      Raiz(arvore C) = ");
                scanf("%d", &c);
 
                inserir(a, b, c);
                printf("\n >> Raizes criadas e elementos preenchidos");
                interacoes++;
                break;
            case 3:
                printf(" >> Remover");
                printf("\n      Escolha a arvore em seguida o elemento que deseja tirar\n");
                printf("            0 - arvore A\n");
                printf("            1 - arvore B\n");
                printf("            2 - arvore C\n\n");
 
                printf("arvore(0,1 ou 2) = ");
                scanf("%d", &passar);
 
                printf("Elemento = ");
                scanf("%d", &elem);
 
                remover(passar, elem);
                break;
            case 4:
                return 0;
                break;
        }
    
    //End
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct pessoa{
    char nome[40];
    int numero;
    struct pessoa *prox;
};
typedef struct pessoa agenda;

void insere(agenda *p);
void procura_pelo_nome(agenda *ini);
void procura_pelo_numero(agenda *ini);

int main(){
    agenda *ini, *pos;
    int op;
    ini = (agenda*)malloc(sizeof(agenda));
    ini->prox=NULL;
    do{
        printf("Selecione a opção: \n
                1. Inserir contato. \n
                2. Procurar nome pelo numero. \n
                3. Procurar numero pelo nome. \n
                4. Sair. \n");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            inserir(ini);
            break;
        case 2:
            procura_pelo_nome(ini);
            break;
        case 3:
            procura_pelo_numero(ini);
            break;
        default:
            break;
        };


    }
    while(op!=4);

    return 0;
}


void insere(agenda *p){

    agenda *nova;
    while(p->prox!=NULL){
        p=p->prox;
    };

    nova = (agenda *)malloc(sizeof(agenda));
    scanf("%s",nova->nome);
    scanf("%d",nova->numero);
    nova->prox=p->prox;
    p->prox=nova;

};

void procura_pelo_nome(agenda *ini){
    agenda *p;
    char n[40];
    scanf("%s",n);
    for(p=ini;p->prox!=NULL;p=p->prox){
        if(strcmp(n,p->nome)==0)
            printf("Numero: %d",p->numero);
    };
};

void procura_pelo_numero(agenda *ini){
    agenda *p;
    int n;
    scanf("%d",&n);
    for(p=ini;p->prox!=NULL;p=p->prox){
        if(n==p->numero);
            printf("Nome: %s",p->nome);
    };
};
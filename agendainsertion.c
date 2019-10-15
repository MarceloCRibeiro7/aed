#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int i = sizeof(int);
int c = sizeof(char);
void *inserir(void *pBuffer);
void listar(void *pBuffer);
void *apagar(void *pBuffer);
void buscar(void *pBuffer);
void insertion(void *pBuffer);
int main(){
    void *pBuffer;
    
    pBuffer = malloc(5*i + 10*c);//numero de contatos, for(j), while(i), temp e switch
    *(int *)pBuffer = 0;
for(;;){
    printf("1)Inserir\n");
    printf("2)Apagar\n");
    printf("3Listar\n");
    printf("4)Buscar\n");
    printf("5)Ordenar\n");
    printf("5)Sair\n");
    scanf("%d",(int*)(pBuffer + i*4));
    switch (*(int*)(pBuffer + i*4))
    {
    case 1:
        pBuffer = inserir(pBuffer);
        break;
    case 2:
        pBuffer = apagar(pBuffer);
        break;
    case 3:
        listar(pBuffer);
        break;
    case 4:
        buscar(pBuffer);
        break;
    case 5:
        insertion(pBuffer);
        break;
    case 6:
        free(pBuffer);
        exit(0);
        break;
    default:
        break;
    }
}
    return 0;
}

void *inserir(void *pBuffer){
    pBuffer = realloc(pBuffer,(5*i+ 10*c) + ((10*c + i) * ((*(int*)pBuffer)+1)));

    printf("Insira o nome:");
    scanf("%s",(char*)pBuffer + 5*i+ 10*c + (10*c + i)*(*(int*)pBuffer));

    printf("Insira o numero:");
    scanf("%d",(int*)(pBuffer + 5*i+ 10*c + (10*c + i)*(*(int*)pBuffer) + 10*c));

    *(int*)pBuffer= *(int*)pBuffer + 1; 

}
void listar(void *pBuffer)
{

    for((*(int*)(pBuffer +i)) = 0; (*(int*)(pBuffer +i)) < *(int*)pBuffer; *(int*)(pBuffer+i) = *(int*)(pBuffer + i)+1) {
        printf("Nome: %s\n",(char*)pBuffer + i*5+ 10*c + (10*c + i)*(*(int*)(pBuffer+i)));
        printf("Numero: %d\n",*(int*)(pBuffer + (5*i+ 10*c +10*c + ((10*c + i)*(*(int*)(pBuffer+i))))));
        //printf("Temporario: %s\n",(char*)pBuffer + 5*i);
    } 
}
void *apagar(void *pBuffer){
    char *nome;
    nome = (char*)malloc(10*c);
    scanf("%s",nome);
    for((*(int*)(pBuffer + i))=0;(*(int*)(pBuffer + i))<(*(int*)pBuffer);(*(int*)(pBuffer + i) = (*(int*)(pBuffer + i)) + 1)){
        if(strcmp((char*)pBuffer + 5*i+ 10*c +(10*c + i)*(*(int*)(pBuffer + i)) ,nome) == 0){
            strcpy((char*)pBuffer + 5*i+ 10*c +(10*c + i)*(*(int*)(pBuffer + i)),(char*)pBuffer + 5*i+ 10*c +(10*c + i)*(*(int*)pBuffer - 1) );
            *(int*)(pBuffer + 5*i+ 10*c +10*c +(10*c + i)*(*(int*)(pBuffer + i))) = *(int*)(pBuffer + 5*i+ 10*c +10*c +(10*c + i)*(*(int*)pBuffer - 1));
            *(int*)pBuffer = *(int*)pBuffer - 1;
            pBuffer = realloc(pBuffer, 5*i + (10*c + i)*(*(int*)pBuffer));
            
        }
    }
    return pBuffer;    
}
void buscar(void *pBuffer){
    char *nome;
    nome = (char*)malloc(10*c);
    scanf("%s",nome);
    for((*(int*)(pBuffer + i))=0;(*(int*)(pBuffer + i))<(*(int*)pBuffer);(*(int*)(pBuffer + i) = (*(int*)(pBuffer + i)) + 1))
        if(strcmp((char*)pBuffer + 5*i + 10*c +(10*c + i)*(*(int*)(pBuffer + i)) ,nome) == 0)
            printf("Numero:%d\n",*(int*)(pBuffer + 5*i + 10*c + 10*c +(10*c + i)*(*(int*)(pBuffer + i))));
}

void insertion(void *pBuffer){
	for (*(int*)(pBuffer + i)=1; *(int*)(pBuffer + i)<*(int*)(pBuffer); *(int*)(pBuffer + i) += 1) { 
		*(int*)(pBuffer + 2*i) =*(int*)(pBuffer + i) - 1;
		*(int*)(pBuffer + 3*i) = *(int*)(pBuffer + 5*i+ 10*c + 10*c + (10*c + i)*(*(int*)(pBuffer + i))); 
		strcpy((char*)pBuffer + 5*i, (char*)pBuffer + 5*i + 10*c + (10*c + i)*(*(int*)(pBuffer + i)));
        while ( (*(int*)(pBuffer + 2*i)>=0) && (*(int*)(pBuffer + 3*i) < *(int*)(pBuffer + 5*i+ 10*c +10*c+ (10*c + i)*(*(int*)(pBuffer + 2*i)))) ) { 
			*(int*)(pBuffer + 5*i+ 10*c + (10*c + i) +10*c + (10*c + i)*(*(int*)(pBuffer + 2*i))) = *(int*)(pBuffer + 5*i+ 10*c + 10*c + (10*c + i)*(*(int*)(pBuffer + 2*i)));
			strcpy((char*)pBuffer + 5*i+ 10*c+ (10*c + i) + (10*c + i)*(*(int*)(pBuffer + 2*i)),(char*)pBuffer + 5*i+ 10*c + (10*c + i)*(*(int*)(pBuffer + 2*i)));
            *(int*)(pBuffer + 2*i)-=1;
             
		}//while

		*(int*)(pBuffer + 5*i+ 10*c + 10*c + (10*c + i) + (10*c + i)*(*(int*)(pBuffer + 2*i))) = *(int*)(pBuffer + 3*i); 
        strcpy((char*)pBuffer + 5*i+ 10*c+ (10*c + i) + (10*c + i)*(*(int*)(pBuffer + 2*i)),(char*)pBuffer + 5*i );

    }//for
 }//Insertion
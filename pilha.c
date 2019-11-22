#include<stdio.h>
#include<stdlib.h>

struct cel {
	int conteudo;
	char nome[30];
	struct cel *prox;
};

typedef struct cel celula;
void insere(int x, celula * p);
void insere_no_fim(int x, celula * p);
void imprime(celula * ini);
celula *busca(int x, celula * ini);
celula *cria(void);
void remova(int y, celula * ini);
void remova_no_fim(celula * ini);
void remova_end(celula * p);
void salva_no_file(celula * ini);

int main()
{
	celula *ini, *pos;
	ini = cria();
	/*insere(10, ini);
	insere(100, ini);
	insere_no_fim(1000, ini);
	imprime(ini);
	pos = busca(100, ini);
	insere(99, pos);
	imprime(ini);
	remova(99, ini);
	imprime(ini);
	pos = busca(100, ini);
	remova_end(pos);
	printf("\n\n");
	
	imprime(ini);
	printf("\n\n");
	remova_no_fim(ini);
	imprime(ini);
	salva_no_file(ini);
	*/
	insere(10,ini);
	insere(9,ini);
	insere(8,ini);
	insere(7,ini);
	//imprime(ini);
	remova_no_fim(ini);
	remova_no_fim(ini);
	remova_no_fim(ini);
	insere(25,ini);
	remova_no_fim(ini);
	remova_no_fim(ini);
	
	//imprime(ini);
	return 0;
}

celula *cria(void)
{
	celula *start;

	start = (celula *) malloc(sizeof(celula));
	start->prox = NULL;
	return start;
}

void insere(int x, celula * p)
{
	celula *nova;

	nova = (celula *) malloc(sizeof(celula));
	nova->conteudo = x;
	fgets(nova->nome,30,stdin);
	nova->prox = p->prox;
	p->prox = nova;
}


void insere_no_fim(int x, celula * p)
{
	celula *nova;
	
	do{
	p=p->prox;
	}
	while(p->prox!=NULL);
	
	nova = (celula *) malloc(sizeof(celula));
	nova->conteudo = x;
	nova->prox = p->prox;
	p->prox = nova;
}


void imprime(celula * ini)
{
	celula *p;
	for (p = ini->prox; p != NULL; p = p->prox)
		printf("%d\n", p->conteudo);
}

celula *busca(int x, celula * ini)
{
	celula *p;
	p = ini->prox;
	while (p != NULL && p->conteudo != x)
		p = p->prox;
	return p;
}

void remova(int y, celula * ini)
{
	celula *p, *q;
	p = ini;
	q = ini->prox;
	while ((q != NULL) && (q->conteudo != y)) {
		p = q;
		q = q->prox;
	}
	if (q != NULL) {
		p->prox = q->prox;
		free(q);
	}
}

void remova_no_fim(celula * ini){
	
	celula *p, *q;
	p= ini;
	q = ini->prox;
	while(q->prox!=NULL){
		p=q;
		q=q->prox;
	}
	;
	printf("\nPop: %d\n",q->conteudo);
	printf("\n%s\n",q->nome);
	free(q);
	p->prox=NULL;
}

void remova_end(celula * p)
{
	celula *morta;
	morta = p->prox;
	printf("\nPop: %d\n",morta->conteudo);
	p->prox = morta->prox;
	free(morta);
}


void salva_no_file(celula * ini){
	FILE *fp;
	celula *p;
	
	if ((fp = fopen("database.txt", "w")) == NULL) {
		printf("Erro ao abrir o arquivo database\n");
		exit(1);
	}
	for (p = ini->prox; p != NULL; p = p->prox)
		fprintf(fp,"%d",p->conteudo);
	fclose(fp);
}

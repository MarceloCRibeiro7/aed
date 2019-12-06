//Estudos arvores binarias

#include<stdio.h>
#include<stdlib.h>

struct tree{
	int value;
	struct tree *left;
	struct tree *right;
};

typedef struct tree tree;
tree * put(tree *p,tree *n);
void printpre(tree *p);
void printin(tree *p);
void printpos(tree *p);

int main(){
	int opt;
	tree *root=NULL;
	tree *n;
	int aux;
				
				
	for(;;){
		printf("\nMENU:\n\n");
		printf("1.Inserir\n");
		//printf("2.Excluir\n");
		printf("3.Listar\n");
		printf("4.Sair\n");
		printf("Digite a opcao desejada:");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				
				printf("Insira o valor:");
				scanf("%d",&aux);
				n=(tree*)malloc(sizeof(tree));
				n->value=aux; 
				n->left=NULL; 
				n->right=NULL;
				root = put(root,n);
				break;
			case 2:
				
				break;
			case 3:
				printpre(root);
				printf("\n");
				printin(root);
				printf("\n");
				//printpos(root);
				//printf("Valor:%d\n",root->value);
				//printf("Valor:%d\n",root->left->left->value);
				//printf("Valor:%d\n",root->right->value);
				
				break;
			case 4:
				exit(0);
				break;
			default:
				break;
		}
	}
}

tree * put(tree *p,tree *n){
	if(p == NULL)
		return n;
	if(n->value<p->value)
		p->left=put(p->left,n);
	else
		p->right=put(p->right,n);
	
	return p;
}
void printpre(tree *p){
	if(p!=NULL){
		printf("%d",p->value);
		printf("(");
		printpre(p->left);
		printpre(p->right);
		printf(")");
	}
}
	
void printin(tree *p){
	if(p!=NULL){
		if(p->left!=NULL)
			printin(p->left);
		printf("%d",p->value);
		printf("->");
		if(p->right!=NULL)
			printin(p->right);
	}
}
	
void printpos(tree *p){ // sob reformas
	if(p!=NULL){
		if(p->left==NULL){
		printf("%d",p->value);
		printf("->");
		}
		else
		if(p->left!=NULL){
			printpos(p->left);
		}
		
		if(p->right!=NULL)
			printin(p->right);
	}
}
	
	
	
	
	
	
	
	
	

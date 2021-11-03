#include <stdio.h>
#include "calc.h"

/* Arquivo que define a interface da calculadora */
typedef struct calc Calc;

/* Funções exportadas */
Calc* cria_calc(char* f);
void operando(Calc* c, float v);
void operador(Calc* c, char op);
void libera_calc(Calc* c);

struct calc {
	char f[21]; /*formato para impressão*/
	Pilha* p; /*pilha de operandos*/
};

Calc* cria_calc(char* formato){
	Calc* c= (Calc*)malloc(sizeof(Calc));
	strcpy(f->f,formato);
	c->p = cria(); //Cria Pilha Vazia
	return c;
}
void operador(Calc* c, char op){
	float v1,v2,v;
	//desempilha operandos
	if (vazia(c->p));
		v2 = 0.0;
	else
		v2=pop(c->p);
	if(vazia(c->p))
		v1=0.0;
	else
		v1=pop(c->p);
	//operações
	switch (op){
		case '+': v=v1+v2 break;
		case '-': v=v1-v2 break;
		case '*': v=v1*v2 break;
		case '/': v=v1/v2 break;
	}
	//empilha resultado
	push(c->p,v);
	//imprime topo da pilha
	print(c->f,v);
}
void libera_calc(Calc* c){
	libera(c->p);
	free(c);
}

int main(void){
	char c;
	float v;
	Calc* calc;
	//calculadora com precisao de 2 casas decimais
	calc = cria_calc("%.2f\n")
	do {
		//lê proximo caractere não branco
		scanf("%c",&c);
		if(c=='+' || c=='-' || c='*' || c='/'){
			operador(calc,c);
		}
		else{
			ungetc(c,stdin);
			if(scanf("%f",&v) == 1)
				operando(calc,v);
		}
	}
	while(c!='q');
	libera_calc(calc);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int quantidade;
typedef struct Relacao{
    int x[20];
    int y[20];
    char nome;
    int tamanho;
}
Relacao[100];
void imprime(Relacao);
void insere(Relacao);
void operacao_composicao(Relacao);
void operacao_inversao(Relacao);
int valida_nome(Relacao,char);
int main(){
    Relacao relacao;
    int op;  
    system("cls");
    fflush(stdin);
    while(1){
        printf("Digite a opcao:\nInserir relacao(1);\nImprimir relacao (2);\nOperacao de relacao(3);\nOperacao de inversao(4);\nSair(5);\n");
        
        scanf("%d",&op);
        switch(op){
            case 1: 
                insere(relacao);
                break;
            case 2:
                imprime(relacao);
                break;
            case 3:
                operacao_composicao(relacao);
                break;
            case 4:
                operacao_inversao(relacao);
                break;
            case 5:
                exit(1);
        }
    }
    

}


void insere(Relacao relacao){
    char nome;
    system("cls");
    
    
    while(!valida_nome(relacao,nome)){
        printf("Digite um nome valido para a relacao\n");
        scanf(" %c",&nome);
        
    }
    relacao[quantidade].nome = nome;
    relacao[quantidade].tamanho = 0;
    while(1){
        char quebrar; 
        printf("Digite o par ordenado no fomato: x y, para continuar digite ','\n");
        
        scanf("%d %d",&relacao[quantidade].x[relacao[quantidade].tamanho],&relacao[quantidade].y[relacao[quantidade].tamanho]);
        relacao[quantidade].tamanho++;
        getchar();
        scanf("%c",&quebrar);
        if(quebrar != ',') // se o cabra nao digitar ',' o baguio sai do loop
            break;
    }
    system("cls");
    quantidade++;
    
    
}
void imprime(Relacao relacao ){
    system("cls");
    printf("RELACOES:\n");
    for(int i=0;i<quantidade;i++){
        printf("(%d) %c : ",i+1,relacao[i].nome);
            for(int j = 0; j<relacao[i].tamanho;j++)
                printf("{(%d,%d)} ",relacao[i].x[j],relacao[i].y[j]);
            
        printf("\n");
    }
    printf("\n\n");

}
void operacao_composicao(Relacao relacao){
    int op1,op2,check;
    system("cls");
    printf("Digite os numero das relacoes (no formato: R S e elas devem ser compativeis)\n");
    scanf("%d",&op1);
    scanf("%d",&op2);
    getchar();
    op1--;
    op2--;
    for (int i = 0;i<relacao[op1].tamanho;i++){
        for(int j = 0;j<relacao[op2].tamanho;j++){
            if(relacao[op1].y[i]==relacao[op2].x[j])
                printf("%c o %c = {(%d,%d)}\n",relacao[op1].nome,relacao[op2].nome,relacao[op1].x[i],relacao[op2].y[j]);
                check++;
        }
    }
    check?printf("operacao invalida\n"):printf("\n");
    printf("\n");
    check = 0;
    
}
void operacao_inversao(Relacao relacao){
    int op;
    system("cls");
    printf("Digite o numero da relacao\n");
    scanf("%d",&op);
    op--;
    int tam = relacao[op].tamanho,temp;
    for(int i=0;i<tam;i++){
        temp = relacao[op].x[i];
        relacao[op].x[i] = relacao[op].y[i];
        relacao[op].y[i] = temp;
        
    }
    system("cls");
    printf("inversao feita com sucesso ;)\n\n");
    
    
}
int valida_nome(Relacao relacao,char nome){
    int i=0;
    if(nome < 65 || nome > 122)
        return 0;
    while(i<quantidade){
        if (nome == relacao[i].nome)
            return 0;
        i++;
    }
    return 1;

}


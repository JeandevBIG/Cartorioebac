#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das string

int regis()
{	
	//inicio da cria��o das strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o das strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file;//cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo com o "w" de escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); 
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite um nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen (arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consul()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	char cpf[40];
	char conteudo[150];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Arquivo n�o localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nEssas s�o as informa��es solicitadas: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
		
}

int del()
{
	setlocale(LC_ALL, "Portuguese");
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
		
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema! \n");
		system ("pause");
	}
	
}


int main() 
{
	int opcao=0; //definindo variav�is
	int laco=1;

	for(laco=1;laco=1;)
	{
	
		system ("cls"); //responsavel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); 

    	printf(" ### CArt�rio da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a op��o desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("Op��o: "); //fim do menu

		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system ("cls");
		
		switch (opcao) //inicio da sele��o do menu
		{
			case 1: 
			regis(); //chamada de fun��es
			break;
			
			case 2:
			consul();
			break;
			
			case 3:
			del();
			break;
			
			default:
			printf("Op��o inv�lida!\n");
			system("pause");
			break;
		} //fim da sele��o
	}
}

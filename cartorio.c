#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o em espa�o de mem�ria
#include <locale.h> //Biblioteca de aloca��es de texto por regi�o
#include <string.h> //Biblioteca respons�vel por cuidar das strings


int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//Inicio cria��o de vari�veis/strings
	char arquivo [40];
	char cpf[40]; //Os colchetes significa que estamos criando uma string CPF do tipo [40]
	char nome[40];	
	char sobrenome[40];	
	char cargo[40];
	//Final da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Respos�vel por copiar os valores da string

	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo e o "W" significa escrecar
	fprintf(file,cpf); //salvo o valor da vari�vel
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s" ,sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
}

int consultar()
{	
	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
		
	char cpf[40]; //Armazenar a resposta do usu�rio
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file; //arquivo
	file = fopen(cpf,"r"); //Abre o arquivo e read ler o arquivo
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!. \n");	
		
	}
	while(fgets(conteudo, 200, file) != NULL) //While � ENQUANTO
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
}
	
	
int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema! \n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;) //"FOR" � usado para repeti��o
	{
		system("cls"); //Respons�vel por limpar a tela
	
	
		setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
		printf("###Cart�rio da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a op��o desejada do menu: \n\n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n\n"); //Fim do menu
		printf("\t4 - Sair do sistema \n\n");
		printf("Op��o: ");
	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
		system("cls"); //Fun��o serve para limpar a tela das mensagens anteriores
	
		switch(opcao) //Fun��o serve para diminuir a quantidade de "if�s"
		{
			case 1: //N�o devemos esquecer que o switch sempre tem que colocar "CASE" ":" e para finalizar "break"
			registro(); //Chamdda de fun��es
			break;
		
			case 2:
			consultar(); //Chamando a fun��o CONSULTAR que criamos l� encima. Para chamar a fun��o necess�rio colocar ";" ponto e virgula.
			break;
		
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			break;
		}	
	}
	
}



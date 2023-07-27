#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação em espaço de memória
#include <locale.h> //Biblioteca de alocações de texto por região
#include <string.h> //Biblioteca responsável por cuidar das strings


int registro() //Função responsável por cadastrar os usuários no sistema
{
	//Inicio criação de variáveis/strings
	char arquivo [40];
	char cpf[40]; //Os colchetes significa que estamos criando uma string CPF do tipo [40]
	char nome[40];	
	char sobrenome[40];	
	char cargo[40];
	//Final da criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Resposável por copiar os valores da string

	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo e o "W" significa escrecar
	fprintf(file,cpf); //salvo o valor da variável
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
		
	char cpf[40]; //Armazenar a resposta do usuário
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file; //arquivo
	file = fopen(cpf,"r"); //Abre o arquivo e read ler o arquivo
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!. \n");	
		
	}
	while(fgets(conteudo, 200, file) != NULL) //While é ENQUANTO
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
}
	
	
int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema! \n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;) //"FOR" é usado para repetição
	{
		system("cls"); //Responsável por limpar a tela
	
	
		setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
		printf("###Cartório da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n\n"); //Fim do menu
		printf("\t4 - Sair do sistema \n\n");
		printf("Opção: ");
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário
	
		system("cls"); //Função serve para limpar a tela das mensagens anteriores
	
		switch(opcao) //Função serve para diminuir a quantidade de "if´s"
		{
			case 1: //Não devemos esquecer que o switch sempre tem que colocar "CASE" ":" e para finalizar "break"
			registro(); //Chamdda de funções
			break;
		
			case 2:
			consultar(); //Chamando a função CONSULTAR que criamos lá encima. Para chamar a função necessário colocar ";" ponto e virgula.
			break;
		
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;
		}	
	}
	
}



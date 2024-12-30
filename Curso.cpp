#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o 
#include <string.h> //biblioteca respons�vel pelas strings

int registrar()// Fun��o responsp�vel pelo cadastro de usurarios
{
	//inicio cria��o de variaveis/string
	char arquivo[50];
	char cpf[40];
	char nome[40];
	char sobrenome[60];
	char cargo[40];
	//final cria��o de variaveis/string
	
	printf("Digite o CPF(APENAS N�MEROS): ");//coletando informa��o do usu�rio
	scanf("%s", cpf);// %s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valore das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo,"w"); // cria o arquivo, "W" signifca escrever
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Nome a ser Cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Sobrenome a ser Cadastrado: ");
	scanf("%s",sobrenome);
		
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);	
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Cargo a ser Cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);	
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
}	

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel localizar esse CPF! \n ");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	system ("pause");
	
}

int deletar()
{

	char cpf[40];

	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file =fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o esta cadastrado\n");
		system("pause");	
			
	}
}

int main()
{
	int opcao=0; //Definindo as vari�veis
	int x=1;
	
	for(x=1;x=1;)
	{
		
		system("cls"); //limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("###Cart�rio da EBAC###\n\n"); //Inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t 1-Registrar os nomes \n");
		printf("\t 2-Consultar os nomes \n");	
		printf("\t 3-Detelar os nomes \n\n"); 
		printf("Op��o: ");//Fim do menu
	
		scanf("%d",&opcao); //Armazenando escolhas usu�rio
	
		system("cls");
		
		switch(opcao)	
		{
			case 1:
			registrar(); //chamada de fun��es
			break;		
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o esta dispon�vel\n");
			system("pause");
			break;	
		} // fim da sele��o
	}
}

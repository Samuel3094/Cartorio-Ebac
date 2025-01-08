#include <stdio.h> //Biblioteca de comunicação como usuário 
#include <stdlib.h> //Biblioteca de alocação de espaços na memoria 
#include <locale.h> //biblioteca de alocações de texto por região 
#include <string.h> //Biblioteca que manipula as strings

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //copia o valor da str cpf para a str arquivo 
	
	FILE *file; //chama a função file para criar um arquivo 
	file = fopen(arquivo,"w"); //cria o arqivo
	
	fprintf(file,cpf); //imprime o valor de cpf dentro do arquivo 
	fclose(file);//fecha essa operação no arquivo 
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	
}
int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf [40];
	char conteudo[300];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado.\n");
	}
	while(fgets(conteudo,300,file)!= NULL)
	{
		printf("Essas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}
int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuario a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuario não se encontra no sistema\n");
		system("pause");
		fclose(file);
	}
	else
	{
		remove(cpf);
		printf("Usuário deletado \n");
		system("pause");
	}
	
}
int main()
	{
	
	int opcao=0;
	int x=1;
	char senhadg[]="a";
	int comparacao;
	
	printf("### Cartório da Ebac\n\n");
	printf("Login de Administrador\n\nDigite sua senha: ");
	scanf("%s",senhadg);
	
	comparacao = strcmp(senhadg,"admin");
	
	if(comparacao == 0)
	{
	
	
	
		for(x=1;x=1;)
		{			
				
			setlocale(LC_ALL, "Portuguese");
			system("cls");
		
			printf("### Cartório da Ebac\n\n");
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Registrar Nomes\n ");
			printf("\t2 - Consultar nomes\n ");
			printf("\t3 - Deletar nomes\n \n ");
			printf("\t4 - Sair do Sistema\n\n");
			printf("Opção: "); //fim do menu
	
			scanf("%d", &opcao);
		
			system("cls");
	
			switch(opcao)
			{
				case 1:
					registro();
				    break;
			
				case 2:
					consulta();
					break;
				
			
				case 3:
					deletar();
					break;
				
				case 4:
					printf("Obrigado por utilizar o sistema\n");
					return 0;
					break;	
			
				default:
					printf("Esta opcão não está disponivel \n");
					system("pause");
					break;
			}
		}
	}
	else
		printf("Senha Incorreta");
}

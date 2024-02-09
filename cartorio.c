#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //bibloteca de alocação espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável para cuidar das strings

int incluir() //função "secundaria" para deixar o código mais "leve", esta função só será chamada quando o usuário apertar o nº1 no menu pricipal
{
	setlocale(LC_ALL, "Portuguese");
	
	char arquivo [20]; //nome do arquivo que será criado no pc
	char cpf[20]; //variáveis tipo char (caracteres) / o colchetes significa que está sendo criado uma string de 20 caracteres
	char nome[20];
	char sobrenome[40];
	char cargo[20];
	
	printf("Você selecionou a opção Incluir nomes\nPor favor digite o CPF do usuário que deseja incluir: ");
	scanf("%s",cpf); //armazena a variável (%s é para armazenar string)
	
	strcpy(arquivo,cpf); //responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo (FILE é função da biblioteca
	file = fopen(arquivo, "w");  //vai criar um arquivo com o nome do arquivo (arquivo=cpf), e vai usar o "w" para também escrever o cpf dentro deste arquivo
	fprintf(file,cpf); //fprintf é para o file armazenar o que será escrito, neste caso o cpf
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //o "a" é para alterar o arquivo que já foi criado no passo anterior
	fprintf(file, "; ");
	fclose(file);
	
	printf("Por favor digite o nome: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, " ");
	fclose(file);
	
	printf("Por favor digite o sobrenome: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "; ");
	fclose(file);
	
	printf("Por favor digite o cargo: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	
	system("pause");
}

int pesquisar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[20];
	char conteudo [200];
	
	printf("Você selecionou a opção Pesquisar nomes\nPor favor digite o CPF do usuário que deseja pesquisar: \n");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo. CPF não localizado!");
	}
	
	while (fgets(conteudo, 200, file) != NULL);
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[20];
	
	printf("Voce selecionou a opção Deletar nomes\nPor favor digite o CPF do usuário que deseja deletar: \n");
	scanf("%s",cpf);

	remove(cpf);	

	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema\n");
	}

	system("pause");
}

int main() //funcão principal
{
	int opcao=0; //variável para as opções do menu (1 "=" é para setar o valor da opção em zero, para que a opção não fique com valor variável de memória)
	int laco=1; //variável para a repetição do menu após selecionar a opção desejada
	char senhadigitada [10]="a";
	int comparacao;
	
	printf("~~~ Cartório da EBAC ~~~\n");
	printf("Login de administrador\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		for(laco=1;laco=1;) //repetição das opções do menu
		{
		
			system ("cls"); //system = "falar com o sistema operacional (não mostra os menus anteriores até o usuario terminar a opção atual)
		
			setlocale(LC_ALL, "Portuguese"); //setar a lingua portuguesa
		
			printf("~~~ Cartório da EBAC ~~~\n\n"); //printf = mostrar para o usuário o texto que está dentro das aspas
			printf("Por favor, selecione uma das opções a seguir\n\n");
			printf("\t1-Incluir usuário\n");
			printf("\t2-Pesquisar usuário\n");
			printf("\t3-Deletar usuário\n\n\n");
			printf("\t4-Sair do sistema\n\n");
			printf("Opção desejada: ");
		
			scanf("%d", &opcao); // escaneia o valor que o usuário coloca (%d é para armazenar o valor de nº inteiro e o &opção é onde será armazenado)
		
			system ("cls"); //system = "falar com o sistema operacional (não mostra os menus anteriores até o usuario terminar a opção atual)
		
			switch(opcao)
			{
				case 1:
				incluir();
				break;
			
				case 2:
				pesquisar();
				break;
			
				case 3:
				deletar();
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema\n");
				return 0;
				break;
			
				default:
				printf("Esta opção não existe, por favor escolha uma opção válida\n");
				system("pause");
				break;
			}
		}
	}
	else
	{
		printf("Senha incorreta!");
	}
}

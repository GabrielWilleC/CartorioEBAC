#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //bibloteca de aloca��o espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel para cuidar das strings

int incluir() //fun��o "secundaria" para deixar o c�digo mais "leve", esta fun��o s� ser� chamada quando o usu�rio apertar o n�1 no menu pricipal
{
	setlocale(LC_ALL, "Portuguese");
	
	char arquivo [20]; //nome do arquivo que ser� criado no pc
	char cpf[20]; //vari�veis tipo char (caracteres) / o colchetes significa que est� sendo criado uma string de 20 caracteres
	char nome[20];
	char sobrenome[40];
	char cargo[20];
	
	printf("Voc� selecionou a op��o Incluir nomes\nPor favor digite o CPF do usu�rio que deseja incluir: ");
	scanf("%s",cpf); //armazena a vari�vel (%s � para armazenar string)
	
	strcpy(arquivo,cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo (FILE � fun��o da biblioteca
	file = fopen(arquivo, "w");  //vai criar um arquivo com o nome do arquivo (arquivo=cpf), e vai usar o "w" para tamb�m escrever o cpf dentro deste arquivo
	fprintf(file,cpf); //fprintf � para o file armazenar o que ser� escrito, neste caso o cpf
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //o "a" � para alterar o arquivo que j� foi criado no passo anterior
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
	
	printf("Voc� selecionou a op��o Pesquisar nomes\nPor favor digite o CPF do usu�rio que deseja pesquisar: \n");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo. CPF n�o localizado!");
	}
	
	while (fgets(conteudo, 200, file) != NULL);
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[20];
	
	printf("Voce selecionou a op��o Deletar nomes\nPor favor digite o CPF do usu�rio que deseja deletar: \n");
	scanf("%s",cpf);

	remove(cpf);	

	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema\n");
	}

	system("pause");
}

int main() //func�o principal
{
	int opcao=0; //vari�vel para as op��es do menu (1 "=" � para setar o valor da op��o em zero, para que a op��o n�o fique com valor vari�vel de mem�ria)
	int laco=1; //vari�vel para a repeti��o do menu ap�s selecionar a op��o desejada
	char senhadigitada [10]="a";
	int comparacao;
	
	printf("~~~ Cart�rio da EBAC ~~~\n");
	printf("Login de administrador\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		for(laco=1;laco=1;) //repeti��o das op��es do menu
		{
		
			system ("cls"); //system = "falar com o sistema operacional (n�o mostra os menus anteriores at� o usuario terminar a op��o atual)
		
			setlocale(LC_ALL, "Portuguese"); //setar a lingua portuguesa
		
			printf("~~~ Cart�rio da EBAC ~~~\n\n"); //printf = mostrar para o usu�rio o texto que est� dentro das aspas
			printf("Por favor, selecione uma das op��es a seguir\n\n");
			printf("\t1-Incluir usu�rio\n");
			printf("\t2-Pesquisar usu�rio\n");
			printf("\t3-Deletar usu�rio\n\n\n");
			printf("\t4-Sair do sistema\n\n");
			printf("Op��o desejada: ");
		
			scanf("%d", &opcao); // escaneia o valor que o usu�rio coloca (%d � para armazenar o valor de n� inteiro e o &op��o � onde ser� armazenado)
		
			system ("cls"); //system = "falar com o sistema operacional (n�o mostra os menus anteriores at� o usuario terminar a op��o atual)
		
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
				printf("Esta op��o n�o existe, por favor escolha uma op��o v�lida\n");
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

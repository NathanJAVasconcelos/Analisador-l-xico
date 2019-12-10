/*
 * ANALISADOR L�XICO
 
 * DATA: 10/12/2019
 * AUTOR: Nathan James Arrais Vasconcelos
 * DISCIPLINA: Teoria da computa��o e compiladores
 * DESCRI��O: Criar um programa em �C� ou em �C++�, que ser� um analisador l�xico, para a linguagem chamada 
 * �Minha Linguagem Normal�, este analisador deve ser constru�do com algumas das t�cnicas vistas em laborat�rio, isso 
 * inclui usar AFD, M�quina de Turing, AFD de Pilha com M�quina de Turing.
 * T�cnica utilizada:  AFD (Aut�mato Finito Determin�stico), para entrada de palavras. Para verifica��o l�xica utilizei 
 * um sistema simples com la�os de repeti��o, estruturas condicionais e algumas manipula��es com vetores de strings. Sendo 
 * esperado na sa�da, a exibi��o das palavras que possuem o alfabeto v�lido, gera��o do arquivo "resultado.txt" e a tabela 
 * de palavras v�lidas e seu tipo, por exemplo: Num�rico, operador aritm�tico, operador de fechamento e operador relacionais. O arquivo resultado cont�m a descri��o dos erros, as palavras inv�lidas e os caracteres que n�o fazem parte do alfabeto.
 * IMPORTANTE: O AFD foi criado para verificar PALAVRAS e n�o CARACTERES, para que o programa desempenhe bem a sua fun��o 
 * se faz necess�rio a inclus�o de espa�os em branco, ou separadores, entre as palavras e caracteres especiais.
 * Funcionamento: Inicialmente foi criada uma matriz com as palavras v�lidas, um vetor com o alfabeto da linguagem e algumas
 * vari�veis globais, necess�rias para a fun��o chave e a main.
 * Dentro da fun��o main est�o declarados mais quatros vetores de strings, o str, o fname, os separadores e os operadores, 
 * necess�rios para a manipula��o das palavras. Al�m deles se encontram declaradas as vari�veis contadoras, necess�rias para a detec��o de erros, e as vari�veis auxiliares j e m, utilizadas como "�ndice".
 * Posteriormente utilizei a fun��o setlocale da biblioteca locale.h, visando fugir dos inc�modos erros na visualiza��o do 
 * programa. Feito isso realizei a leitura de um arquivo e logo em seguida comecei a grava��o de outro, sendo este �ltimo 
 * com o resultado do programa.
 * O c�digo realmente come�a na estrutura de repeti��o while, essa apenas desempenha sua fun��o enquanto ch=fgetc(f1) for 
 * diferente do fim de arquivo, isto s� � poss�vel devido a fun��o fgetc, que � respons�vel pela leitura do caracter presente
 * na posi��o atual do fluxo interno e assim que o faz, a posi��o atual � avan�ada para o pr�ximo caractere. Isto acontece 
 * repetidas vezes, at� que ocorra um erro ou chegue no fim do arquivo, retornando EOF e consequentemente interrompendo o 
 * while.
 * Dentro do nosso while temos outras tr�s estruturas de repeti��o for, vamos falar da primeira delas. O primeiro for � inicializado
 * com 0 e seguir�  "ativo" enquanto a vari�vel de autoincremento m for menor do que 42, mas porque 42? A resposta � simples,
 * nosso alfabeto comporta 43 caracteres e o for � inicializado com 0, logo a quantidade de vezes que precisamos percorr�-lo � igual a 43-1.
 * Dentro desta estrutura de repeti��o temos apenas um if, o mesmo � respons�vel por comparar ch com o nosso vetor alfabeto 
 * na posi��o m, caso sejam diferentes a vari�vel aux ser� incrementada, mas no que isso nos ajuda?  F�cil, com o t�rmino 
 * destas repeti��es compararemos o aux com a quantidade de caracteres comportados pelo alfabeto, caso sejam iguais um 
 * print informando o erro ser� emitido no txt e logo em seguida a nossa vari�vel aux � zerada, pronta para ser utilizada 
 * quando formos testar outro caracter.
* O segundo for conta com a vari�vel j inicializada em 0 e atuar� enquanto a mesma for menor do que 13, quer saber o motivo 
* desse n�mero? Tranquilo, � a nossa quantidade de operadores-1! Declarados no in�cio da fun��o main. Dentro do for temos 
* uma estrutura condicional que compara se o que est� atribu�do a ch � igual a algum de nossos operadores previamente declarados
* na fun��o main, se a afirmativa for verdadeira realizaremos outro teste condicional, o oposto resulta no incremento do j e
* consequentemente num novo teste condicional.
Sendo a afirmativa verdadeira, testamos se o ch � igual a algum operador relacional (=,> e <), caso seja, uma mensagem ser� 
* printada tela, logo em seguida nosso contador de operadores ser� incrementado (op++) e atribu�mos ao nosso vetor str na 
* posi��o i (str[i]) o valor de nulo (�\0�),  utilizando-o como par�metro para a chamada da fun��o chave.
* Na fun��o chave realizamos a abertura do arquivo de grava��o e logo em seguida declaramos duas vari�veis �ndices e uma 
* especial, seu nome � flag e ter� como valores 0 e 1, utilizada nas estruturas condicionais posteriormente citadas.  
* A fun��o chave tem em seu interior uma estrutura de repeti��o for que � inicializada com k=0 e s� ser� fechada quando k 
* for menor do que 10, afinal temos 11 palavras v�lidas e esse valor -1 � igual a 10. Dentro desta estrutura contamos com o 
* if, este utiliza o strcmp para comparar o vetor palavras na posi��o K com o ponteiro p. Caso a afirmativa seja verdadeira 
* uma mensagem ser� printada na tela, informando a palavra v�lida, logo em seguida o contador pc ser� incrementado 
* (utilizado para informar a quantidade de palavras v�lidas), o valor de 1 ser� atribu�do a flag e tanto a estrutura de 
* repeti��o quanto a condicional ser�o interrompidas.
* Ainda na fun��o chave temos um if que utiliza a vari�vel flag como par�metro, caso a mesma seja 0 seremos encaminhados 
* para outra estrutura condicional. Se isdigit (fun��o da biblioteca ctype.h para verificar se o caracter � um d�gito 
* decimal) for verdadeiro, emitiremos um print informando se tratar de um n�mero e incrementamos o contador. Caso contr�rio,
* faremos um teste para descobrir se o vetor p � diferente de nulo, sendo verdadeira a afirmativa, imprimimos no arquivo a 
* palavra n�o reconhecida e incrementamos o contador. No fim da fun��o atribu�mos a vari�vel i o valor de -1, pois a mesma � 
* utilizada como crit�rio para uma estrutura condicional na fun��o main.
* Voltando para a nossa fun��o main, mais especificamente para o else de nosso segundo for. Caso o mesmo seja iniciado, 
* printaremos na tela o operador aritm�tico, incrementamos a nossa vari�vel contadora de operadores, atribu�mos a matriz 
* str na posi��o i o valor de nulo (�\0�) e a realizamos a chamada da fun��o chave recebendo como par�metro str (A fun��o 
* chave j� foi explicada).
* O terceiro for dentro da estrutura while � inicializado com j igual a 0 e tem como crit�rio de parada essa mesma vari�vel 
* ter valor menos do que 13 (qtd de separadores-1). No seu interior tem uma estrutura condicional que quebra o la�o caso i 
* seja igual a -1, essa vari�vel recebe o valor -1 sempre que passa pela fun��o chave. Logo em seguida realiza uma nova 
* compara��o, caso ch seja igual a eps na posi��o j uma sequ�ncia de ifs ser� testada, visando encontrar um operador de 
* fechamento (){}� em dado momento � atribu�do ao vetor str na posi��o i o valor �\0� e a fun��o chave � chamada.
* Ainda dentro do while, testamos se o i � diferente de -1, caso a afirmativa seja verdadeira � atribu�do ao vetor str na 
* posi��o i o valor �\0� e a fun��o chave � chamada. Caso contr�rio ser� atribu�do 0 ao valor de i e o while seguir� enquanto
* (ch=fgetc(f1))!=EOF.
* Fora do while temos apenas os comandos que imprimem erros no arquivo (Ap�s realizar um teste com os contadores) e o 
* fechamento do arquivo de leitura e grava��o.
*/

#include<stdio.h> //entrada e saida
#include<ctype.h> //ctype para uso do isdigit
#include<string.h> // manipulacao de strings
#include <stdlib.h> //exit
#include<locale.h> // pt-br
void chave(char *p);
int i=0, id=0, pc=0, num=0, op=0;
char palavras[11][10]={"for","step","sqrt","if","else","return",
"print","read","to","num","string"};
char alfabeto[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
'r', 's', 't', 'u', 'v', 'x', 'y', 'z', '=', '>', '<', '(', ')', '{', '}', '+', '-', '%', ',', ';', '"', '[', ']','/',':'};
main()
{
	char ch,str[25],seps[14]=" \t\n,;(){}[]\"<>",oper[]="%*-+=<>/";
	int j, m, countaspas=0, countchave_a=0, countchave_f=0, countparen_a=0, countparen_f=0, erro=0, aux=0;
	char fname[50];
	setlocale(LC_ALL,"Portuguese_Brazil");
	FILE *f1;
    printf("Informe o caminho do arquivo:\n");
    scanf("%s",fname);
    f1 = fopen(fname,"r");
	if(f1==NULL){
	 printf("O arquivo n�o foi encontrado");
	 exit(0);
	}
	FILE *f2;
    f2 = fopen("resultado.txt", "a");
    fprintf(f2, "\n%s", "Arquivo ");
    fprintf(f2, " %s", fname);
    fprintf(f2, " %s", "analisado.");
    fprintf(f2, "\n%s", "Sa�da:");
    printf("Palavras e operadores reconhecidos: \n");
	while((ch=fgetc(f1))!=EOF){
	  for(m=0;m<42;m++){
	  		 if ((ch!=alfabeto[m]) && (ch!=' ')){
	  		 	aux++;
			   }
	  }
	  if(aux==42) {
	  	 fprintf(f2, "\n%s", "O caracter ");
         fprintf(f2, "\t%c\t", ch);
         fprintf(f2, "\t%s", " n�o faz parte do alfabeto!");
	  	 aux=0;
	  }
      for(j=0;j<=13;j++){
        if(ch==oper[j]){
	         if(ch=='='||ch=='>'||ch=='<'){ 
	         printf("%c � um operador relacional\n",ch);
             op++;
             str[i]='\0';
             chave(str);
	         }
	         else{ 
	         printf("%c � um operador aritm�tico\n",ch);
             op++;
             str[i]='\0';
             chave(str);
	         }
         }
     }
     for(j=0;j<=13;j++){
        if(i==-1) break;
        if(ch==seps[j]){
        if(ch=='{'){
        	printf("%c � um operador de fechamento\n",ch);
        	countchave_a++;
		} 
        if(ch=='}'){
        	printf("%c � um operador de fechamento\n",ch);
        	countchave_f++;
		} 
        if(ch=='(') {
        	printf("%c � um operador de fechamento\n",ch);
        	countparen_a++;
		}
        str[i]='\0';
        chave(str);
		if(ch=='"') {
        	printf("%c � um operador de fechamento\n",ch);
        	countaspas++;
		}
		if(ch==')'){
        	printf("%c � um operador de fechamento\n",ch);
        	countparen_f++;
		} 
        }
     }
     if(i!=-1){
      str[i]=ch;
      i++;
     }
     else i=0;
    }
    printf("Palavras: %d\nPalavras n�o reconhecidas: %d\nOperadores: %d\nN�meros: %d\n",pc,id,op,num);
    if(countchave_a!=countchave_f || countparen_a!=countparen_f || countaspas%2!=0){
    	fprintf(f2, "\n%s", "O arquivo ");
        fprintf(f2, "%s", fname);
        fprintf(f2, "%s", " apresenta falta de fechamento de c�digo!!!");
    	erro++;
	} 
    if(erro=0) {
	    fprintf(f2, "\n%s", "O arquivo ");
        fprintf(f2, "%s", fname);
        fprintf(f2, "%s", " foi analisado corretamente!!!");}
    else{
    	fprintf(f2, "\n%s", "O arquivo ");
        fprintf(f2, "%s", fname);
        fprintf(f2, "%s", " cont�m erros!!!");
	}
    fclose(f1);
    fclose(f2);
    }
    
void chave(char *p)
{
FILE *f2;
f2 = fopen("resultado.txt", "a");
     if(f2 == NULL){
     printf("Erro na abertura do arquivo!");
     exit(0);
     }
int k,flag=0, l=0;
for(k=0;k<=10;k++){
     if(strcmp(palavras[k],p)==0){
     printf("%s � uma palavra v�lida\n",p);
     pc++;
     flag=1;
     break;
     }
}
if(flag==0){
	//isdigit - verifica se o caracter � decimal
     if(isdigit(p[0])){
     printf("%s � um n�mero\n",p);
     num++;
     }
     else{
     if(p[0]!='\0'){
     fprintf(f2, "\n%s", "A palavra");
     fprintf(f2, "\t%s\t", p);
     fprintf(f2, "\t%s", "n�o foi reconhecida");
     id++;
     }
     }
}
i=-1;
}

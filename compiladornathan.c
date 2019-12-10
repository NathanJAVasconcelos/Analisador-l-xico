/*
 * ANALISADOR LÉXICO
 
 * DATA: 10/12/2019
 * AUTOR: Nathan James Arrais Vasconcelos
 * DISCIPLINA: Teoria da computação e compiladores
 * DESCRIÇÃO: Criar um programa em “C” ou em “C++”, que será um analisador léxico, para a linguagem chamada 
 * “Minha Linguagem Normal”, este analisador deve ser construído com algumas das técnicas vistas em laboratório, isso 
 * inclui usar AFD, Máquina de Turing, AFD de Pilha com Máquina de Turing.
 * Técnica utilizada:  AFD (Autômato Finito Determinístico), para entrada de palavras. Para verificação léxica utilizei 
 * um sistema simples com laços de repetição, estruturas condicionais e algumas manipulações com vetores de strings. Sendo 
 * esperado na saída, a exibição das palavras que possuem o alfabeto válido, geração do arquivo "resultado.txt" e a tabela 
 * de palavras válidas e seu tipo, por exemplo: Numérico, operador aritmético, operador de fechamento e operador relacionais. O arquivo resultado contém a descrição dos erros, as palavras inválidas e os caracteres que não fazem parte do alfabeto.
 * IMPORTANTE: O AFD foi criado para verificar PALAVRAS e não CARACTERES, para que o programa desempenhe bem a sua função 
 * se faz necessário a inclusão de espaços em branco, ou separadores, entre as palavras e caracteres especiais.
 * Funcionamento: Inicialmente foi criada uma matriz com as palavras válidas, um vetor com o alfabeto da linguagem e algumas
 * variáveis globais, necessárias para a função chave e a main.
 * Dentro da função main estão declarados mais quatros vetores de strings, o str, o fname, os separadores e os operadores, 
 * necessários para a manipulação das palavras. Além deles se encontram declaradas as variáveis contadoras, necessárias para a detecção de erros, e as variáveis auxiliares j e m, utilizadas como "índice".
 * Posteriormente utilizei a função setlocale da biblioteca locale.h, visando fugir dos incômodos erros na visualização do 
 * programa. Feito isso realizei a leitura de um arquivo e logo em seguida comecei a gravação de outro, sendo este último 
 * com o resultado do programa.
 * O código realmente começa na estrutura de repetição while, essa apenas desempenha sua função enquanto ch=fgetc(f1) for 
 * diferente do fim de arquivo, isto só é possível devido a função fgetc, que é responsável pela leitura do caracter presente
 * na posição atual do fluxo interno e assim que o faz, a posição atual é avançada para o próximo caractere. Isto acontece 
 * repetidas vezes, até que ocorra um erro ou chegue no fim do arquivo, retornando EOF e consequentemente interrompendo o 
 * while.
 * Dentro do nosso while temos outras três estruturas de repetição for, vamos falar da primeira delas. O primeiro for é inicializado
 * com 0 e seguirá  "ativo" enquanto a variável de autoincremento m for menor do que 42, mas porque 42? A resposta é simples,
 * nosso alfabeto comporta 43 caracteres e o for é inicializado com 0, logo a quantidade de vezes que precisamos percorrê-lo é igual a 43-1.
 * Dentro desta estrutura de repetição temos apenas um if, o mesmo é responsável por comparar ch com o nosso vetor alfabeto 
 * na posição m, caso sejam diferentes a variável aux será incrementada, mas no que isso nos ajuda?  Fácil, com o término 
 * destas repetições compararemos o aux com a quantidade de caracteres comportados pelo alfabeto, caso sejam iguais um 
 * print informando o erro será emitido no txt e logo em seguida a nossa variável aux é zerada, pronta para ser utilizada 
 * quando formos testar outro caracter.
* O segundo for conta com a variável j inicializada em 0 e atuará enquanto a mesma for menor do que 13, quer saber o motivo 
* desse número? Tranquilo, é a nossa quantidade de operadores-1! Declarados no início da função main. Dentro do for temos 
* uma estrutura condicional que compara se o que está atribuído a ch é igual a algum de nossos operadores previamente declarados
* na função main, se a afirmativa for verdadeira realizaremos outro teste condicional, o oposto resulta no incremento do j e
* consequentemente num novo teste condicional.
Sendo a afirmativa verdadeira, testamos se o ch é igual a algum operador relacional (=,> e <), caso seja, uma mensagem será 
* printada tela, logo em seguida nosso contador de operadores será incrementado (op++) e atribuímos ao nosso vetor str na 
* posição i (str[i]) o valor de nulo (‘\0’),  utilizando-o como parâmetro para a chamada da função chave.
* Na função chave realizamos a abertura do arquivo de gravação e logo em seguida declaramos duas variáveis índices e uma 
* especial, seu nome é flag e terá como valores 0 e 1, utilizada nas estruturas condicionais posteriormente citadas.  
* A função chave tem em seu interior uma estrutura de repetição for que é inicializada com k=0 e só será fechada quando k 
* for menor do que 10, afinal temos 11 palavras válidas e esse valor -1 é igual a 10. Dentro desta estrutura contamos com o 
* if, este utiliza o strcmp para comparar o vetor palavras na posição K com o ponteiro p. Caso a afirmativa seja verdadeira 
* uma mensagem será printada na tela, informando a palavra válida, logo em seguida o contador pc será incrementado 
* (utilizado para informar a quantidade de palavras válidas), o valor de 1 será atribuído a flag e tanto a estrutura de 
* repetição quanto a condicional serão interrompidas.
* Ainda na função chave temos um if que utiliza a variável flag como parâmetro, caso a mesma seja 0 seremos encaminhados 
* para outra estrutura condicional. Se isdigit (função da biblioteca ctype.h para verificar se o caracter é um dígito 
* decimal) for verdadeiro, emitiremos um print informando se tratar de um número e incrementamos o contador. Caso contrário,
* faremos um teste para descobrir se o vetor p é diferente de nulo, sendo verdadeira a afirmativa, imprimimos no arquivo a 
* palavra não reconhecida e incrementamos o contador. No fim da função atribuímos a variável i o valor de -1, pois a mesma é 
* utilizada como critério para uma estrutura condicional na função main.
* Voltando para a nossa função main, mais especificamente para o else de nosso segundo for. Caso o mesmo seja iniciado, 
* printaremos na tela o operador aritmético, incrementamos a nossa variável contadora de operadores, atribuímos a matriz 
* str na posição i o valor de nulo (‘\0’) e a realizamos a chamada da função chave recebendo como parâmetro str (A função 
* chave já foi explicada).
* O terceiro for dentro da estrutura while é inicializado com j igual a 0 e tem como critério de parada essa mesma variável 
* ter valor menos do que 13 (qtd de separadores-1). No seu interior tem uma estrutura condicional que quebra o laço caso i 
* seja igual a -1, essa variável recebe o valor -1 sempre que passa pela função chave. Logo em seguida realiza uma nova 
* comparação, caso ch seja igual a eps na posição j uma sequência de ifs será testada, visando encontrar um operador de 
* fechamento (){}” em dado momento é atribuído ao vetor str na posição i o valor ‘\0’ e a função chave é chamada.
* Ainda dentro do while, testamos se o i é diferente de -1, caso a afirmativa seja verdadeira é atribuído ao vetor str na 
* posição i o valor ‘\0’ e a função chave é chamada. Caso contrário será atribuído 0 ao valor de i e o while seguirá enquanto
* (ch=fgetc(f1))!=EOF.
* Fora do while temos apenas os comandos que imprimem erros no arquivo (Após realizar um teste com os contadores) e o 
* fechamento do arquivo de leitura e gravação.
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
	 printf("O arquivo não foi encontrado");
	 exit(0);
	}
	FILE *f2;
    f2 = fopen("resultado.txt", "a");
    fprintf(f2, "\n%s", "Arquivo ");
    fprintf(f2, " %s", fname);
    fprintf(f2, " %s", "analisado.");
    fprintf(f2, "\n%s", "Saída:");
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
         fprintf(f2, "\t%s", " não faz parte do alfabeto!");
	  	 aux=0;
	  }
      for(j=0;j<=13;j++){
        if(ch==oper[j]){
	         if(ch=='='||ch=='>'||ch=='<'){ 
	         printf("%c é um operador relacional\n",ch);
             op++;
             str[i]='\0';
             chave(str);
	         }
	         else{ 
	         printf("%c é um operador aritmético\n",ch);
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
        	printf("%c é um operador de fechamento\n",ch);
        	countchave_a++;
		} 
        if(ch=='}'){
        	printf("%c é um operador de fechamento\n",ch);
        	countchave_f++;
		} 
        if(ch=='(') {
        	printf("%c é um operador de fechamento\n",ch);
        	countparen_a++;
		}
        str[i]='\0';
        chave(str);
		if(ch=='"') {
        	printf("%c é um operador de fechamento\n",ch);
        	countaspas++;
		}
		if(ch==')'){
        	printf("%c é um operador de fechamento\n",ch);
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
    printf("Palavras: %d\nPalavras não reconhecidas: %d\nOperadores: %d\nNúmeros: %d\n",pc,id,op,num);
    if(countchave_a!=countchave_f || countparen_a!=countparen_f || countaspas%2!=0){
    	fprintf(f2, "\n%s", "O arquivo ");
        fprintf(f2, "%s", fname);
        fprintf(f2, "%s", " apresenta falta de fechamento de código!!!");
    	erro++;
	} 
    if(erro=0) {
	    fprintf(f2, "\n%s", "O arquivo ");
        fprintf(f2, "%s", fname);
        fprintf(f2, "%s", " foi analisado corretamente!!!");}
    else{
    	fprintf(f2, "\n%s", "O arquivo ");
        fprintf(f2, "%s", fname);
        fprintf(f2, "%s", " contém erros!!!");
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
     printf("%s é uma palavra válida\n",p);
     pc++;
     flag=1;
     break;
     }
}
if(flag==0){
	//isdigit - verifica se o caracter é decimal
     if(isdigit(p[0])){
     printf("%s é um número\n",p);
     num++;
     }
     else{
     if(p[0]!='\0'){
     fprintf(f2, "\n%s", "A palavra");
     fprintf(f2, "\t%s\t", p);
     fprintf(f2, "\t%s", "não foi reconhecida");
     id++;
     }
     }
}
i=-1;
}

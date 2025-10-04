#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AMARELO  "\033[33m"
#define AZUL    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define VERDE   "\033[32m"
#define RESET   "\033[0m"

#define MAX 100


// Estrutura
struct Musica{
	int id;
	int status;
	char titulo[MAX];
	char artista[MAX];
	char genero[MAX];
	int ano_lancamento;
};

//(apelidar)
typedef struct Musica TMusica;

// Funções: Menu, Cadastrar, Visualizar, Pesquisar, Alterar, Remover e (Ordenar por Ano)

void menu () {
	
	
	printf("\n");
	printf("==================================\n");
	printf("==== Gerenciador de Playlist ====\n");
	printf("1 - Adicionar Musica a Playlist\n");
	printf("2 - Exibir Playlist\n");
	printf("3 - Buscar Musica por Titulo\n");
	printf("4 - Editar Musica\n");
	printf("5 - (Ordenar Playlist por Ano)\n");
	printf("6 - Excluir Musica\n");
	printf("7 - Sair\n");
	printf("==================================\n");

}

void adicionar (TMusica vetor[], int posicao) { // posição: utiliza a posi. do array para cadastrar
	
		
	vetor[posicao].id = posicao;
	vetor[posicao].status = 1;
	
	printf(AMARELO"\nDigite o Titulo da musica: \n"RESET);
	fgets(vetor[posicao].titulo, MAX-1, stdin);
 
 	printf(AMARELO"\nNome do Artista: \n"RESET);
 	fgets(vetor[posicao].artista, MAX-1, stdin);
 	
 	printf(AMARELO"\nQual genero da musica: \n"RESET);
 	fgets(vetor[posicao].genero, MAX-1, stdin);
 	
 	printf(AMARELO"\nQual o ano de lancamento: \n"RESET);
 	scanf("%d", &vetor[posicao].ano_lancamento);
}
 
void exibir (TMusica vetor[], int n) { // n: indica o tamanho do array
	
	int i;
	
	printf(AMARELO"\n----------------------------------"RESET);
	printf(AMARELO"\n        PLAYLIST ATUAL            "RESET);
	printf(AMARELO"\n----------------------------------\n"RESET);
	
	for(i=0; i<n; i++){
		
		if(vetor[i].status == 1){
			
			printf(AMARELO"Id: %d\n"RESET, vetor[i].id);
			printf(AMARELO"Musica: %s"RESET, vetor[i].titulo);
			printf(AMARELO"Artista: %s"RESET, vetor[i].artista);
			printf(AMARELO"Genero: %s"RESET, vetor[i].genero);
			printf(AMARELO"Ano: %d"RESET, vetor[i].ano_lancamento);
		}
		printf(AMARELO"\n----------------------------------\n"RESET);
	}
}
 
void buscar (TMusica vetor[], int n) {
	
	int i;
	char titulo[MAX];
	int encontrou = 0;
	
	printf(AMARELO"\n----------------------------------\n"RESET);
	printf(AMARELO"          BUSCA DE MUSICA             "RESET);
	printf(AMARELO"\n----------------------------------\n"RESET);
	printf(AMARELO"Entre com o titulo:");
	fgets(titulo, MAX-1, stdin);
		
	for(i=0; i<n; i++){
		
		if(vetor[i].status == 1 && strcmp(vetor[i].titulo, titulo) == 0){
			printf(AMARELO"----------------------------------\n"RESET);
			printf(AMARELO"Id: %d\n"RESET, vetor[i].id);
			printf(AMARELO"Titulo: %s"RESET, vetor[i].titulo);
			printf(AMARELO"Artista: %s"RESET, vetor[i].artista);
			printf(AMARELO"Genero: %s"RESET, vetor[i].genero);
			printf(AMARELO"----------------------------------\n"RESET);
			encontrou = 1;
		}
	}
	
	if(!encontrou){
		printf(AMARELO"----------------------------------\n"RESET);
		printf(AMARELO"Musica nao encontrada!\n"RESET);
		printf(AMARELO"----------------------------------\n"RESET);
	}
}

void editar (TMusica vetor[], int n) {
	
	int id_alterar;
	int encontrou = 0;
	int opcao;
	int i;
	
	printf(AMARELO"\n----------------------------------\n"RESET);
	printf(AMARELO"          EDITAR MUSICA               "RESET);
	printf(AMARELO"\n----------------------------------\n"RESET);
	printf(AMARELO"Digite o ID da musica para alterar:"RESET);
	scanf("%d", &id_alterar);
	getchar(); // limpa o buffer
	
	for(i = 0; i < n; i++) {
		
		if(vetor[i].status == 1 && vetor[i].id == id_alterar){
			
			encontrou = 1;
			
			printf(AMARELO"Musica encontrada!\n"RESET);
			printf(AMARELO"----------------------------------\n"RESET);
			printf(AMARELO"Id: %d\n"RESET, vetor[i].id);
			printf(AMARELO"Status: %d\n"RESET, vetor[i].status);
			printf(AMARELO"Titulo: %s"RESET, vetor[i].titulo);
			printf(AMARELO"Artista: %s"RESET, vetor[i].artista);
			printf(AMARELO"Genero: %s"RESET, vetor[i].genero);
			printf(AMARELO"Ano: %d"RESET, vetor[i].ano_lancamento);
			printf(AMARELO"\n----------------------------------\n"RESET);
		}
		
		do {
			
			printf(AMARELO"O que deseja alterar?\n"RESET);
			printf(AMARELO"\n1 - Titulo\n"RESET);
			printf(AMARELO"2 - Artista\n"RESET);
			printf(AMARELO"3 - Genero\n"RESET);
			printf(AMARELO"4 - Ano de Lancamento\n"RESET);
			printf(AMARELO"5 - Voltar ao menu\n"RESET);
			printf(AMARELO"----------------------------------\n"RESET);
			printf(AMARELO"\nDigite opcao: "RESET);
			scanf("%d", &opcao);
			getchar();
			printf(AMARELO"\n----------------------------------"RESET);
			
			switch(opcao){
				case 1:
					printf(AMARELO"\nNovo titulo: "RESET);
					fgets(vetor[i].titulo, MAX-1, stdin);
					printf(AMARELO"\nTitulo alterado!"RESET);
					break;
				
				case 2:
					printf(AMARELO"\nNovo nome: "RESET);
					fgets(vetor[i].artista, MAX-1, stdin);
					printf(AMARELO"\nNome alterado!"RESET);
					break;
					
				case 3:
					printf(AMARELO"\nNovo genero: "RESET);
					fgets(vetor[i].genero, MAX-1, stdin);
					printf(AMARELO"\nGenero alterado!"RESET);
					break;
					
				case 4:
					printf(AMARELO"\nNovo ano de lancamento: "RESET);
					scanf("%d", &vetor[i].ano_lancamento);
					printf(AMARELO"\nAno alterado!"RESET);
					break;
					
				case 5 :
					printf(AMARELO"\nAlteracoes Salvas!"RESET);
					break;
					
				default:
					printf(AMARELO"\nOpcao invalida!\n"RESET);
			}
			
		} while(opcao != 5);
		
		break;	
		
	} // fechamento do for
	
	if(!encontrou) {
		printf(AMARELO"\nMusica com Id %d nao encontrada!\n"RESET, id_alterar);
	}
	
	
}
 
void excluir (TMusica vetor[], int n){
	
	int id;
	
	printf(AMARELO"\n----------------------------------"RESET);
	printf(AMARELO"\n        EXCLUIR MUSICA            "RESET);
	printf(AMARELO"\n----------------------------------\n"RESET);
	printf(AMARELO"Entre com id:"RESET);
	scanf("%d", &id);
	printf(AMARELO"----------------------------------\n"RESET);
	
	if(id < 0 || id >= n){
		printf(AMARELO"Id invalido!\n"RESET);
		printf(AMARELO"----------------------------------\n"RESET);
		return;
	}
	
	if(vetor[id].status == 1){
		vetor[id].status = 0;
		printf(AMARELO"Cadastro removido\n"RESET);
		printf(AMARELO"----------------------------------\n"RESET);
	}
}
 
void ord_crescente(TMusica vetor[], int n){
	
	int i,j; 
	TMusica temp;
	
		
	for(i = 0; i < n - 1; i++){ // evita uma passada extra
		for(j = 0; j < n - i - 1; j++){ // compara vizinhos se precisa ainda ser trocado
			
			if(vetor[j].status == 1 && vetor[j+1].status == 1){ //eleento atual && vizinho
				
				if(vetor[j].ano_lancamento > vetor[j+1].ano_lancamento){ // Se vizinhos forem iguais, vai comparar ano lançam
					temp = vetor[j];
					vetor[j] = vetor[j+1];
					vetor[j+1] = temp;
				}
			}
			
		}
	}
	
	printf(AMARELO"\n%-6s | %s\n", "ANO", "TITULO"RESET);
    printf(AMARELO"-----------------------------\n"RESET);
    for(i = 0; i < n; i++){
        if(vetor[i].status == 1){  // só imprime os ativos
            printf(AMARELO"%-6d | %s\n"RESET, vetor[i].ano_lancamento, vetor[i].titulo);
        }
	}
	
} 
 
 int main () {
 	

 	// Ponteiro para alocação dinâmica de memória
 	TMusica *vetor;
 	int n, opcao;
 	n = 0;
	
	do{
		
		menu();
		
		printf("\nEntre com uma opcao:");
		scanf("%d", &opcao);
		getchar();
		
		switch(opcao){
			
			case 1:
					n++;
					
					if (n == 1){ 
						vetor = (TMusica*) malloc(sizeof(TMusica));
					}
					else{
						vetor = (TMusica*) realloc(vetor, n*sizeof(TMusica));
					}
					
					adicionar(vetor, n-1);
					
					printf("\nCadastro realizado com sucesso\n");
					break;
					
			case 2:
					exibir(vetor, n);
					break;
					
			case 3:
					buscar(vetor, n);
					break;
			
			case 4:
					editar(vetor, n);
					break;
					
			case 5:					
					ord_crescente(vetor, n);
					break;
					
			case 6:
					excluir(vetor, n);
					break;
					
			case 7:
					break;
					
			case 8:
					printf("Opcao invalida!\n");
					break;
		}
		
	} while(opcao != 7);
	
 }

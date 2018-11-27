#include <stdio.h>
#include <stdlib.h>

struct campo{int **campo, **marca;} c;

void expansao(int L, int C, int lin, int col){
	int i, j, fim;
	c.marca[lin][col]=1;
	i=lin; j=col;
	if(i>=0 && i<L && j>=0 && j<C-1){
		j++;
		if(c.campo[i][j]==0 && c.marca[i][j]!=1)
			expansao(L, C, i, j);
		else
			c.marca[i][j]=1;
	}
	i=lin; j=col;	
	if(i>=0 && i<L && j>0 && j<C){
		j--;
		if(c.campo[i][j]==0 && c.marca[i][j]!=1)
			expansao(L, C, i, j);
		else
			c.marca[i][j]=1;
	}
	i=lin; j=col;
	if(i>=0 && i<L-1 && j>=0 && j<C){
		i++;
		if(c.campo[i][j]==0 && c.marca[i][j]!=1)
			expansao(L, C, i, j);
		else
			c.marca[i][j]=1;
	}
	i=lin; j=col;
	if(i>0 && i<L && j>=0 && j<C){
		i--;
		if(c.campo[i][j]==0 && c.marca[i][j]!=1)
			expansao(L, C, i, j);
		else
			c.marca[i][j]=1;
	}
	i=lin; j=col;
	if(i>=0 && i<L-1 && j>=0 && j<C-1){
		i++; j++;
		if(c.campo[i][j]==0 && c.marca[i][j]!=1)
			expansao(L, C, i, j);
		else
			c.marca[i][j]=1;
	}
	i=lin; j=col;
	if(i>=0 && i<L-1 && j>0 && j<C){
		i++; j--;
		if(c.campo[i][j]==0 && c.marca[i][j]!=1)
			expansao(L, C, i, j);
		else
			c.marca[i][j]=1;
	}
	i=lin; j=col;
	if(i>0 && i<L && j>=0 && j<C-1){
		i--; j++;
		if(c.campo[i][j]==0 && c.marca[i][j]!=1)
			expansao(L, C, i, j);
		else
			c.marca[i][j]=1;
	}
	i=lin; j=col;
	if(i>0 && i<L && j>0 && j<C){
		i--; j--;
		if(c.campo[i][j]==0 && c.marca[i][j]!=1)
			expansao(L, C, i, j);
		else
			c.marca[i][j]=1;
	}
	return;
}

void printar(int L, int C){
	int i, j, k;
	printf("\n\n");
	for(i=0; i<L; i++){
		if(i==0){
			printf("   ");
			for(k=0; k<C; k++){
				if(k<9)
					printf(" %d   ", k+1);
				else
					printf("%d   ", k+1);
			}
			printf("\n\n");
		}
		for(j=0; j<C; j++){
			if(j==0){
				if(i<9)
					printf(" %d  ", i+1);
				else
					printf("%d  ", i+1);
			}
			if(c.marca[i][j]==0)
				printf("%c    ", 177);
			else if(c.marca[i][j]==1){
				if(c.campo[i][j]==666)
					printf("*    ");
				else
					printf("%d    ", c.campo[i][j]);
			}
			else if(c.marca[i][j]==2)
				printf("%c    ", 66);
			else
				printf("%c    ", 63);
		}
		printf("\n\n");
	}
	printf("\n\n");
	return;
}

int playar(int L, int C, int M){
	int i, j, lin, col, k, move;
	char lixo;
	while(1){
		k=0;
		for(i=0; i<L; i++)
			for(j=0; j<C; j++)
				if(c.marca[i][j]==1)
					k++;
		if(k==(L*C)-M){
			printf("\n\n  OLOKO, O CARA EH BOM!\n\n");
			for(i=0; i<L; i++)
				for(j=0; j<C; j++)
					c.marca[i][j]=1;
			printar(L, C);
			printf("\nCongratulations!!!\n\n");
			printf("Voce desejar jogar novamente?\n"
				    "1 - Sim\n"
				    "2 - Nao\n");
			while(1){
				scanf("%d", &move);
				if(move>0 && move<3){
					if(move==1)
						return main();
					else{
						printf("\nObrigado por jogar =)\n");
						return;
					}	
				}
			}
		}
		printf("1 - Jogar\n"
			   "2 - Marcar Bandeira\n"
	    	   "3 - Marcar Interrogacao\n"
			   "4 - Remover Bandeira ou Interrogacao\n"
		       "5 - Para sair do jogo\n"
		   	   "Digite sua jogada: ");
		move=0;
		while(1){
			scanf("%d", &move);
			if(move>0 && move<6)
				break;
			else
				scanf("%c", &lixo);
		}
		if(move==5){
			printf("\n\n");
			for(i=0; i<L; i++)
				for(j=0; j<C; j++)
					c.marca[i][j]=1;
			printar(L, C);
			printf("Obrigado por jogar =)\n\n");
			return;
		}
		printf("Digite a linha: ");
		lin=0;
		while(1){
			scanf("%d", &lin);
			if(lin>0 && lin<=L)
				break;
			else
				scanf("%c", &lixo);
		}
		printf("Digite a coluna: ");
		col=0;
		while(1){
			scanf("%d", &col);
			if(col>0 && col<=C)
				break;
			else
				scanf("%c", &lixo);
		}
		lin--; col--;
		switch (move){
			case 1:
				if(c.campo[lin][col]==0)
					expansao(L, C, lin, col);
				else if(c.campo[lin][col]==666){
					for(i=0; i<L; i++)
						for(j=0; j<C; j++)
							c.marca[i][j]=1;
					printar(L, C);
					printf("  Que pena meu caro jogador, voce perdeu\n\n");
					printf("Voce desejar jogar novamente?\n"
				  		   "1 - Sim\n"
				   		   "2 - Nao\n");
					while(1){
						scanf("%d", &move);
						if(move>0 && move<3){
							if(move==1)
								return main();
							else{
								printf("Obrigado por jogar =)\n");
								return;
							}	
						}
						else
							scanf("%c", &lixo);
					}
				}
				else{
					c.marca[lin][col]=1;
					k=0;
					for(i=0; i<L; i++)
						for(j=0; j<C; j++)
							if(c.marca[i][j]==1)
								k++;
					if(k==(L*C)-M){
						printf("\n\n  OLOKO, O CARA EH BOM!\n\n");
						for(i=0; i<L; i++)
							for(j=0; j<C; j++)
								c.marca[i][j]=1;
						printar(L, C);
						printf("\nCongratulations!!!\n\n");
						printf("Voce desejar jogar novamente?\n"
							    "1 - Sim\n"
							    "2 - Nao\n");
						while(1){
							scanf("%d", &move);
							if(move>0 && move<3){
								if(move==1)
									return main();
								else{
									printf("\nObrigado por jogar =)\n");
									return;
								}	
							}
						}
					}
				}
				printar(L, C);
				break;
			case 2:
				if(c.marca[lin][col]!=1)
					c.marca[lin][col]=2;
				printar(L, C);
				break;
			case 3:
				if(c.marca[lin][col]!=1)
					c.marca[lin][col]=3;
				printar(L, C);
				break;
			case 4:
				if(c.marca[lin][col]!=1)
					c.marca[lin][col]=0;
				printar(L, C);
				break;
		}
	}
	return;
}

void minar(int L, int C, int M){
	int i, j, k, ii, jj;
	srand((unsigned)time(NULL));
	c.campo=(int **) calloc(L, sizeof(int *));
	c.marca=(int **) calloc(L, sizeof(int *));
	for(i=0; i<L; i++){
		*(c.campo+i)= (int *) calloc(M, sizeof(int));
		*(c.marca+i)= (int *) calloc(M, sizeof(int));
	}
	for(k=0; k<M; k++){
		while(1){
			i=rand()%L;
			j=rand()%C;
			if(c.campo[i][j]==0){
				c.campo[i][j]=666;
				break;
			}
		}
	}
	for(i=0; i<L; i++)
			for(j=0; j<C; j++)
				if(c.campo[i][j]==666)
					for(ii=i-1; ii<=i+1; ii++)
						if(ii>=0 && ii<L)
							for(jj=j-1; jj<=j+1; jj++)
								if(jj>=0 && jj<C)
									if(c.campo[ii][jj]!=666)
										c.campo[ii][jj]++;
	system("cls");
	printf("Campo %dx%d, %d minas\n", L, C, M);
	printf("Boa sorte, caro jogador\n"
		   "Para uma melhor experiencia, maximize sua janela\n\n");
	printar(L, C);
	playar(L, C, M);
	return;
}

int main(void){
	int L, C, M, max, min;
	int i, k;
	char lixo;
	system("cls");
	printf("                      CAMPO MINADO v1.0\n\n\n"
			"Digite o numero de linhas e de colunas desejado para o campo\n\n");
	printf("Numero de linhas entre 5 e 99\n");
	printf("Numero de linhas: ");
	while(1){
		scanf("%d", &L);
		if(L>4 && L<100)
			break;
		else
			scanf("%c", &lixo);
	}
	printf("Numero de colunas entre 5 e 99\n");
	printf("Numero de Colunas: ");
	while(1){
		scanf("%d", &C);
		if(C>4 && C<100)
			break;
		else
			scanf("%c", &lixo);
	}
	printf("\n");
	min=(C*L)*0.2;
	max=(C*L)*0.4;
	printf("Digite o numero de minas desejado:\n");
	for(i=min, k=1; i<=max; i++, k++){
			printf("%d ", i);
			if(k%10==0)
				printf("\n");
		}
		printf("\n\n");
	while(1){
		scanf("%d", &M);
		if(M>=min && M<=max)
			break;
		else 
			scanf("%c", &lixo);
	}
	minar(L, C, M);
	getchar();
	return 0;
}

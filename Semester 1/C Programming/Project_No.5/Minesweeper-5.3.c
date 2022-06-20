#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void getValues(int *M, int *N, int *K);
char **make_board(int M, int N);
void print_board(FILE *fp, char **board, int M, int N);
void free_board (char **board, int M);
char **mines (char **board, int M, int N, int K);
void numbers (char **board, char **p, int M, int N, int K);
void bomb_check (char *p);
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
int main (int argc, char **argv)
{
	system ("chcp 1253");
	FILE *fptr;
	fptr=fopen(argv[1],"w");
	if (fptr==NULL)
	{
		printf("Σφάλμα, δεν βρέθηκε αρχείο.\n");
	}
	int M,N,K,i,j;
	char **board,**p;
	getValues(&M, &N, &K);
	board=make_board(M, N);
	p = mines(board, M, N, K);
	numbers (board, p, M, N, K);
	print_board(fptr, board, M, N);
	free_board (board, M);
	free_board (p,K);
	return 0;
}
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
void getValues(int *M, int *N, int *K)
{
	int numM,numN,numK;
	printf("Παρακαλώ εισάγετε τις διαστάσεις του πίνακα >>>\n");
	do
	{
		printf("Παρακαλώ εισάγετε το M (Αριθμός γραμμών):\n");
		scanf("%d",&numM);
		printf("Παρακαλώ εισάγετε το N (Αριθμός στηλών):\n");
		scanf("%d",&numN);
	}while (numM<0 || numN<0);
	printf("Παρακαλώ εισάγετε το K (Αριθμός ναρκών):\n");
	scanf("%d",&numK);
	system ("cls");
	*M=numM;
	*N=numN;
	*K=numK;	
}
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
char **make_board(int M, int N)
{
	int i,j;
	char **b;
	b=(char **)malloc(M*sizeof(char *));
	if (b==NULL)
	{
		printf("Σφάλμα κατά την δέσμευση της μνήμης.");
		exit(-1);
	}
	for (i=0;i<M;i++)
	{
		b[i]=(char *)calloc(N,1);
		if (b[i]==NULL)
		{
			printf("Σφάλμα κατά την δέσμευση της μνήμης.");
			exit(-1);
		}
	}
	return b;
}
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
void print_board(FILE *fp,char **board, int M, int N)
{
	int i,j;
	for (i=0;i<M;i++)
	{
		printf("%d-\t",i+1);
		fprintf(fp,"%d-\t",i+1);
		for (j=0;j<N;j++)
		{
			if(board[i][j]==9)
			{
				printf("X ");
				fprintf(fp,"X ");
			}
			else
			{
				printf("%d ",board[i][j]);
				fprintf(fp,"%d ",board[i][j]);
			}
		}
		printf("\n");
		fprintf(fp,"\n");
	}
}
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
void free_board (char **board, int M)
{
	int i,j;
	for(i=0;i<M;i++)
		free (board[i]);
	free (board);
}
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
char **mines(char **board, int M, int N, int K)
{
	int i,j,r1,r2,Flag;
	char **p;
	p=make_board(K,2);
	srand (time(NULL));
	for(i=0;i<K;i++)
	{
		Flag=0;
		do
		{
			r1=rand() % (M);
			r2=rand() % (N);
			if (board[r1][r2] != 9)
			{
				Flag=1;
			}
		}while( Flag==0 );
		p[i][0]=r1;
		p[i][1]=r2;	
		board[r1][r2]=9;
	}
	return p;
}
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
void numbers (char **board, char **p, int M, int N, int K)
{
	int i,j,l;
	M--;
	N--;
	for (l=0;l<K;l++)
	{
		i = p[l][0];
		j = p[l][1];
		if (i==0 && j==0)
		{
			bomb_check (&board[0][1]);
			bomb_check (&board[1][1]);
			bomb_check (&board[1][0]);
		}
		else if (i==0 && j==N)
		{
			bomb_check (&board[0][N-1]);
			bomb_check (&board[1][N-1]);
			bomb_check (&board[1][N]);
		}
		else if (i==M && j==0)
		{
			bomb_check (&board[M-1][0]);
			bomb_check (&board[M-1][1]);
			bomb_check (&board[M][1]);
		}
		else if (i==M && j==N)
		{
			bomb_check (&board[M-1][N]);
			bomb_check (&board[M-1][N-1]);
			bomb_check (&board[M][N-1]);
		}
		else if (i==0)
		{
			bomb_check (&board[i][j+1]);
			bomb_check (&board[i][j-1]);
			bomb_check (&board[i+1][j]);
			bomb_check (&board[i+1][j+1]);
			bomb_check (&board[i+1][j-1]);
		}
		else if (j==N)
		{
			bomb_check (&board[i-1][j]);
			bomb_check (&board[i+1][j]);
			bomb_check (&board[i-1][j-1]);
			bomb_check (&board[i][j-1]);
			bomb_check (&board[i+1][j-1]);
		}
		else if (i==M)
		{
			bomb_check (&board[i][j-1]);
			bomb_check (&board[i][j+1]);
			bomb_check (&board[i-1][j-1]);
			bomb_check (&board[i-1][j]);
			bomb_check (&board[i-1][j+1]);
		}
		else if (j==0)
		{
			bomb_check (&board[i-1][j]);
			bomb_check (&board[i+1][j]);
			bomb_check (&board[i-1][j+1]);
			bomb_check (&board[i][j+1]);
			bomb_check (&board[i+1][j+1]);
		}
		else 
		{
			bomb_check (&board[i-1][j-1]);
			bomb_check (&board[i-1][j]);
			bomb_check (&board[i-1][j+1]);
			bomb_check (&board[i+1][j-1]);
			bomb_check (&board[i+1][j]);
			bomb_check (&board[i+1][j+1]);
			bomb_check (&board[i][j-1]);
			bomb_check (&board[i][j+1]);
		}
	}
}
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
void bomb_check (char *p)
{
	if (*p != 9)
		*p=*p+1;
}

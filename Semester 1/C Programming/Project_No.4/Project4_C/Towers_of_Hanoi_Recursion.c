#include <stdio.h>
void tower(int diskoi,char Stilos1,char Stilos2,char Stilos3 );
int main ()
{
	system ("chcp 1253");
	int n;
	int x=1;
	int y=2;
	int z=3;
	printf("Δώσε μου τον αριθμό των δίσκων:  ");
	scanf("%d",&n);
	printf("\n\n");
	tower(n,x,y,z);
	
return 0;
}
void tower(int diskoi,char Stilos1,char Stilos2,char Stilos3)
{
	if (diskoi==1)
	{
		printf("Τοποθετώ έναν δίσκο από τον Στύλο %i στον Στύλο %i\n\n",Stilos1,Stilos3);
		return;
	}
	else
	{
		tower(diskoi-1,Stilos1,Stilos3,Stilos2);
		printf("\tΜετακινώ έναν δίσκο από τον Στύλο %i στον Στύλο %i\n\n",Stilos1,Stilos3);
		tower(diskoi-1,Stilos2,Stilos1,Stilos3);
	}
	
}


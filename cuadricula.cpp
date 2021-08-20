#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int fb[16][2]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,};
int cb=0;

void imprimircuadricula(int cuadricula[4][4])
{
	printf("___________________________________________\n");
	for(int k=0;k<4;k++)
	{
		
		for(int j=0;j<4;j++)
		{
			
			
			if(cuadricula[k][j] == 0)
				printf("||    ");
			else	
				printf("||  %d ",cuadricula[k][j]);
			if(cuadricula[k][j]<10)
			{

					printf("  || ");
					
					
				
			}
			else
			{
				
				
				printf(" || ");
			
			}
				
			
			
			
		}

	printf("\n");	
	}
	
	printf("___________________________________________\n");
}









bool BuscarBloq(int cuadricula[4][4],int siguiente[2])
{
	bool ban= false;

	for(int k=0;k<cb;k++)
	{
		if(siguiente[0]==fb[k][0] && siguiente[1]==fb[k][1])
		{

			ban=true;
			break;
		}

	}
	return ban;
}

void moverx(int cuadricula[4][4],int pos[2],int mov)
{
	
	int siguiente[2];
	int ban=false;

	if(pos[1] != 3 && mov == 1)
	{
		
		cuadricula[pos[0]][pos[1]] = cuadricula[pos[0]][pos[1]+1];
		cuadricula[pos[0]][pos[1]+1]= 0;
		
	}
	
	if(pos[1] != 0 && mov == 2)
	{
		
		cuadricula[pos[0]][pos[1]] = cuadricula[pos[0]][pos[1]-1];
		cuadricula[pos[0]][pos[1]-1]= 0;
	
	}
	


}

void movery(int cuadricula[4][4],int pos[2],int mov)
{
	int siguiente[2];
	int ban=false;
	
	if(pos[0] != 3 && mov == 3)
	{
		

		cuadricula[pos[0]][pos[1]] = cuadricula[pos[0]+1][pos[1]];
		cuadricula[pos[0]+1][pos[1]]= 0;
	
	}
	
	if(pos[0] != 0 && mov == 4)
	{
		
		
		cuadricula[pos[0]][pos[1]] = cuadricula[pos[0]-1][pos[1]];
		cuadricula[pos[0]-1][pos[1]]= 0;


	
	}
	


}




void buscapos(int cuadricula[4][4],int pos[2])
{
	

	for(int k=0;k<4;k++)
	{
		for(int j=0;j<4;j++)
		{
			
			if(cuadricula[k][j]==0)
			{
				pos[0]=k;
				pos[1]=j;
				break;
			}

		}	
		
	}
	


	
}


void shuffle(int cuadricula[4][4],int pos[2])
{

	for(int k=0;k<1000;k++)
	{
		
		
		int ran = rand()%2;
		if(ran==0)
		{
			ran = 1+rand()%2;
			buscapos(cuadricula,pos);
			moverx(cuadricula,pos,ran);

		}else 
		if(ran==1)
		{
			ran= 3+rand()%2;
			buscapos(cuadricula,pos);
			movery(cuadricula,pos,ran);

		}
		
	}


}

void comprobarcompleto(int cuadricula[4][4],int vueltas)
{
	bool res=false;
	if(cuadricula[0][0] == 1 && cuadricula[0][1] == 2 && cuadricula[0][2] == 3 && cuadricula[0][3] == 4  && cuadricula[1][0] == 5 && cuadricula[1][1] == 6 && cuadricula[1][2] == 7 && cuadricula[1][3] == 8 && cuadricula[2][0] == 9 && cuadricula[2][1] == 10 && cuadricula[2][2] == 11 && cuadricula[2][3] == 12 && cuadricula[3][0] == 13 && cuadricula[3][1] == 14 && cuadricula[3][2] == 15 && cuadricula[3][3] == 0)
	{
		
		printf("Resuelto en %d movimientos\n",vueltas);

		imprimircuadricula(cuadricula);
		res=true;
		exit(0);
	}


}






int main()
{	
	int pos[2],Bloq=0;
	int cuadricula[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};
	int  infi=-1;
	int mov;
	int acum[16]={1,1,1},res=3;	

	
	srand(time(NULL));
	
	int ran;
	int control;

	imprimircuadricula(cuadricula);	

	long vueltas=0;

	shuffle(cuadricula,pos);
	printf("Revuelto\n");

	imprimircuadricula(cuadricula);
	scanf("%d",&control);
	
	

	int siguiente[2];
	bool ban=false;

	while(infi<0)
	{
		
		
		ran = rand()%2;
		if(ran==0)
		{
			ran = 1+rand()%2;
			buscapos(cuadricula,pos);

			if(ran==1)
			{
				siguiente[0]=pos[0];
				siguiente[1]=pos[1]+1;

				ban = BuscarBloq(cuadricula,siguiente);
			}
			else
			{
				siguiente[0]=pos[0];
				siguiente[1]=pos[1]-1;

				ban = BuscarBloq(cuadricula,siguiente);
			}
			if(ban == false)
				moverx(cuadricula,pos,ran);
		comprobarcompleto(cuadricula,vueltas);
		}else 
		if(ran==1)//mover y
		{
			ran= 3+rand()%2;
			buscapos(cuadricula,pos);
			
			if(ran==3)
			{
				siguiente[0]=pos[0]+1;
				siguiente[1]=pos[1];

				ban = BuscarBloq(cuadricula,siguiente);
			}
			else
			{
				siguiente[0]=pos[0]-1;
				siguiente[1]=pos[1];

				ban = BuscarBloq(cuadricula,siguiente);
			}
			if(ban == false)
				movery(cuadricula,pos,ran);
		comprobarcompleto(cuadricula,vueltas);
		}
		vueltas++;
		 
			
		if(cuadricula[0][0] == 1 && fb[0][0] != 0 && fb[0][1] != 0)
		{
			fb[0][0] = 0;
			fb[0][1] = 0;
			acum[0]=0;
			cb++;
			break;
			
					
		}
		
	
	}
	
	

	imprimircuadricula(cuadricula);
	printf("Movimientos: %li\n",vueltas);

	
	


	while(infi<0)
	{
		
		
		ran = rand()%2;
		if(ran==0)
		{
			ran = 1+rand()%2;
			buscapos(cuadricula,pos);

			if(ran==1)
			{
				siguiente[0]=pos[0];
				siguiente[1]=pos[1]+1;

				ban = BuscarBloq(cuadricula,siguiente);
			}
			else
			{
				siguiente[0]=pos[0];
				siguiente[1]=pos[1]-1;

				ban = BuscarBloq(cuadricula,siguiente);
			}
			if(ban == false)
				moverx(cuadricula,pos,ran);
		comprobarcompleto(cuadricula,vueltas);
		}else 
		if(ran==1)//mover y
		{
			ran= 3+rand()%2;
			buscapos(cuadricula,pos);
			
			if(ran==3)
			{
				siguiente[0]=pos[0]+1;
				siguiente[1]=pos[1];

				ban = BuscarBloq(cuadricula,siguiente);
			}
			else
			{
				siguiente[0]=pos[0]-1;
				siguiente[1]=pos[1];

				ban = BuscarBloq(cuadricula,siguiente);
			}
			if(ban == false)
				movery(cuadricula,pos,ran);
		comprobarcompleto(cuadricula,vueltas);
		}
		vueltas++;
		 
			
		if(cuadricula[0][1] == 2 && fb[1][0] != 0 && fb[1][1] != 1)
		{
			fb[1][0] = 0;
			fb[1][1] = 1;
			acum[1]=0;
			cb++;
			break;
			
					
		}
		
	
	}


	imprimircuadricula(cuadricula);
	printf("movimientos: %li\n",vueltas );
	



	while(infi<0)
	{
		
		
		ran = rand()%2;
		if(ran==0)
		{
			ran = 1+rand()%2;
			buscapos(cuadricula,pos);

			if(ran==1)
			{
				siguiente[0]=pos[0];
				siguiente[1]=pos[1]+1;

				ban = BuscarBloq(cuadricula,siguiente);
			}
			else
			{
				siguiente[0]=pos[0];
				siguiente[1]=pos[1]-1;

				ban = BuscarBloq(cuadricula,siguiente);
			}
			if(ban == false)
				moverx(cuadricula,pos,ran);
		comprobarcompleto(cuadricula,vueltas);
		}else 
		if(ran==1)//mover y
		{
			ran= 3+rand()%2;
			buscapos(cuadricula,pos);
			
			if(ran==3)
			{
				siguiente[0]=pos[0]+1;
				siguiente[1]=pos[1];

				ban = BuscarBloq(cuadricula,siguiente);
			}
			else
			{
				siguiente[0]=pos[0]-1;
				siguiente[1]=pos[1];

				ban = BuscarBloq(cuadricula,siguiente);
			}
			if(ban == false)
				movery(cuadricula,pos,ran);
		comprobarcompleto(cuadricula,vueltas);
		}
		vueltas++;
		 
			
		if(cuadricula[1][0] == 5 && fb[1][0] != 1 && fb[1][1] != 0)
		{
			fb[2][0] = 1;
			fb[2][1] = 0;
			acum[2]=0;
			cb++;
			break;
			
					
		}
		
	
	}


	imprimircuadricula(cuadricula);
	printf("Movimientos: %li\n",vueltas );
	

	while(infi<0)
	{
		
		
		ran = rand()%2;
		if(ran==0)
		{
			ran = 1+rand()%2;
			buscapos(cuadricula,pos);

			if(ran==1)
			{
				siguiente[0]=pos[0];
				siguiente[1]=pos[1]+1;

				ban = BuscarBloq(cuadricula,siguiente);
			}
			else
			{
				siguiente[0]=pos[0];
				siguiente[1]=pos[1]-1;

				ban = BuscarBloq(cuadricula,siguiente);
			}
			if(ban == false)
				moverx(cuadricula,pos,ran);
		comprobarcompleto(cuadricula,vueltas);
		}else 
		if(ran==1)//mover y
		{
			ran= 3+rand()%2;
			buscapos(cuadricula,pos);
			
			if(ran==3)
			{
				siguiente[0]=pos[0]+1;
				siguiente[1]=pos[1];

				ban = BuscarBloq(cuadricula,siguiente);
			}
			else
			{
				siguiente[0]=pos[0]-1;
				siguiente[1]=pos[1];

				ban = BuscarBloq(cuadricula,siguiente);
			}
			if(ban == false)
				movery(cuadricula,pos,ran);
		comprobarcompleto(cuadricula,vueltas);	
		}
		vueltas++;
		 
			
		if(cuadricula[0][2] == 3 && cuadricula[0][3] == 4)
		{
			fb[3][0] = 0;
			fb[3][1] = 2;
			acum[3]=0;
			cb++;
			

			fb[4][0] = 0;
			fb[4][1] = 3;
			acum[4]=0;
			cb++;
			
			break;
			
					
		}
		
	
	}


	imprimircuadricula(cuadricula);
	printf("Movimientos: %li\n",vueltas );
	

	

	while(infi<0)
	{
		
		
		ran = rand()%2;
		if(ran==0)
		{
			ran = 1+rand()%2;
			buscapos(cuadricula,pos);

			if(ran==1)
			{
				siguiente[0]=pos[0];
				siguiente[1]=pos[1]+1;

				ban = BuscarBloq(cuadricula,siguiente);
			}
			else
			{
				siguiente[0]=pos[0];
				siguiente[1]=pos[1]-1;

				ban = BuscarBloq(cuadricula,siguiente);
			}
			if(ban == false)
				moverx(cuadricula,pos,ran);
		comprobarcompleto(cuadricula,vueltas);
		}else 
		if(ran==1)//mover y
		{
			ran= 3+rand()%2;
			buscapos(cuadricula,pos);
			
			if(ran==3)
			{
				siguiente[0]=pos[0]+1;
				siguiente[1]=pos[1];

				ban = BuscarBloq(cuadricula,siguiente);
			}
			else
			{
				siguiente[0]=pos[0]-1;
				siguiente[1]=pos[1];

				ban = BuscarBloq(cuadricula,siguiente);
			}
			if(ban == false)
				movery(cuadricula,pos,ran);
		comprobarcompleto(cuadricula,vueltas);
		}
		vueltas++;
		 
			
		if(cuadricula[2][0] == 9 && cuadricula[3][0] == 13)
		{
			fb[5][0] = 2;
			fb[5][1] = 0;
			acum[4]=0;
			cb++;
			

			fb[6][0] = 3;
			fb[6][1] = 0;
			acum[4]=0;
			cb++;
			
			break;
			
					
		}
		
	
	}


	imprimircuadricula(cuadricula);
	printf("Movimientos: %li\n",vueltas );
	




	while(infi<0)
	{
		
		
		ran = rand()%2;
		if(ran==0)
		{
			ran = 1+rand()%2;
			buscapos(cuadricula,pos);

			if(ran==1)
			{
				siguiente[0]=pos[0];
				siguiente[1]=pos[1]+1;

				ban = BuscarBloq(cuadricula,siguiente);
			}
			else
			{
				siguiente[0]=pos[0];
				siguiente[1]=pos[1]-1;

				ban = BuscarBloq(cuadricula,siguiente);
			}
			if(ban == false)
				moverx(cuadricula,pos,ran);
		comprobarcompleto(cuadricula,vueltas);
		}else 
		if(ran==1)//mover y
		{
			ran= 3+rand()%2;
			buscapos(cuadricula,pos);
			
			if(ran==3)
			{
				siguiente[0]=pos[0]+1;
				siguiente[1]=pos[1];

				ban = BuscarBloq(cuadricula,siguiente);
			}
			else
			{
				siguiente[0]=pos[0]-1;
				siguiente[1]=pos[1];

				ban = BuscarBloq(cuadricula,siguiente);
			}
			if(ban == false)
				movery(cuadricula,pos,ran);
		comprobarcompleto(cuadricula,vueltas);
		}
		vueltas++;
		 
			
		if(cuadricula[1][1]==6 )
		{ 
			fb[7][0] = 1;
			fb[7][1] = 1;
			acum[4]=0;
			cb++;
			
			break;
					
		}
		
	
	}


	imprimircuadricula(cuadricula);
	printf("Movimientos: %li\n",vueltas );
	



	while(infi<0)
	{
		
		
		ran = rand()%2;
		if(ran==0)
		{
			ran = 1+rand()%2;
			buscapos(cuadricula,pos);

			if(ran==1)
			{
				siguiente[0]=pos[0];
				siguiente[1]=pos[1]+1;

				ban = BuscarBloq(cuadricula,siguiente);
			}
			else
			{
				siguiente[0]=pos[0];
				siguiente[1]=pos[1]-1;

				ban = BuscarBloq(cuadricula,siguiente);
			}
			if(ban == false)
				moverx(cuadricula,pos,ran);

		comprobarcompleto(cuadricula,vueltas);
		}else 
		if(ran==1)//mover y
		{
			ran= 3+rand()%2;
			buscapos(cuadricula,pos);
			
			if(ran==3)
			{
				siguiente[0]=pos[0]+1;
				siguiente[1]=pos[1];

				ban = BuscarBloq(cuadricula,siguiente);
			}
			else
			{
				siguiente[0]=pos[0]-1;
				siguiente[1]=pos[1];

				ban = BuscarBloq(cuadricula,siguiente);
			}
			if(ban == false)
				movery(cuadricula,pos,ran);

		comprobarcompleto(cuadricula,vueltas);
		}
		vueltas++;
		 
			
		if(cuadricula[1][2]== 7 && cuadricula[1][3]== 8)
		{
			fb[8][0] = 1;
			fb[8][1] = 2;
			acum[5]=0;
			cb++;
			

			fb[9][0] = 1;
			fb[9][1] = 3;
			acum[5]=0;
			cb++;
			
			break;
					
		}
		
	
	}


	imprimircuadricula(cuadricula);
	printf("Movimientos: %li\n",vueltas );
	

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	
	while(infi<0)
	{
		
		comprobarcompleto(cuadricula,vueltas);
		ran = rand()%2;
		if(ran==0)
		{
			ran = 1+rand()%2;
			buscapos(cuadricula,pos);

			if(ran==1)
			{
				siguiente[0]=pos[0];
				siguiente[1]=pos[1]+1;

				ban = BuscarBloq(cuadricula,siguiente);
			}
			else
			{
				siguiente[0]=pos[0];
				siguiente[1]=pos[1]-1;

				ban = BuscarBloq(cuadricula,siguiente);
			}
			if(ban == false)
				moverx(cuadricula,pos,ran);

		}else 
		if(ran==1)//mover y
		{
			ran= 3+rand()%2;
			buscapos(cuadricula,pos);
			
			if(ran==3)
			{
				siguiente[0]=pos[0]+1;
				siguiente[1]=pos[1];

				ban = BuscarBloq(cuadricula,siguiente);
			}
			else
			{
				siguiente[0]=pos[0]-1;
				siguiente[1]=pos[1];

				ban = BuscarBloq(cuadricula,siguiente);
			}
			if(ban == false)
				movery(cuadricula,pos,ran);

		}
		vueltas++;
		 
			


		
	
	}

	

	

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

	bool resuelto=false;
	while(resuelto != true)
	{
		
		//resuelto = comprobarcompleto(cuadricula,vueltas);
		ran = rand()%2;
		if(ran==0)
		{
			ran = 1+rand()%2;
			buscapos(cuadricula,pos);

			if(ran==1)
			{
				siguiente[0]=pos[0];
				siguiente[1]=pos[1]+1;

				ban = BuscarBloq(cuadricula,siguiente);
			}
			else
			{
				siguiente[0]=pos[0];
				siguiente[1]=pos[1]-1;

				ban = BuscarBloq(cuadricula,siguiente);
			}
			if(ban == false)
				moverx(cuadricula,pos,ran);

		}else 
		if(ran==1)//mover y
		{
			ran= 3+rand()%2;
			buscapos(cuadricula,pos);
			
			if(ran==3)
			{
				siguiente[0]=pos[0]+1;
				siguiente[1]=pos[1];

				ban = BuscarBloq(cuadricula,siguiente);
			}
			else
			{
				siguiente[0]=pos[0]-1;
				siguiente[1]=pos[1];

				ban = BuscarBloq(cuadricula,siguiente);
			}
			if(ban == false)
				movery(cuadricula,pos,ran);

		}
		vueltas++;
		 
			
		
		
	
	}


	imprimircuadricula(cuadricula);
	printf("9 vueltas: %li\n",vueltas );
	printf("%d, %d\n",fb[0][0],fb[0][1]);
	printf("%d, %d\n",fb[1][0],fb[1][1]);
	printf("%d, %d\n",fb[2][0],fb[2][1]);
	printf("%d, %d\n",fb[3][0],fb[3][1]);
	printf("%d, %d\n",fb[4][0],fb[4][1]);
	printf("%d, %d\n",fb[5][0],fb[5][1]);
	printf("%d, %d\n",fb[6][0],fb[6][1]);
	printf("%d, %d\n",fb[7][0],fb[7][1]);
	printf("%d, %d\n",fb[8][0],fb[8][1]);
	printf("%d, %d\n",fb[9][0],fb[9][1]);
	printf("%d, %d\n",fb[10][0],fb[10][1]);
	printf("%d, %d\n",fb[11][0],fb[11][1]);
	printf("cb: %d\n",cb );	
	*/
}







/*
bool resuelto=false;

	while(resuelto != true)
	{
		resuelto = comprobarcompleto(cuadricula,vueltas);		
		
		ran = rand()%2;
		if(ran==0)
		{
			ran = 1+rand()%2;
			buscapos(cuadricula,pos);

			if(ran==1)
			{
				siguiente[0]=pos[0];
				siguiente[1]=pos[1]+1;

				ban = BuscarBloq(cuadricula,siguiente);
			}
			else
			{
				siguiente[0]=pos[0];
				siguiente[1]=pos[1]-1;

				ban = BuscarBloq(cuadricula,siguiente);
			}
			if(ban == false)
				moverx(cuadricula,pos,ran);

		}else 
		if(ran==1)//mover y
		{
			ran= 3+rand()%2;
			buscapos(cuadricula,pos);
			
			if(ran==3)
			{
				siguiente[0]=pos[0]+1;
				siguiente[1]=pos[1];

				ban = BuscarBloq(cuadricula,siguiente);
			}
			else
			{
				siguiente[0]=pos[0]-1;
				siguiente[1]=pos[1];

				ban = BuscarBloq(cuadricula,siguiente);
			}
			if(ban == false)
				movery(cuadricula,pos,ran);

		}
		vueltas++;
		 
			
		if(cuadricula[2][1]== 10 && cuadricula[3][1]== 14)
		{
			fb[9][0] = 2;
			fb[9][1] = 1;
			acum[5]=0;
			cb++;
			

			fb[10][0] = 3;
			fb[10][1] = 1;
			acum[5]=0;
			cb++;
			
			break;
					
		}
		
	
	}


	imprimircuadricula(cuadricula);
	printf("8 vueltas: %li\n",vueltas );
	printf("%d, %d\n",fb[0][0],fb[0][1]);
	printf("%d, %d\n",fb[1][0],fb[1][1]);
	printf("%d, %d\n",fb[2][0],fb[2][1]);
	printf("%d, %d\n",fb[3][0],fb[3][1]);
	printf("%d, %d\n",fb[4][0],fb[4][1]);
	printf("%d, %d\n",fb[5][0],fb[5][1]);
	printf("%d, %d\n",fb[6][0],fb[6][1]);
	printf("%d, %d\n",fb[7][0],fb[7][1]);
	printf("%d, %d\n",fb[8][0],fb[8][1]);
	printf("%d, %d\n",fb[9][0],fb[9][1]);
	printf("%d, %d\n",fb[10][0],fb[10][1]);
	printf("%d, %d\n",fb[11][0],fb[11][1]);
	printf("cb: %d\n",cb );	



*/
//name-Md Ahnaf Tajwar Kamal
//uta id:1001854202
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<time.h>

void Fill_Array(int array[][5],int DUP_array[25]);

void print_array(int array[][5]);

int no_exists_one(int bingo_array[][5],int num_exist);

int comp_row_one(int bingo_array[][5]);

int comp_col_one(int bingo_array[][5]);

int PickNumber(int bingo_array[][5],int DUP_array[25], int counter);




int main(void)
{
	int bingo_array[5][5]={};
	int DUP_array[25]={};

	char decision;
	char c;

	int counter=0;

	int called_no;
	//int no_exists;
	int num_exist;

	srand(time(0));

	

	Fill_Array(bingo_array,DUP_array);
	print_array( bingo_array);

   
	
		while(counter<75)
		{
			called_no=PickNumber(bingo_array,DUP_array,counter);

			if(called_no>0 || called_no<16)
			{
				c='B';
	
			}
			if(called_no>15 || called_no<31)
			{
				c='I';
	
			}
			if(called_no>30 || called_no<46)
			{
				c='N';
	
			}
			if(called_no>45 || called_no<61)
			{
				c='G';
	
			}
			if(called_no>60 || called_no<76)
			{
				c='O';
	
			}
			
		
			printf("The next number is %c%d\n",c,called_no);



			printf("Do you have this number?");
			scanf("%c",&decision);

			if(decision!='Y')
			{
				print_array( bingo_array);
				counter++;

	           
			}
			if(decision=='Y')
			{
				int no_exists=no_exists_one(bingo_array,called_no);

				if(no_exists!=1)
				{
					printf("This value is not in your bingo card-are you trying to cheat?");
	
				}
				if(no_exists==1)
				{
					int comp_row=comp_row_one(bingo_array);
					int comp_col=comp_col_one(bingo_array);

					if(comp_row==1)
					{
						printf("You filled out a row-BINGO\n");
						counter=100;
	
					}
					if(comp_col==1)
					{
						printf("You filled out a column-BINGO\n");
						counter=100;

					}


	
				}


	
			}
			counter++;


		}

	
	
	return 0;
}

void Fill_Array(int bingo_array[][5],int DUP_array[25])
{
	int value;
	int k=0;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			value=rand()%15+(j*15)+1;
			bingo_array[i][j]=value;
			DUP_array[k]=bingo_array[i][j];
			k++;
			
			
		}
		
	}
	bingo_array[2][2]='0';
		
	
}

void print_array(int array[][5])
{
	printf("B\tI\tN\tG\tO\n");

	for(int k=0;k<39;k++)
	{	
	   printf("-");
	}
	printf("\n"); 

	for(int i=0;i<5;i++)
	{

		for(int j=0;j<5;j++)
		{
			if(array[i][j]=='0')
			{
				printf(" X\t");
			}
			else
			{	
				printf("|%d|\t",array[i][j]);
			}	
		    
		}

		printf("\n");

		for(int x=0;x<39;x++)
		{
	        printf("-");
		}
		printf("\n");
		
	}

}

int PickNumber(int bingo_array[][5],int DUP_array[25], int counter)
{
	int value;
	for(int k=0;k<25;k++)
	{
		for(int row=0;row<5;row++)
		{
			for(int col=0;col<5;col++)
			{
				//bingo_array[row][col];

				while(DUP_array[k]!=bingo_array[row][col])
			    {
				 value=rand()%15+(col*15)+1;
			     bingo_array[row][col]=value;
			     DUP_array[k]=bingo_array[row][col];
			     k++;
			     counter=k;

			    }
			}
			
			//printf("%d",value);	
		}	
	}
	return value;	
}

int no_exists_one(int bingo_array[][5],int num_exist)
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(bingo_array[i][j]==num_exist)
			{
				bingo_array[i][j]='0';

				return 1;
			}	
		}	

	}	
	return 0;
}

int comp_row_one(int bingo_array[][5])
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(bingo_array[i][j]=='0')
			{
				return 1;
			}	
		}	
	}
	return 0;	
}	

int comp_col_one(int bingo_array[][5])
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(bingo_array[j][i]=='0')
			{
				return 1;
			}	
		}	
	}
	return 0;	
}
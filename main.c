#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <limits.h>
#include <time.h>

float getFloat (int mode);
void clear_stdin();
int getInt ();
int main()
{
	float **a;
	int n = 0, c = 0, ch = 0;
	float s = 0.0, a_mean = 0.0;
	int r = (unsigned int)(time(NULL));
	srand(r);
	do
	{
		c = 0;
		system("cls");
		printf("A. INPUT ARRAY\n");
		printf("B. PROCESS ARRAY\n");
		printf("C. OUTPUT ARRAY\n");
		printf("D. EXIT\n");
		c = getchar();
		switch (c)
		{
            case 97 :   //a
            {

                system("cls");
                printf("ENTER THE SIZE OF ARRAY: ");
                clear_stdin();
                n = getInt();
                a = (float**)malloc(n * sizeof(float*));
                for(int i = 0; i < n; i++)
                {
                    a[i] = (float*)malloc(n * sizeof(float));
                }
                printf("FILL THE ARRAY WITH RANDOM VALUES? (y/n) ");
                ch = getchar();
                clear_stdin();
                switch (ch)
                    {
                    case 121 :   //y
                    {
                        for(int i = 0; i < n; i++)
                        {
                            for(int j = 0; j < n; j++)
                            {
                            a[i][j] = getFloat(2);
                            printf("%-7.2f ", a[i][j]);
                            }
                            printf("\n");
                        }
                        getchar();
                        clear_stdin();
                        break;
                    }
                    case 110 :   //n
                    {
                        for(int i = 0; i < n; i++)
                        {
                            for(int j = 0; j < n; j++)
                            {
                            a[i][j] = getFloat(1);
                            }
                            printf("\n");
                        }
                        break;
                    }
                    }
                ch = 0;
                c = 0;
                continue;
            }
            case 98 :   //b
            {
                if (n > 0)
                {
                    for (int i = 0; i < n; i++)
                    {
                        s += a[i][n-i-1];
                    }
                    a_mean = s / n;
                }
                else
                {
                    printf("THE ARRAY IS EMPTY!\n");
                    getchar();
                    clear_stdin();
                }
                c = 0;
                continue;
            }
            case 99 :   //c
            {
			system("cls");
			printf("INPUT ARRAY: \n");
			for(int i = 0; i < n; i++)
			{
			    for (int j = 0; j < n; j++)
                    printf("%-7.2f ", a[i][j]);
                printf("\n");
			}
			printf("\n");
			printf("OUTPUT ARRAY: \n");

			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < n; j++)
                {
                    if (i > j)
                    {
                        printf("%-7.2f ", a_mean);
                    }
                    else
                    {
                        printf("%-7.2f ", a[i][j]);
                    }

                }
                printf("\n");
			}
			c = 0;
			getchar();
			clear_stdin();
			continue;
		}
		}
	}
	while(c != 100);
	for(int i = 0; i < n; i++)
    {
        free(a[i]);
    }
	free(a);
	return 0;
}

void clear_stdin()
{
	int ch = getchar();
	while (ch != '\n' && ch != EOF)
	{
		ch = getchar();
	}
}

float getFloat (int mode)
{
	char str[512];
	int r;
	float x;
	switch(mode)
	{
	case 1 :
	{
		fgets(str, sizeof(str), stdin);
		while (sscanf (str, "%d", &r) != 1)
		{
			printf("Enter correct value!\n");
			fgets(str, sizeof(str), stdin);
		}
		x = (float)r;
		break;
	}
	case 2 :
	{
		x = (float)(rand() % 256 - 128);
		break;
	}
	default :
	{
		x = 0.1;
	}

	}
	return x;
}


int getInt (){
	char str[512];
	int x;

	fgets(str, sizeof(str), stdin);
	while (sscanf (str, "%d", &x) != 1) {
		printf("Enter correct value!\n");
		fgets(str, sizeof(str), stdin);
	}
	return x;
}

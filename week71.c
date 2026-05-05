#include <stdio.h>
#include <stdlib.h>

int p[10], ch, i, j, n, hp, temp;
int eat[10], think[10];

void one()
{
    printf("Allow one philosopher to eat at any time\n");

    for(i = 0; i < hp; i++)
    {
        printf("P %d is waiting\n", p[i]);
    }

    int done[10] = {0};

    for(i = 0; i < hp; i++)
    {
        if(done[i] == 0)
        {
            printf("\nP %d is granted to eat\n", p[i]);
            printf("P %d has finished eating\n", p[i]);

            done[i] = 1;
        }
    }
}

void two()
{
    printf("Allow two philosophers to eat at any time\n");

    int done[10] = {0};

    for(i = 0; i < hp; i++)
    {
        if(done[i] == 0)
        {
            printf("\nP %d is granted to eat\n", p[i]);

            for(j = i + 1; j < hp; j++)
            {
                if((p[i] + 1) % n != p[j] % n &&
                   p[i] % n != (p[j] + 1) % n)
                {
                    printf("P %d is granted to eat\n", p[j]);

                    done[j] = 1;

                    printf("P %d has finished eating\n", p[j]);
                    break;
                }
            }

            printf("P %d has finished eating\n", p[i]);

            done[i] = 1;
        }
    }
}

int main()
{
    printf("Enter the total number of philosophers: ");
    scanf("%d", &n);

    printf("How many are hungry: ");
    scanf("%d", &hp);

    for(i = 0; i < hp; i++)
    {
        printf("Enter philosopher %d position (1 to %d): ", i + 1, n);
        scanf("%d", &p[i]);
    }

    do
    {
        printf("\n1. One can eat at a time");
        printf("\n2. Two can eat at a time");
        printf("\n3. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                one();
                break;

            case 2:
                two();
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid option\n");
        }

    } while(ch != 3);

    return 0;
}

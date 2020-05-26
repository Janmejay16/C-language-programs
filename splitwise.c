#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,p,q,n,avg;
    int sum=0;
    printf("Enter total number of people : ");
    scanf("%d",&n);
    int diffarr[n];
    int expense[n];
    char names[n][30];

    for(p=0;p<n;p++)
    {
        printf("Enter name of person %d :",p+1);
        fflush(stdin);
        gets(names[p]);
    }

    system("cls");
    for(p=0;p<n;p++)
    {
        printf("Enter contribution by person %d :",p+1);
        scanf("%d",&i);
        expense[p] = i;
    }

    for(p=0;p<n;p++)
    {
        sum = sum + expense[p];
    }
    avg = (float)sum/n;
    system("cls");
    printf("\n\t\tAverage contribution = %d\n\n",avg);

    for(p=0;p<n;p++)
    {
        diffarr[p] = expense[p]-avg;
    }
    printf("******************************RESULT******************************\n");
    initiate:
    for(p=0;p<n;p++)
    {
        if(diffarr[p]<0)
        {
            for(q=0;q<n;q++)
            {
                if(abs(diffarr[p]) == diffarr[q] && p!=q)
                {
                    printf("\n\t\t%s has to give Rs.%d to %s \n",names[p],abs(diffarr[p]),names[q]);
                    diffarr[q] = 0;
                    diffarr[p] = 0;
                    q++;
                    goto initiate;

                }
                else if(abs(diffarr[p]) > diffarr[q] && p!=q && diffarr[q] > 0)
                {
                    printf("\n\t\t%s has to give Rs.%d to %s \n",names[p],diffarr[q],names[q]);
                    diffarr[p] = diffarr[p] + diffarr[q];
                    diffarr[q] = 0;
                    q++;
                    goto initiate;

                }
                else if(abs(diffarr[p]) < diffarr[q] && diffarr[q] > 0)
                {
                    printf("\n\t\t%s has to give Rs.%d to %s \n",names[p],abs(diffarr[p]),names[q]);
                    diffarr[q] = diffarr[p] + diffarr[q];
                    diffarr[p] = 0;
                    q++;
                    goto initiate;


                }


            }
        }
    }

}

#include<stdio.h>

#include<stdlib.h>

#define N 1000000

main()

{

    int *sum_of_div,i,j,t,len,count,remain=N,max_len=0;
    sum_of_div=(int*)malloc((N+1)*sizeof(int));
    for(i=1;i<=N;i++)

	{

	    sum_of_div[i]=1;

	}

    for(i=2;i*i<=N;i++)

	{

	    for(j=i+1;j*i<=N;j++)

		{

		    sum_of_div[i*j]+=i+j;

		}

	    sum_of_div[i*i]+=i;

	}                                        //①

    for(i=1;i<=N;i++)

	{

	    if(sum_of_div[i]>N)

		{

		    sum_of_div[i]=0;

		    remain--;

		}                                   //①

	}

    for(max_len=1;remain>0;max_len++)        //②

	{   

	    for(i=1,count=0;i<=N;i++)

		{

		    if(sum_of_div[i])

			{

			    for(t=i,len=0;len<max_len;len++)

				{

				    if(sum_of_div[t])

					{

					    t=sum_of_div[t];

					}

				    else

					{

					    sum_of_div[i]=0;       //④

					    remain--;

					    len=max_len;           //用于结束循环并使后面能判断该循环是由于这个原因结束的

					}

				}

                

			    if(len==max_len && t==i)

				{

				    printf("%8d",i);

				    count++;

				    sum_of_div[i]=0;           //③

				    remain--;

				}

			}

		}

	    if(count)

		{

		    printf("\n%d节的友好链共有以上%d组\n",max_len,count);

		}

	}

    free(sum_of_div);

}

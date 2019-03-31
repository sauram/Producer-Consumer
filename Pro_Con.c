//15.03.2019
//Saurabh Singh Gautam
//Sauram
/*

Following is the solution of Producer-Consumer Problem

*/
#include<stdio.h>
#include<stdlib.h>
 
int mutual_wala_exclusion=1,Buffer_is_full=0,Buffer_is_empty=3,x_pc=0;
 
int main()
{
	int n;
	void smproducerfn();
	void smconsumerfn();
	int wait_sema_phore(int);
	int signal_sema_phore(int);
	printf("\n1.Producer\n2.Consumer\n3.Exit");
	while(1)
	{
		printf("\nEnter the choice:");
		scanf("%d",&n);
		switch(n)
		{
			case 1:	if((mutual_wala_exclusion==1)&&(Buffer_is_empty!=0))
						smproducerfn();
					else
						printf("Oops ! Buffer is Buffer_is_full.");
					break;
			case 2:	if((mutual_wala_exclusion==1)&&(Buffer_is_full!=0))
						smconsumerfn();
					else
						printf("Oops ! Buffer is Buffer_is_empty.");
					break;
			case 3:
					exit(0);
					break;
		}
	}
	
	return 0;
}
 
int wait_sema_phore(int s)
{
	return (--s);
}
 
int signal_sema_phore(int s)
{
	return(++s);
}
 
void smproducerfn()
{
	mutual_wala_exclusion=wait_sema_phore(mutual_wala_exclusion);
	Buffer_is_full=signal_sema_phore(Buffer_is_full);
	Buffer_is_empty=wait_sema_phore(Buffer_is_empty);
	x_pc++;
	printf("\nProducer produces the item %d",x_pc);
	mutual_wala_exclusion=signal_sema_phore(mutual_wala_exclusion);
}
 
void smconsumerfn()
{
	mutual_wala_exclusion=wait_sema_phore(mutual_wala_exclusion);
	Buffer_is_full=wait_sema_phore(Buffer_is_full);
	Buffer_is_empty=signal_sema_phore(Buffer_is_empty);
	printf("\nConsumer consumes item %d",x_pc);
	x_pc--;
	mutual_wala_exclusion=signal_sema_phore(mutual_wala_exclusion);
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

struct node
{	char ques[500];
	char ans1[200];
	char ans2[200];
	char ans3[200];
	char ans4[200];
	int correct;
	struct node *next;
};
struct node *head=NULL;

void insert(char *q,char *a1,char *a2,char *a3,char *a4,int ch)
{	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	strcpy(temp->ques,q);
	strcpy(temp->ans1,a1);
	strcpy(temp->ans2,a2);
	strcpy(temp->ans3,a3);
	strcpy(temp->ans4,a4);
	temp->correct=ch;
	temp->next=NULL;
	if(head==NULL)
		head=temp;
	else
	{	struct node * p=head;
		while(p->next!=NULL)
			p=p->next;
		p->next=temp;}
	}

void answer()
{	int corr,sum=0;
	int i=0, visited[3];
	visited[0]=0;
	visited[1]=0;
	visited[2]=0;
	int os;
	struct node *p=head;
	while(p!=NULL)
	{	printf("Ques. %s\n\n\n",p->ques);
		printf("Opt1. %s\n",p->ans1);
		printf("Opt2. %s\n",p->ans2);
		printf("Opt3. %s\n",p->ans3);
		printf("Opt4. %s\n\n",p->ans4);
		printf("Enter 911 to use helpline\n\n");
		printf("Enter your option:");
		scanf("%d",&corr);
		if(corr==911)
		{	printf("There are 3 lifelines : 1.Call a friend\t\t2.Audience Poll\t\t3.Ultimate lifeline\nEnter your choice:");
			scanf("%d",&os);
			while(1)
			{	if((os==1||os==2||os==3)&&visited[os-1]!=1)
				{	visited[os-1]=1;
					printf("**You have won this question**(But you only won 1,00,000 for this question)\n");
					sum=sum+100000;
					printf("Your total earning is Rs.%d\n\n\n\n\n\n\n\n",sum);
					break;
				}
				else
				{	printf("Wrong option entered or it has been used previously\n");
					printf("Enter your option again : ");
					scanf("%d",&os);
				}
			}
		}
		else
		{	if(corr==p->correct)
			{	sum=sum+500000;
				printf("Entered option is correct and your total earning is Rs.%d\n\n\n\n\n\n\n\n",sum);
			}
			else
				printf("Wrong option, sorry you didn't win anything\n\n\n\n\n\n\n\n");
		}
		p=p->next;
	}
	printf("Total amount won is Rs. %d",sum);
}

void queslist()
{	char q1[500]="Who is the President of India?\0";
	char a11[200]="Narendra Modi\0";
	char a21[200]="Ramnath Kovind\0";
	char a31[200]="Manmohan Singh\0";
	char a41[200]="Venkaihya Naidu\0";
	int ch1=2;
	insert(q1,a11,a21,a31,a41,ch1);
	char q2[500]="Who is the director of the film Interstellar?\0";
	char a12[200]="W.B.	Weide\0";
	char a22[200]="Steven Spielberg\0";
	char a32[200]="James Cameron\0";
	char a42[200]="Christopher Nolan\0";
	int ch2=4;
	insert(q2,a12,a22,a32,a42,ch2);
	char q3[500]="Where is Taj Mahal Located?";
	char a13[200]="Kolkata";
	char a23[200]="Hyderabad";
	char a33[200]="Mumbai";
	char a43[200]="Agra";
	int ch3=4;
	insert(q3,a13,a23,a33,a43,ch3);
	char q4[500]="What is the currency of Russia?";
	char a14[200]="Rubal";
	char a24[200]="Dollar";
	char a34[200]="Rand";
	char a44[200]="Pound";
	int ch4=1;
	insert(q4,a14,a24,a34,a44,ch4);
	char q5[500]="Who is regarded as Captain Cool?";
	char a15[200]="Sachin Tendukar";
	char a25[200]="Sourav Ganguly";
	char a35[200]="MS Dhoni";
	char a45[200]="Virat Kohli";
	int ch5=3;
	insert(q5,a15,a25,a35,a45,ch5);
	char q6[500]="______ is the Capital of Syria";
	char a16[200]="Dhaka";
	char a26[200]="Damascus";
	char a36[200]="Islamabad";
	char a46[200]="Kabul";
	int ch6=2;
	insert(q6,a16,a26,a36,a46,ch6);
}

int main()
{	printf("1.Superuser(Want to add additional questions)\n2.User(Normal users)\nEnter:");
	int n;	
	char q[500],a1[200],a2[200],a3[200],a4[200];
	int opt;
	scanf("%d",&n);
	getchar();
	queslist();
	if(n==1)
	{	while(n!=-1)
		{	printf("Enter your question:");
			gets(q);
			printf("Enter option 1:");
			gets(a1);
			printf("Enter option 2:");
			gets(a2);
			printf("Enter option 3:");
			gets(a3);
			printf("Enter option 4:");
			gets(a4);
			printf("Enter correct option out of 4");
			scanf("%d",&opt);
			insert(q,a1,a2,a3,a4,opt);
			printf("Enter -1 to stop entering questions and 1 to continue:");
			scanf("%d",&n);
			getchar();
		}
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nWelcome to the game of \n***Kaun Banega Crorepati***\nEach right answer has prize money of Rs.5,00,000.\nToh Chaliye shuru karte hai ees Adhbut khel ko     jiska naam hai Kaun Banega Crorepati!!!\n\n");
	answer();
	return 0;
}
    

/*int i=0, visited[3];
printf("Enter 911 to use helpline\n");
printf("There are 3 lifelines : 1.Call a friend\t2.Audience Poll\t3.Ultimate lifeline\nEnter your choice:");
int os;
scanf("%d",&os);
while(1)
{	if((os==1||os==2||os==3)&&visited[os-1]!=1)
	{	visited[os-1]=1;
		printf("**You have won this question**");
		break;
	}
	else
	{	printf("Enter your option again");
	}
}
*/
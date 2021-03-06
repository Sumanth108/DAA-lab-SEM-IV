#include<stdio.h>
#include<string.h>


int S[130];
int p_size,size;

void shift_table(char p[])
{
	int m=p_size;
	int i,j;
	
	for(i=0;i<128;i++)
		S[i]=m;
	for(j=0;j<m-1;j++)
		S[p[j]]=m-1-j;
		
}

int horspool(char t[],char p[])
{
	int i,j,k,m,n;
	n=size;
	m=p_size;
	
	i=m-1;
	while(i<n)
	{
		k=0;
		while((k<m) && (p[m-1-k]==t[i-k]))
			k++;
		if(k==m)
			return (i-m+1);
		else
			i+=S[t[i]];
	}
	return -1;
}

	
void main()
{
	int pos;
	char t[100],p[100];
	
	printf("Einput the input string:");
	gets(t);
	size=strlen(t);

	printf("Enter the pattern string:");
	gets(p);
	p_size=strlen(p);
	
	
	shift_table(p);
	pos=horspool(t,p);
	
	if(pos>0)
		printf("Found, beginning at %d \n ",pos+1);
	else
		printf("Not Found\n");
		
}

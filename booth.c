#include<stdio.h>
main()
{
	int a,b,a1[16],cb2[16],b1[16],a2[16],b2[16],i,j,k,d=0,c=0,n,temp;
	printf("Enter value of multiplier and multiplicant :  \n");
	scanf("%d%d",&a,&b);
    for(i=0;i<16;i++)
	{
		a1[i]=0;
		b1[i]=0;
		a2[i]=0;
		b2[i]=0;
	}
	if(a<0)
	{
		a2[0]=1;
		a=-a;
	}
	if(b<0)
	{
		b2[0]=1;
		b=-b;
	}
    for(i=0;a!=0||b!=0;i++)
	{
		a1[i]=a%2;
    	a=a/2;
		b1[i]=b%2;
		b=b/2;
	}
	
	for(j=0;j<i;j++)
	{
		printf("%d",a1[j]);
    }
    printf("\n");
    for(j=0;j<i;j++)
	{
	printf("%d",b1[j]);
    }
    
	for(j=i-1,k=1;j>=0;j--,k++)
	{
	    a2[k]=a1[j];
		b2[k]=b1[j];	
	}
	if(a2[0]==1)
	{
	  	for(j=1;j<=i;j++)
    	{ 
		  if(a2[j]==0) a2[j]=1;
	      else a2[j]=0;
        }
        for(j=i;j>=0;j--)
		{
			if(j==i)
			{
				if(a2[j]==0)
				  a2[j]=1;
				else
				{
					a2[j]=0;
					d=1;
				}
			}
			else if(a2[j]==0 && d==1)
			{
				a2[j]=1;
				d=0;
			}
			else if(a2[j]==1 && d==1)
			{
				a2[j]=0;
				d=1;
			}
			
		}
        
	}
	// for 2s complement of B 
	d=0;
	if(b2[0]==1)
	{
	  	for(j=1;j<=i;j++)
    	{ 
		  if(b2[j]==0) b2[j]=1;
	      else b2[j]=0;
        }
        for(j=i;j>=0;j--)
		{
			if(j==i)
			{
				if(b2[j]==0)
				  b2[j]=1;
				else
				{
					b2[j]=0;
					d=1;
				}
			}
			else if(b2[j]==0 && d==1)
			{
				b2[j]=1;
				d=0;
			}
			else if(b2[j]==1 && d==1)
			{
				b2[j]=0;
				d=1;
			}
			
		}
	}
	//  for 2s complement of B2
    d=0;
    for(j=0;j<=i;j++)
    	{ 
		  if(b2[j]==0) cb2[j]=1;
	      else cb2[j]=0;
        }
    for(j=i;j>=0;j--)
		{
			if(j==i)
			{
				if(cb2[j]==0)
				  cb2[j]=1;
				else
				{
					cb2[j]=0;
					d=1;
				}
			}
			else if(cb2[j]==0 && d==1)
			{
				cb2[j]=1;
				d=0;
			}
			else if(cb2[j]==1 && d==1)
			{
				cb2[j]=0;
				d=1;
			}
			
		}
	

	for(j=0;j<=i;j++)
	{
		a2[j+i+1]=a2[j];
	a2[j]=0;
    }
    printf("\n final A : ");

    	for(j=0;j<=i*2+1;j++)
	{
		printf("%d",a2[j]);
    }
      printf("\nB : ");
    for(j=0;j<=i;j++)
	{
		printf("%d",b2[j]);
    }
     printf("\n complement of B : ");
    for(j=0;j<=i;j++)
	{
		printf("%d",cb2[j]);
    }
    n=i*2+1;
   
    
    for(j=0;j<=i;j++)
	{
	 printf("\npass %d step1 : ",j);
	 if(a2[n]==0&&a2[n+1]==1)
  	 {  
  	 	for(k=n/2;k>=0;k--)
		{
			temp= (a2[k]+b2[k]+c)%2;
			c= (b2[k]+a2[k]+c)/2;
			a2[k]=temp;
		}
	 	for(k=0;k<=i*2+1;k++)
			{
				printf("%d",a2[k]);
    		}
    	printf(" %d",a2[n+1]);
	 }  
	 else if(a2[n]==1&&a2[n+1]==0)
	 {  
	    for(k=n/2;k>=0;k--)
		{
			temp= (a2[k]+cb2[k]+c)%2;
			c= (cb2[k]+a2[k]+c)/2;
			a2[k]=temp;
		}
	 	
	 	for(k=0;k<=i*2+1;k++)
			{
				printf("%d",a2[k]);
    		}
    	printf(" %d",a2[n+1]);
	 }	
	 printf("\npass %d step2 : ",j);
	
     for(k=n;k>=0;k--)
     {
       a2[k+1]=a2[k];	
	 }
	 a2[0]=a2[1];
     for(k=0;k<=i*2+1;k++)
	 {
		printf("%d",a2[k]);
     }
     printf(" %d",a2[n+1]);
	}
}

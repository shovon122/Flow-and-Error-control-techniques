#include<stdio.h>
#include<string.h>
#define N strlen(g)

char t[1000],cs[1000],g[500]="100000100110000010001110110110111";
int a1,e1,c1;

int xor(){
    for(c1 = 1;c1 < N; c1++)
    cs[c1] = (( cs[c1] == g[c1])?'0':'1');
}

void crc(){
    for(e1=0;e1<N;e1++)
        cs[e1]=t[e1];
    do{
        if(cs[0]=='1')
            xor();
        for(c1=0;c1<N-1;c1++)
            cs[c1]=cs[c1+1];
        cs[c1]=t[e1++];
    }while(e1<=a1+N-1);
}

int main()
{

    int x1,y1,z1;
    printf("\n\n\n//////------------ WELCOME TO OUR PROJECT -------------/////\n\n\n");
    C:
     A3:
    printf("\n\n\n1. CRC-32 Implement\n\n");
    printf("\n\n2. Selective Reject Sliding Window Implement\n\n");
    printf("\n\n3. Exit\n\n");
    printf("Enter your option: ");
    scanf("%d",&x1);
    if(x1==1)
        goto A;
    else if(x1==2)
        goto B;
    else if (x1==3)
           {
            printf("\nExit ");
            goto A2;}
    else
       {
        printf("\nWrong Keyword!!! Please Enter The Correct One");
        goto C;}
{
    A:
    E:
    printf("\nEnter the digital data frame : ");
    scanf("%s",t);
    z1=strlen(t);

    for(y1=0;y1<z1;y1++)
    {
        if(t[y1]== '0' || t[y1]== '1')
            {

            }
            else
            {
               printf("unrecognized data. please enter correct digital");
               goto E;
            }
    }
    D:
    printf("\n----------------------------------------");
    printf("\nGenerating polynomial/divisor for CRC-32 bits : %s",g);
    a1=strlen(t);
    for(e1=a1;e1<a1+N-1;e1++)
        t[e1]='0';
    printf("\n----------------------------------------");
    printf("\nModified data frame is : %s",t);
    printf("\n----------------------------------------");
    crc();
    printf("\nChecksum is : %s",cs);
    for(e1=a1;e1<a1+N-1;e1++)
        t[e1]=cs[e1-a1];
    printf("\n----------------------------------------");
    printf("\nFinal codeword is : %s",t);
    printf("\n----------------------------------------");
    printf("\nTest error detection 0(yes) 1(no)? : ");
    scanf("%d",&e1);
    if(e1==0)
    {
        do{
            printf("\nEnter the position where error is to be inserted : ");
            scanf("%d",&e1);
        }while(e1==0 || e1>a1+N-1);
        t[e1-1]=(t[e1-1]=='0')?'1':'0';
        printf("\n----------------------------------------");
        printf("\nErroneous data : %s\n",t);
    }
    crc();
    for(e1=0;(e1<N-1) && (cs[e1]!='1');e1++);
        if(e1<N-1)
            printf("\nError detected\n\n");
        else
            printf("\nNo error detected\n\n");
            printf("\n----------------------------------------\n");
            goto A3;
}
B:
    {
        int b,c,w=2,i,j=0,k,l,f,g1,h,o;
    char s[700],x,a[500];
    printf("\nEnter the data of frame : ");
    scanf("%s",&s);
    b=strlen(s);

    for(j=0;j<b;j++)
    {
    printf("\nIs there any error?(y for yes & n for no)  ");
    scanf("%s",&x);

    if(x =='n')

{
     for(i=j;i<j+4;i++)
        {
       if(s[i]==NULL)

              {

              goto A1;
              }
         printf("\n frame %c send",s[i]);

        }

        printf("\nreceiver send ack %c ",s[i]);

        j=j+3;
}
     else if(x=='y')
    {
        printf("\nwhich frame is damaged ? ");
        scanf("%d",&c);
        for(k=j;k<j+c;k++)
        {
            if(s[k]==NULL)
                {
                    goto A1;
                }
          printf("\n frame %c send",s[k]);
}
        printf("\n receiver send %c nak",s[k-1]);
       for(l=k-1;l<k+3;l++)
    {
        if(s[l]==NULL)
             {
              goto A1;
              }
        printf("\n frame %c send",s[l]);

    }
    printf("\n receiver send %c ack ",s[l]);
   j=j+l-1;
    }

}
A1:
    printf("\n received ack %c ",s[b-1]);
    printf("\n End of transmission ");
    goto A3;
    }

A2:
        return 0;
}


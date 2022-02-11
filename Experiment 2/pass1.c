#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 3

int function()
{
    int i=0;
    char opcode[10],mnemonic[10],operand[10],label[10],code[10];
    int locctr=0,start,flag=0;
    FILE *fp1,*fp2,*fp3,*fp4;


fp1=fopen("INPUT1.txt","r");fp2=fopen("txx.txt","w");fp3=fopen("txxxx.txt","w");fp4=fopen("MOT.txt","r");


/////

int count_lines = 0;
char filechar[40], chr;

//extract character from file and store in chr
chr = getc(fp1);
while (chr != EOF)
{
    // printf("%c",chr);
    //Count whenever new line is encountered
    if (chr == '\n')
    {
        count_lines = count_lines + 1;
    }
    //take next character from file.
    chr = getc(fp1);
}
fclose(fp1); //close file.


/////
fp1=fopen("INPUT1.txt","r");


fscanf(fp1,"%s%s%s",label,opcode,operand);


if(strcmp(opcode,"START")==0)
{
    i+=1;
fprintf(fp3,"%s\t%s\t%s\n",label,opcode,operand);
fscanf(fp1,"%s%s%s",label,opcode,operand);

}
else
locctr=0;

while(strcmp(opcode,"END")!=0 )
{  
    fprintf(fp3,"%d\t",locctr);

    if(strcmp(label,"**")!=0)
    fprintf(fp2,"%s\t%d\n",label,locctr);
    fscanf(fp4,"%s",mnemonic);

    if(strcmp(opcode,"DC")==0)
    {locctr+=4;i+=1;}
    
    else if(strcmp(opcode,"DS")==0)
    {locctr+=4;i+=1;}
    
    else if(strcmp(opcode,"USING")==0)
    {
    locctr+=0;i+=1;
    }
    
    while(strcmp(mnemonic,"END")!=0)//A
        {
            if(strcmp(opcode,mnemonic)==0)
            {
                locctr+=4;
                flag=1;
                i+=1;
                break;
            }
            fscanf(fp4,"%s",mnemonic);
        }
    flag=0;
    fscanf(fp1,"%s%s%s",label,opcode,operand);
    rewind(fp4);
}

fclose(fp1);fclose(fp2);fclose(fp3);fclose(fp4);

remove("txxxx.txt");remove("txx.txt");




if(i==count_lines)
    return 1;
return 0;


}


void main()
{
    
int decision;
decision=function();


if(decision)

{
char opcode[10],mnemonic[10],operand[10],label[10],code[10];
int locctr=0,start,length,flag=0;
FILE *fp1,*fp2,*fp3,*fp4;

fp1=fopen("INPUT1.txt","r");
fp2=fopen("st.txt","w");
fp3=fopen("out.txt","w");
fp4=fopen("MOT.txt","r");

fscanf(fp1,"%s%s%s",label,opcode,operand);//next line mai jayega

if(strcmp(opcode,"START")==0)
{
fprintf(fp3,"%s\t%s\t%s\n",label,opcode,operand);
fscanf(fp1,"%s%s%s",label,opcode,operand);//line 2

}
else
locctr=0;

while(strcmp(opcode,"END")!=0 )
{  
    fprintf(fp3,"%d\t",locctr);//Location ctr is printed from line2

    if(strcmp(label,"**")!=0)
    fprintf(fp2,"%s\t%d\n",label,locctr);
    fscanf(fp4,"%s",mnemonic);
    
    

    if(strcmp(opcode,"DC")==0)
    locctr+=4;
    
    else if(strcmp(opcode,"DS")==0)
    locctr+=4;
    
    else if(strcmp(opcode,"USING")==0)
    {
    locctr+=0;
    }
    
    while(strcmp(mnemonic,"END")!=0)//A
        {
        printf("%s\t%s\n",opcode,mnemonic);



        if(strcmp(opcode,mnemonic)==0)
        {
        printf("\ninside the loop\n");
        locctr+=4;
        flag=1;
        break;
        }

        fscanf(fp4,"%s",mnemonic);//L,St,end
        }
    printf("%d\n",flag);
    flag=0;
    fprintf(fp3,"%s\t%s\t%s\n",label,opcode,operand);
    fscanf(fp1,"%s%s%s",label,opcode,operand);
    rewind(fp4);
}

fprintf(fp3,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
printf("\n The length of the program is %d",length);
fclose(fp1);
fclose(fp2);
fclose(fp3);
fclose(fp4);

}

else
{
    printf("Error opcode not  present in MOT table");
}
}
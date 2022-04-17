#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 //#include <stdlib.h>
 void main()
{
 char opcode[10],mnemonic[10],operand[10],label[10],code[10],opc[10],ope[10],l[10];
 int locctr=0,start,length,count=0;
 FILE *fp1,*fp2,*fp3,*fp4;
 
 fp1 = fopen("Input.txt", "r");
 fp2 = fopen("MNT.txt", "w");
 fp3 = fopen("MDT.txt", "w");
 fp4 = fopen("Expandedsourcecode.txt", "w");
 fscanf(fp1, "%s%s%s", label, opcode, operand);
 if (strcmp(opcode, "Macro") == 0)
 {
 fscanf(fp1, "%s", opcode);
 printf("%s", opcode);
 fprintf(fp3, "%s", opcode);

 }
 
 fprintf(fp4, "%s\t%s\t%s\n", label, opcode, operand);
 fclose(fp1);
 fclose(fp2);
 fclose(fp3);
 fclose(fp4);
}

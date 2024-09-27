#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int len(char* str)
{
    int cnt=0;
    while(str[cnt]!='\0')
    {
        cnt++;
    }
    return(cnt);
}
void stringow(char* base,char* new,int offset)
{
    int cnt = 0;
    while(new[cnt]!='\0')
    {
        base[cnt+offset]=new[cnt];
        cnt++;
    }
}
char* nextword(FILE* argf)
{

    char* cc = (char*)malloc(1);
    cc[0] = '\0';
    char cn = 1;
    int c = getc(argf);
    if(c == -1)
    {
    
        return(cc);
    }
    
    while(c == 32 || c == 9 || c == 10)
    {
        c = getc(argf);    
    }
    
    while(c != -1 && c != 32 && c != 9 && c != 10)
    {
        cn++;
        cc = (char*)realloc(cc,cn);
        
        cc[cn-2] = (char)c;
        cc[cn-1] = '\0';
        c = getc(argf);
    }
    return(cc);
}
void fileappend(FILE* fptr,char* input)
    {
    int iter = 0;
    while(input[iter]!='\0')
    {
        fprintf(fptr,"%c",input[iter]);
        iter++;
    }

    }
void meow(FILE* argf,FILE* fptr) 
{
    char* a = nextword(argf);
    char* b;
    switch(a[0])
        {
        case '0':
            b = "\0\0";
            break;
        case '1':
            b = "+ ";
            break;
        case '2':
            b = "- ";
            break;
        case '3':
            b = "* ";
            break;
        case '4':
            b = "/ ";
            break;
        case '5':
            b = "\% ";
            break;
        case '6':
            b = "**";
            break;
        }
    free(a);
    
    char* arg1 = nextword(argf);
    char* arg2 = nextword(argf);
    if(a == "\0\0")
    {
        char* line = malloc(len(arg1)+len(arg2)+4);
        stringow(line,arg1,0);
        line[len(arg1)] = '=';
        stringow(line,arg1,len(arg1)+1);
        line[len(arg1)+len(arg2)+1] = ';';
        line[len(arg1)+len(arg2)+1] = '\n';
        fileappend(fptr,line);
        free(line);
    }
    else
    {
        //probably useless
        //printf("%d",2*len(arg1)+len(arg2)+6);
        char* line = malloc(2*len(arg1)+len(arg2)+6);
        stringow(line,arg1,0);
        line[len(arg1)] = '=';
        stringow(line,arg1,len(arg1)+1);
        stringow(line,b,2*len(arg1)+1);
        stringow(line,arg2,2*len(arg1)+3);
        line[2*len(arg1)+len(arg2)+3] = ';';
        line[2*len(arg1)+len(arg2)+4] = '\n';
        line[2*len(arg1)+len(arg2)+4] = '\0';
        fileappend(fptr,line);
        free(line);
    }
    fileappend(fptr,"\n");
    free(arg1);
    free(arg2);

}
void mrow(FILE* argf,FILE* fptr)
{
    char* a = nextword(argf);
    char* b = nextword(argf);
    char bool = 0;
    int iter = 0;
    while(iter < len (a))
    {
        if(a[iter] == '*')
        {
            bool = 1;
        }
        iter++;
    }
    if(bool)
    {
        char* c = nextword(argf);
        char* d = (char*)malloc(2*sizeof(a)+sizeof(b)+sizeof(c)+14);
        sprintf(d,"%s %s = (%s)malloc(%s);\n",a,c,a,b);
        fileappend(fptr,d);
        free(c);
        free(d);
    }
    else 
    {
        char* d = (char*)malloc(sizeof(a)+sizeof(b)+2);
        sprintf(d,"%s %s;\n",a,b);
        fileappend (fptr,d);
        free(d);
    }
    free(a);
    free(b);
}
void miau(FILE* argf,FILE* fptr)
{
    char* a0 = nextword(argf);
    fileappend(fptr,a0);
    fileappend(fptr," ");
    free(a0);

    fileappend(fptr,"(");
    char* a1 = nextword(argf);
    int a1i = 0;
    int iter = 0;
    while(iter < len(a1))
    {
        a1i *= 10;
        switch(a1[iter])
        {
            case 48:
                break;
            case 49:
                a1i+=1;
                break;
            case 50:
                a1i+=2;
                break;
            case 51:
                a1i+=3;
                break;
            case 52:
                a1i+=4;
                break;
            case 53:
                a1i+=5;
                break;
            case 54:
                a1i+=6;
                break;
            case 55:
                a1i+=7;
                break;
            case 56:
                a1i+=8;
                break;
            case 57:
                a1i+=9;
                break;
        }
        iter++;
    }
    iter = 0;
    while(iter < a1i)
    {
        if(iter != 0)
        {
            fileappend(fptr,",");
        }
        char* aa1 = nextword(argf);
        char* aa2 = nextword(argf);
        fileappend(fptr,aa1);
        fileappend(fptr," ");
        fileappend(fptr,aa2);
        free(aa1);
        free(aa2);
    }
    fileappend(fptr,"){\n");
    free(a1);

}
void wrao(FILE* argf,FILE* fptr)
{
    char* a1 = nextword(argf);
    int a1i = 0;
    int iter = 0;
    while(iter < len(a1))
    {
        a1i *= 10;
        switch(a1[iter])
        {
            case 48:
                break;
            case 49:
                a1i+=1;
                break;
            case 50:
                a1i+=2;
                break;
            case 51:
                a1i+=3;
                break;
            case 52:
                a1i+=4;
                break;
            case 53:
                a1i+=5;
                break;
            case 54:
                a1i+=6;
                break;
            case 55:
                a1i+=7;
                break;
            case 56:
                a1i+=8;
                break;
            case 57:
                a1i+=9;
                break;
        }
        iter++;
    }
    iter = 0;
    while(iter < a1i)
    {
        if(iter != 0)
        {
            fileappend(fptr," ");
        }
        char* a2 = nextword(argf);

        fileappend(fptr,a2);
        free(a2);
        iter++;
    }
    free(a1);
    fileappend(fptr,"\n");
}
void main(int argc,char* argv[])
{
    if(argc==1)
    {

        exit(1);
    }
    FILE *fptr;
    fptr = fopen("out.c","w");
    FILE *argf;
    argf = fopen(argv[1],"r+");
    char eof=0;
    fileappend(fptr,"#include <stdio.h>\n");
    fileappend(fptr,"#include <stdlib.h>\n");
    while(!eof)
    {
        char* cc = nextword(argf);

        if(strcmp(cc,"meow") == 0)
        {
            meow(argf,fptr);
        }
        if(strcmp(cc,"prrr") == 0)
        {
            fileappend(fptr,"printf(");
            char* c1 = nextword(argf);
            fileappend(fptr,c1);
            free(c1);
            fileappend(fptr,");\n");
        }
        if(strcmp(cc,"mrow") == 0)
        {
            mrow(argf,fptr);
        }

        if(strcmp(cc,"") == 0)
        {
            eof = 1;
        }
        if(strcmp(cc,"miau") == 0)
        {
            miau(argf,fptr);
        }
        if(strcmp(cc,"mao") == 0)
        {
            fileappend(fptr,"}\n");
        }
        if(strcmp(cc,"mrawr") == 0)
        {
            char* a1 = nextword(argf);
            fileappend(fptr,"free(");
            fileappend(fptr,a1);
            fileappend(fptr,");\n");
            free(a1);
        }
        if(strcmp(cc,"awr") == 0)
        {
            char* a1 = nextword(argf);
            fileappend(fptr,"if(");
            fileappend(fptr,a1);
            fileappend(fptr,"){\n");
            free(a1);
        }
        if(strcmp(cc,"wao") == 0)
        {
            char* a1 = nextword(argf);
            fileappend(fptr,a1);
            fileappend(fptr,"\n");
            free(a1);
        }
        if(strcmp(cc,"wrao") == 0)
        {
            wrao(argf,fptr);

        }
        free(cc);
        /*
        cat sounds
        mrrr
        prr
        miu
        however tf you hiss
        */
       
    }
    fclose(fptr);
    fclose(argf);

}
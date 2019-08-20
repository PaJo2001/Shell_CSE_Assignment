#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/utsname.h>  
#include <unistd.h>  
#include <libgen.h>

int infiniteloop(int argc, char *argv[])
{
    struct utsname username;
    char user[64];
    char filepath[1000];
    char loc[1000];
    long long int tildasize,i;
    getlogin_r(user,sizeof(user)-1);
    uname(&username);
    realpath(argv[0],filepath);
    char *tilda = dirname(filepath);
    printf("%s\n",tilda);
    tildasize=strlen(tilda);
    
    while(1)
    {   
        getcwd(loc,sizeof(loc));
        printf("%s\n",loc);
        long long int locsize = strlen(loc);
        int flag=0;
        for(i=0;i<tildasize;i++)
        {
            if(loc[i]==tilda[i])
                flag=0;
            else
            {   
                flag=1;
                break;
            }
        }
        printf("%s@%s:",user,username.sysname);
        if(flag==0)
        {
            printf("~");
            for(i=tildasize;i<locsize;i++)
                printf("%c",loc[i]);
        }
        else
        {
            printf("%s",loc);
        }
        printf("> ");
        char *cmdline = (char*)malloc(1000*sizeof(char));
        char *tempcmdline= (char*)malloc(1000*sizeof(char));
        char *argument= (char*)malloc(1000*sizeof(char));
        long long int commandlength;
        long long int linelength,k=0;
        scanf(" %[^\t\n]s",cmdline);
        strcpy(tempcmdline,cmdline);
        linelength=strlen(cmdline);
        char *command = strtok(tempcmdline," ");
        commandlength=strlen(command);
        for(i=commandlength+1;i<linelength;i++)
        {    argument[i-commandlength-1]=cmdline[i];}
        //printf("%s, %s, %s",cmdline,command,argument);
    }
}
int main(int argc, char *argv[])
{
    infiniteloop(argc, argv);
}
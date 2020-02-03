#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char fileExt[9];
    char dirve[9];
    char fileNameWithoutExt[99];
    char filePath[99];
    char fDir[128] = {};
    char comText[255];
    char comTextFinall[255];
    int MAXPATH = 1024;
    char buffer[MAXPATH];
    _getcwd(buffer, MAXPATH);
    _splitpath(argv[1], dirve, filePath, fileNameWithoutExt, fileExt);
    strcat(fDir, dirve);
    strcat(fDir, filePath);
    if (*fileExt != 0)
    {
        /*
        printf("文件基本名：%s\n", fileNameWithoutExt);
        printf("文件类型是：%s\n", fileExt);
        printf("文件目录是：%s\n", fDir);
        */
        printf("文件路径：%s\n", argv[1]);
        //*/ 
        if (!strcmp(fileExt, ".txt"))
        {
            goto Unmatched;
        }
        if (!strcmp(fileExt, ".bat") || !strcmp(fileExt, ".cmd"))
        {
            sprintf(comText, "\"%s\"", argv[1]);
        }
        if (!strcmp(fileExt, ".py") || !strcmp(fileExt, ".pyw"))
        {
            sprintf(comText, "\"%s\"", argv[1]);
        }
        if (!strcmp(fileExt, ".ui"))
        {
            sprintf(comText, "pyuic5 \"%s\" -o \"%s.py\"", argv[1], fileNameWithoutExt);
        }
        if (!strcmp(fileExt, ".c"))
        {
            sprintf(comText, "gcc -fexec-charset=gbk \"%s\" -o \"%s\" && \"%s.exe\"", argv[1], fileNameWithoutExt, fileNameWithoutExt);
        }
        if (!strcmp(fileExt, ".cpp"))
        {
            sprintf(comText, "g++ -fexec-charset=gbk \"%s\" -o \"%s\" && \"%s.exe\"", argv[1], fileNameWithoutExt, fileNameWithoutExt);
        }
        if (!strcmp(fileExt, ".cs"))
        {
            sprintf(comText, "csc \"%s\" && \"%s\"", argv[1], fileNameWithoutExt);
        }
        if (!strcmp(fileExt, ".java"))
        {
            sprintf(comText, "javac -encoding UTF-8 \"%s\" && java \"%s\"", argv[1], fileNameWithoutExt);
        }
        if (!strcmp(fileExt, ".csproj"))
        {
            sprintf(comText, "dotnet run --project \"%s\"", argv[1]);
        }
        
    }
    else
    {
        printf("   ERROR：未匹配的当前文件类型，请检查输入！\n");
        strcpy(fDir, buffer);
        Unmatched:
        sprintf(comText, "echo %s", buffer);
    } 
    sprintf(comTextFinall, "cd /d \"%s\" && %s", fDir, comText);
    printf("当前路径：%s\n", fDir);
    printf("运行命令：%s\n", comText);
    printf("------------------------------------------------------------------\n");
    system(comTextFinall);
    printf("------------------------------------------------------------------\n");
    system("pause");

    return 0;
}
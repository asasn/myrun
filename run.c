#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char fileExt[9];
    char dirve[9];
    char fileNameWithoutExt[99];
    char filePath[99];
    char fFilename[128] = {};
    char comText[255];
    char comTextFinall[255];
    _splitpath(argv[1], dirve, filePath, fileNameWithoutExt, fileExt);
    strcat(fFilename, dirve);
    strcat(fFilename, filePath);
    if (*fileExt != 0)
    {
        /*
        printf("文件基本名：%s\n", fileNameWithoutExt);
        printf("文件类型是：%s\n", fileExt);
        printf("文件目录是：%s\n", fFilename);
        */
        printf("完整路径是：%s\n\n", argv[1]);
        //*/ 
        if (!strcmp(fileExt, ".txt"))
        {
            printf("现在打开的是.txt文件");
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
    }
    else
    {
        printf("未匹配的当前文件类型，请检查输入！\n");
        strcpy(comText, "chdir");
    } 
    sprintf(comTextFinall, "cd /d %s && %s", fFilename, comText);    
    printf("------------------------------------------------------------------\n");
    system(comTextFinall);
    printf("------------------------------------------------------------------\n");
    printf("%s\n", comText);
    system("pause");

    return 0;
}
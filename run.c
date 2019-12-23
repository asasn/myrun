#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int pushTo(int argc, char *temp[])
{
    int i;
    char comstr[255];
    for (i = 1; i < argc; i++)
    {

        strcat(comstr, temp[i]);
        strcat(comstr, " ");
    }
    printf("拼接的文字是：%s\n", comstr);
    system(comstr);
    return 0;
}

int main(int argc, char *argv[])
{
    //char *p = NULL;
    char fileExt[9];
    char dirve[9];
    char fileNameWithoutExt[99];
    char filePath[99];
    char fFilename[128] = "\0";
    char comstr[255] = "\0";
    _splitpath(argv[1], dirve, filePath, fileNameWithoutExt, fileExt);
    strcat(fFilename, dirve);
    strcat(fFilename, filePath);

    if (*fileExt != 0)
    {
        printf("文件基本名：%s\n", fileNameWithoutExt);
        printf("文件类型是：%s\n", fileExt);
        printf("文件路径是：%s\n", fFilename);
        printf("--------------------------------\n");
        if (strcmp(fileExt, ".txt") == 0)
        {
            printf("现在打开的是.txt文件");
        }
        if (strcmp(fileExt, ".py") == 0)
        {
            system(argv[1]);
        }
        if (strcmp(fileExt, ".c") == 0)
        {
            strcat(comstr, "gcc");
            strcat(comstr, " ");
            strcat(comstr, "-fexec-charset=gbk");
            strcat(comstr, " ");
            strcat(comstr, argv[1]);
            strcat(comstr, " ");
            strcat(comstr, "-o");
            strcat(comstr, " ");
            strcat(comstr, fileNameWithoutExt);
            strcat(comstr, " ");
            strcat(comstr, "&&");
            strcat(comstr, " ");
            strcat(comstr, fileNameWithoutExt);
            system(comstr);
        }
        if (strcmp(fileExt, ".cpp") == 0)
        {
            strcat(comstr, "g++");
            strcat(comstr, " ");
            strcat(comstr, "-fexec-charset=gbk");
            strcat(comstr, " ");
            strcat(comstr, argv[1]);
            strcat(comstr, " ");
            strcat(comstr, "-o");
            strcat(comstr, " ");
            strcat(comstr, fileNameWithoutExt);
            strcat(comstr, " ");
            strcat(comstr, "&&");
            strcat(comstr, " ");
            strcat(comstr, fileNameWithoutExt);
            system(comstr);
        }
    }
    else
    {
        printf("--------------------------------\n");
        printf("主要参数不符合规范，请检查输入！");
    }

    printf("\n--------------------------------\n");
    system("pause");
    
    return 0;
}
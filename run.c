#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char fileExt[9];
    char dirve[9];
    char fileNameWithoutExt[99];
    char filePath[99];
    char fFilename[128];
    char comstr[255];
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
        printf("完整路径是：%s\n", argv[1]);
        printf("---------------------------------\n");
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
        printf("---------------------------------\n");
        printf("未匹配的当前文件类型，请检查输入！");
        strcpy(comstr, "无命令");
    }

    printf("\n---------------------------------\n");
    printf("传入的命令是：%s\n\n", comstr);
    system("pause");

    return 0;
}
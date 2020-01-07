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
        printf("完整路径是：%s\n\n", argv[1]);
        strcat(comstr, "cd");
        strcat(comstr, " /d ");
        strcat(comstr, "\"");
        strcat(comstr, fFilename);
        strcat(comstr, "\"");
        printf("%s\n", comstr);
        system(comstr); //执行cd /d filepath
        memset(comstr, 0, sizeof(comstr));  //清空字符串
        //*/        
        if (strcmp(fileExt, ".txt") == 0)
        {
            printf("现在打开的是.txt文件");
        }
        if (strcmp(fileExt, ".bat") == 0 || strcmp(fileExt, ".cmd") == 0)
        {
            strcat(comstr, "\"");
            strcat(comstr, argv[1]);
            strcat(comstr, "\"");
        }
        if (strcmp(fileExt, ".py") == 0)
        {
            strcat(comstr, "\"");
            strcat(comstr, argv[1]);
            strcat(comstr, "\"");
        }
        if (strcmp(fileExt, ".ui") == 0)
        {
            strcat(comstr, "pyuic5 \"");
            strcat(comstr, argv[1]);
            strcat(comstr, "\" -o ");
            strcat(comstr, fileNameWithoutExt);
            strcat(comstr, ".py");
        }
        if (strcmp(fileExt, ".c") == 0)
        {
            strcat(comstr, "gcc -fexec-charset=gbk \"");
            strcat(comstr, argv[1]);
            strcat(comstr, "\" -o \"");
            strcat(comstr, fileNameWithoutExt);
            strcat(comstr, "\" && \"");
            strcat(comstr, fileNameWithoutExt);
            strcat(comstr, "\"");
        }
        if (strcmp(fileExt, ".cpp") == 0)
        {
            strcat(comstr, "g++ \"");
            strcat(comstr, argv[1]);
            strcat(comstr, "\" && ");
            strcat(comstr, fileNameWithoutExt);
        }
    }
    else
    {
        printf("未匹配的当前文件类型，请检查输入！\n");
        strcpy(comstr, "chdir");
    }
    printf("%s\n", comstr);
    printf("------------------------------------------------------------------\n");
    system(comstr);
    printf("------------------------------------------------------------------\n");
    system("pause");

    return 0;
}
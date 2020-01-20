这是一个调用命令行的程序，可用于各种编辑器的外部工具启动命令行<br>
用法：外部工具设置命令"x:\xxx\xxx\run.exe" "当前文件的完整路径"<br>
以上路径，视软件支持可使用参数变量，比如emeditor当中的$(Path)<br>
目前的支持列表（需环境变量支持，具体命令代码可在源代码中修改之后重新编译）：<br>
.txt<br>
.py<br>
.c<br>
.cpp<br>
.cs<br>
.csproj<br>
.java<br>
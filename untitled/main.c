#include <stdio.h>
#include <windows.h>

int main() {
    // 1. 获取当前编码
    UINT old_cp = GetConsoleOutputCP();
    printf("原编码: %u\n", old_cp);

    // 2. 强制设置为UTF-8
    BOOL success = SetConsoleOutputCP(65001);
    printf("设置结果: %s\n", success ? "成功" : "失败");
    printf("新编码: %u\n", GetConsoleOutputCP());

    // 3. 测试输出
    printf("================\n");
    printf("测试中文输出\n");

    int i = 123;
    printf("十进制: %d\n", i);
    printf("十六进制: %x\n", i);
    printf("================\n");

    return 0;
}
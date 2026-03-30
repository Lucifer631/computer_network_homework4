#include <stdio.h>

// 奇偶校验检验函数
int parity_check(const unsigned char *msg, const int msg_length)
{
    // 1. 统计消息中 1 的个数（非0视为1）
    int count = 0;
    for (int i = 0; i < msg_length; i++) {
        if (msg[i] != 0) {
            count++;
        }
    }

    // 2. 偶校验规则：1 的个数为偶数 → 校验通过
    //    奇数个1 → 校验失败
    if (count % 2 == 0) {
        return 1;  // 通过
    } else {
        return 0;  // 失败
    }
}

// ------------------- 测试主函数 -------------------
int main()
{
    // 测试用例1：偶校验正确（1的个数：4 → 偶数）
    unsigned char msg1[] = {0, 1, 0, 1, 0, 1, 0, 1};
    int len1 = sizeof(msg1) / sizeof(msg1[0]);
    printf("测试1结果：%d（1=通过）\n", parity_check(msg1, len1));

    // 测试用例2：偶校验错误（1的个数：3 → 奇数）
    unsigned char msg2[] = {0, 1, 0, 1, 0, 1, 0, 0};
    int len2 = sizeof(msg2) / sizeof(msg2[0]);
    printf("测试2结果：%d（0=失败）\n", parity_check(msg2, len2));

    return 0;
}

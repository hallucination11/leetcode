#1. 交替数字和

给你一个正整数 n 。n 中的每一位数字都会按下述规则分配一个符号：

最高有效位 上的数字分配到 正 号。
剩余每位上数字的符号都与其相邻数字相反。
返回所有数字及其对应符号的和。

示例 1：

输入：n = 521
输出：4
解释：(+5) + (-2) + (+1) = 4

示例 2：

输入：n = 111
输出：1
解释：(+1) + (-1) + (+1) = 1

class Solution {
public:
    int alternateDigitSum(int n) {
        std::vector<int> v;
        while(n > 0) {
            store = n % 10;
            v.push_back(store);
            n = n / 10;
        }
        int len = v.size(), fuhao = 1;
        for (int i = len - 1 ; i >= 0; i --) {
            v[i]  = v[i] * fuhao;
            fuhao = fuhao * (-1);
        }
        int result = 0;
        for (int i = 0 ; i < len; i ++) {
            result += v[i];
        }
        return result;
    }
};
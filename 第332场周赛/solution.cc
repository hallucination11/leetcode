# 1.回环句

句子 是由单个空格分隔的一组单词，且不含前导或尾随空格。

例如，"Hello World"、"HELLO"、"hello world hello world" 都是符合要求的句子。

单词 仅 由大写和小写英文字母组成。且大写和小写字母会视作不同字符。

如果句子满足下述全部条件，则认为它是一个 回环句 ：

	单词的最后一个字符和下一个单词的第一个字符相等。

	最后一个单词的最后一个字符和第一个单词的第一个字符相等。

例如，"leetcode exercises sound delightful"、"eetcode"、"leetcode eats soul" 都是回环句。

然而，"Leetcode is cool"、"happy Leetcode"、"Leetcode" 和 "I like Leetcode" 都 不 是回环句。

给你一个字符串 sentence ，请你判断它是不是一个回环句。如果是，返回 true ；否则，返回 false 。

class Solution(object):
    def isCircularSentence(self, sentence):
        """
        :type sentence: str
        :rtype: bool
        """
        words = sentence.split(' ')
        n = len(words)
        for i in range(n):
        	next = (i + 1) % n
        	if words[i][-1] != words[next][0]:
        		return false

        return true
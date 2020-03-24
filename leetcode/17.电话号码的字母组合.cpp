// @lc code=start
class Solution {
public:
    string digitsMember;
    string path;
    vector<string> table, res;

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        this->digitsMember = digits;

        table = vector<string> { "", 
            "", "abc","def",
            "ghi","jkl","mno",
            "pqrs","tuv","wxyz"};                   //知识点：初始化vector
        
        DFS(digits );

        return res;
    }

    void DFS(const string &digits)                  //错误：如果引用，这里要有const， error: cannot bind non-const lvalue reference
    {
        if(path.size() == digitsMember.size())
        {
            res.push_back( path );
            return;
        }

        string str = table[ digits[0] - '0'];       //获取一个数字对应的字母列表

        for( int i = 0; i < str.size(); ++i)        //小循环是这里for，大循环是递归
        {
            path.push_back( str[i]);

            DFS(digits.substr(1) );                 //digits.substr(1) ，从下标1之后到结束的字符串
            
            path.pop_back();
        }
    }

};

//队列
class Solution_BFS {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> res; 
		map<char, string> mp = { 
            {'2',"abc" },{'3',"def"},{'4',"ghi"},
            {'5',"jkl"},{'6',"mno"},{'7',"pqrs"},
            {'8',"tuv"},{'9',"wxyz"} };             //映射map哈希表

		queue<string> que;//新建队列
		
		for (int j = 0; j < mp[digits[0]].size(); j++)      //先将第一个元素对应的码表"abc"入队
		{
			string str;
			str.push_back(mp[digits[0]][j]);//char转string
			que.push(str);//string入队
		}

		for (int digitIdx = 1; digitIdx < digits.size(); digitIdx++)
		{
			for (int qLen = que.size(); qLen > 0; --qLen)
			{
				for (int charIdx = 0; charIdx < mp[digits[digitIdx]].size(); charIdx++)
				{
					string str = que.front() + mp[ digits[digitIdx] ][charIdx] ;          //队头元素加上新元素
					que.push(str);                                                          //入队
				}
				que.pop();//队头出队
			}
		}
		while (!que.empty())
		{
			res.push_back(que.front());//队头元素存储至res
			que.pop();//队头出队
		}
		return res;//返回
	}
};

// @lc code=end
/* 
https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/solution/cpp-hui-su-suan-fa-by-xu-zhou-geng/
 */


/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (52.48%)
 * Likes:    617
 * Dislikes: 0
 * Total Accepted:    89.4K
 * Total Submissions: 169.2K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 * 
 */

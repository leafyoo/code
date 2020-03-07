// @lc code=start
class Solution {
public:
string countOfAtoms(string formula) {
	map<string, int, less<string> > mp;                                //map的key恰好是递增的  //错误：less<string>多了()
	int outNum = 1;
	stack<int> st;

    //每次循环，处理：1.数值（元素下标或小括号下标）;  2.一个 "(" || 一个 ")" || 一个元素名字
	for (int i = formula.size() - 1; i >= 0; i--)           
	{
        //转换出一个连续数值,数值是每次循环都面对的问题
        int digitCharCnt = 0, nearNum = 1;
        for (; i >= 0 && isdigit(formula[i]); i--) 
            ++digitCharCnt;
        nearNum = ( digitCharCnt > 0 ) ? stoi( formula.substr(i+1, digitCharCnt) ) : 1;
		
        if (formula[i] == ')')              //这里和上面并不对立，不是 if  else的关系
		{
			outNum *= nearNum;
			st.push(nearNum);
		}
		else if (formula[i] == '(')
		{
			outNum /= st.top();
			st.pop();
		}
        else
        {
            //取出元素名字（含小写），【贪婪式】获取所有小写字母，非贪婪式获取一个大写。因为连续大写字母的情况属于多个原子
            int nameCharCnt = 0;
            for (; i >= 0 && islower( formula[i] ); i--)        
                ++nameCharCnt;
            if( isupper( formula[i] ) )
            {
                ++nameCharCnt;
                mp[ formula.substr(i, nameCharCnt) ] += outNum * nearNum;
            }
        }
	}
    
    //输出
	string res = "";
	for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++)
	{
		res += (it->first);
		if(it->second > 1)
			res += (to_string(it->second));
	}
	return res;
}
};

// @lc code=end
/*
fish:
注意区分 less<string>  、  less<int>() 

map<string, int, less<string> > mp; 
sort(coins.begin(), coins.end(), less<int>() 	);

*/


/*
 * @lc app=leetcode.cn id=726 lang=cpp
 *
 * [726] 原子的数量
 *
 * https://leetcode-cn.com/problems/number-of-atoms/description/
 *
 * algorithms
 * Hard (43.13%)
 * Likes:    47
 * Dislikes: 0
 * Total Accepted:    1.7K
 * Total Submissions: 4K
 * Testcase Example:  '"H2O"'
 *
 * 给定一个化学式formula（作为字符串），返回每种原子的数量。
 * 
 * 原子总是以一个大写字母开始，接着跟随0个或任意个小写字母，表示原子的名字。
 * 
 * 如果数量大于 1，原子后会跟着数字表示原子的数量。如果数量等于 1 则不会跟数字。例如，H2O 和 H2O2 是可行的，但 H1O2
 * 这个表达是不可行的。
 * 
 * 两个化学式连在一起是新的化学式。例如 H2O2He3Mg4 也是化学式。
 * 
 * 一个括号中的化学式和数字（可选择性添加）也是化学式。例如 (H2O2) 和 (H2O2)3 是化学式。
 * 
 * 给定一个化学式，输出所有原子的数量。格式为：第一个（按字典序）原子的名子，跟着它的数量（如果数量大于
 * 1），然后是第二个原子的名字（按字典序），跟着它的数量（如果数量大于 1），以此类推。
 * 
 * 示例 1:
 * 
 * 
 * 输入: 
 * formula = "H2O"
 * 输出: "H2O"
 * 解释: 
 * 原子的数量是 {'H': 2, 'O': 1}。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: 
 * formula = "Mg(OH)2"
 * 输出: "H2MgO2"
 * 解释: 
 * 原子的数量是 {'H': 2, 'Mg': 1, 'O': 2}。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: 
 * formula = "K4(ON(SO3)2)2"
 * 输出: "K4N2O14S4"
 * 解释: 
 * 原子的数量是 {'K': 4, 'N': 2, 'O': 14, 'S': 4}。
 * 
 * 
 * 注意:
 * 
 * 
 * 所有原子的第一个字母为大写，剩余字母都是小写。
 * formula的长度在[1, 1000]之间。
 * formula只包含字母、数字和圆括号，并且题目中给定的是合法的化学式。
 * 
 * 
 */

/*
class Solution {
public:
    string countOfAtoms(string formula) {
        string res;
        map<string, int, less<string>() > mp;

        int n = formula.size();
        for( int i = 0; i < n; )
        {
            int beg = i, cnt = 1;
            if( isupper(formula[i]) )
            {
                if(i+1 <= n && islower(formula[i+1]))
                {
                    ++i;
                    while(i < n && islower(formula[i]) ) ++i;
                }

                if(isdigit( formula[i] ))
                {
                    int begNum = i;
                    while(i < n && isdigit( formula[i] )) ++i;
                    cnt = stoi( formula.substr(begNum, i-begNum) );
                }
                string atom = formula.substr(beg, i-beg);
                mp[ atom ] += cnt;
            }

            if( formula[i] == )

        }
    }
};
*/
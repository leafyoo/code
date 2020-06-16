// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        if(path.empty() ) 
            return "/";

        stack<string> st;
        vector<string> vec;
        splitPath( path, vec);
        
        for( vector<string>::iterator it = vec.begin(); it != vec.end(); ++it)
        {
            string s = *it;
            if(s == ".." && !st.empty())
                st.pop();
            else if(s != "." && s != "" && s != "..")           //错误：这里依然要判断 s != ".."
                st.push(s);
        }

        string res;
        for( ; !st.empty();  )
        {
            res = "/" + st.top() + res;
            st.pop();
        }
        res = (res.empty() ? "/" : res);

        return res;
    }

    //切分路径为vector： home   ..   usr  local  这样，把 '/'扔掉
    void splitPath(string & path, vector<string> &vec)      
    {
        int n = path.size();
        for(int b = 1; b < n; )                     //错误：这里++b 导致逻辑混乱，还是尽量自己控制
        {
            int e = b;                                    //解释：i指向 非'/'字符
            
            while(e < n && path[e] != '/')      //解释：这里走完之后end指向 '/'
                ++e;      
            vec.push_back(path.substr(b, e-b));
            
            b = e+1;                                      //解释：end指向"/"，i指向非'/'字符
        }
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 *
 * https://leetcode-cn.com/problems/simplify-path/description/
 *
 * algorithms
 * Medium (38.75%)
 * Likes:    114
 * Dislikes: 0
 * Total Accepted:    28.2K
 * Total Submissions: 72.7K
 * Testcase Example:  '"/home/"'
 *
 * 以 Unix 风格给出一个文件的绝对路径，你需要简化它。或者换句话说，将其转换为规范路径。
 * 
 * 在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点 （..）
 * 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。更多信息请参阅：Linux / Unix中的绝对路径 vs 相对路径
 * 
 * 请注意，返回的规范路径必须始终以斜杠 / 开头，并且两个目录名之间必须只有一个斜杠 /。最后一个目录名（如果存在）不能以 /
 * 结尾。此外，规范路径必须是表示绝对路径的最短字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入："/home/"
 * 输出："/home"
 * 解释：注意，最后一个目录名后面没有斜杠。
 * 
 * 
 * 示例 2：
 * 
 * 输入："/../"
 * 输出："/"
 * 解释：从根目录向上一级是不可行的，因为根是你可以到达的最高级。
 * 
 * 
 * 示例 3：
 * 
 * 输入："/home//foo/"
 * 输出："/home/foo"
 * 解释：在规范路径中，多个连续斜杠需要用一个斜杠替换。
 * 
 * 
 * 示例 4：
 * 
 * 输入："/a/./b/../../c/"
 * 输出："/c"
 * 
 * 
 * 示例 5：
 * 
 * 输入："/a/../../b/../c//.//"
 * 输出："/c"
 * 
 * 
 * 示例 6：
 * 
 * 输入："/a//b////c/d//././/.."
 * 输出："/a/b/c"
 * 
 */

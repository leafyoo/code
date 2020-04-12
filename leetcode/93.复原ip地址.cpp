// @lc code=start
class Solution {
public:
    vector<string> res;             //错误：restoreIpAddresses函数内定义了同样一个 vector<string> res

    vector<string> restoreIpAddresses(string s) {
        int sLen = s.size();
        if(sLen < 4 || sLen > 12) return res;

        DFS(s, 0, "");

        return res;
    }

    void DFS(string tail, int segCnt, string ip)
    {
        if(tail.empty() || segCnt == 4)
        {
            if( tail.empty() && segCnt == 4 ) res.push_back(ip);
            return;
        }

        for( int partLen = 1; partLen <= 3; ++partLen)      //每个分节的长度
        {
            if( tail.size() < partLen || !checkOk( tail.substr(0, partLen)) ) break;            //剪枝

            string append = (segCnt == 3) ? tail.substr(0, partLen) :  (tail.substr(0, partLen) + ".");
            
            DFS(tail.substr(partLen), segCnt+1, ip + append);
        }
    }

    bool checkOk(string str)
    {
        return !(str.size() < 1 || str.size() > 3 
            || (stoi(str) > 255 || stoi(str) < 0 )          //知识点：stoi
            || (str.size() > 1 && str[0] == '0'));          //错误：这里 > 1写成了 ==1
    }
};
/*
https://leetcode-cn.com/problems/restore-ip-addresses/solution/cdi-gui-hui-su-jian-zhi-by-codave/

std::cout<< tail << "="<< segCnt << "=" << ip << "=" << "#" << std::endl;
std::cout<< partLen << "="<< tail.substr(partLen) << "=" << ip + append << "=" << "##" << std::endl;

 */

class Solution_force {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        int sLen = s.size();
        if(sLen < 4 || sLen > 12) return res;

        for( int i = 0; i < 3; ++i)
        {
            for( int j = 0; j < 3; ++j)
            {
                for( int m = 0; m < 3; ++m)
                {
                    for( int n = 0; n < 3 ;  ++n)
                    {
                        if(i+j+m+n+4 != sLen) 
                            continue;

                        string s1 = s.substr(0, i+1);
                        string s2 = s.substr(i+1, j+1);
                        string s3 = s.substr(i+j+2, m+1);
                        string s4 = s.substr(i+j+m+3, n+1);

                        if( checkOk(s1) && checkOk(s2) && checkOk(s3) && checkOk(s4) )
                            res.push_back( s1 + "." + s2 + "." + s3 + "." + s4);
                    }
                }
            }
        }

        return res;
    }

    bool checkOk(string str)
    {
        return !(str.size() < 1 || str.size() > 3 
            || (stoi(str) > 255 || stoi(str) < 0 ) 
            || (str.size() > 1 && str[0] == '0'));          //错误：这里 > 1写成了 ==1
    }

};
// @lc code=end
/* 
https://leetcode-cn.com/problems/restore-ip-addresses/solution/ke-neng-shi-zui-you-mei-de-bao-li-jie-fa-liao-by-u/

 */


/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 *
 * https://leetcode-cn.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (45.67%)
 * Likes:    209
 * Dislikes: 0
 * Total Accepted:    30.6K
 * Total Submissions: 66.4K
 * Testcase Example:  '"25525511135"'
 *
 * 给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
 * 
 * 示例:
 * 
 * 输入: "25525511135"
 * 输出: ["255.255.11.135", "255.255.111.35"]
 * 
 */


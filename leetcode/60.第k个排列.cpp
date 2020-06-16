// @lc code=start
class Solution {
private:
    vector<int> hash;
    vector<int> factorial;
    bool flag = true;
    void dfs(int cur, int n, int &k, string &ret, int &cnt, string path){
        if(cur == n){
            ret = path;
            flag = false;
            return;
        }
        int temp = factorial[n-cur-1];
        for(int i=0; i<n; i++){
            if(hash[i] && flag){
                if(temp < k ){
                    k = k - temp;
                    continue;
                }
                path.push_back(i+1+'0');
                hash[i] = 0;
                dfs(cur+1,n,k,ret,cnt,path);
                hash[i] = 1;
                path.pop_back();
            }
        }
    }

public:
    string getPermutation(int n, int k) {
        //calculate the factorial
        if(n == 1) return "1";
        factorial.resize(n);
        factorial[0] = 1;
        factorial[1] = 1;
        if(n > 2){
            for(int i=2; i<n; i++){
                factorial[i] = i * factorial[i-1];
            }
        }
        string ret;
        string path;
        hash.resize(n,1);
        int cnt = 0;
        dfs(0,n,k,ret,cnt,path);
        return ret;
    }
};

/* 
作者：edward_wang
链接：https://leetcode-cn.com/problems/permutation-sequence/solution/jian-ji-cppdfsjian-zhi-by-edward_wang/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。 */
// @lc code=end

/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 第k个排列
 *
 * https://leetcode-cn.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Medium (48.63%)
 * Likes:    240
 * Dislikes: 0
 * Total Accepted:    33.1K
 * Total Submissions: 68.1K
 * Testcase Example:  '3\n3'
 *
 * 给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。
 * 
 * 按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
 * 
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * 
 * 给定 n 和 k，返回第 k 个排列。
 * 
 * 说明：
 * 
 * 
 * 给定 n 的范围是 [1, 9]。
 * 给定 k 的范围是[1,  n!]。
 * 
 * 
 * 示例 1:
 * 
 * 输入: n = 3, k = 3
 * 输出: "213"
 * 
 * 
 * 示例 2:
 * 
 * 输入: n = 4, k = 9
 * 输出: "2314"
 * 
 * 
 */

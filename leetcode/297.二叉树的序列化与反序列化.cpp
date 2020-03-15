// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return string();

        string res;
        queue<TreeNode* > q;
        q.push(root);
        while( !q.empty() )
        {
            int cnt = q.size();
            for( int i = 0; i < cnt; ++i)
            {
                TreeNode* p = q.front();
                q.pop();
                if(!p)
                    res += "#,";                    //错误2：这里少了 ；号
                else
                {
                    res += to_string(p->val) + ",";
                    q.push( p->left );
                    q.push( p->right );
                }
            }
        }
        return res;
    }

    void toVec(string &str, vector<string> &vec)
    {
        for( int beg = 0; beg < str.size(); )
        {
            int end = str.find(',', beg);
            if(end == -1)
                break;
            vec.push_back( str.substr(beg, end-beg) );
            beg = end+1;
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vec;
        toVec( data, vec);
        if(vec.size() < 1) return nullptr;

        TreeNode * root = new TreeNode( stoi( vec[0] ) );       //先把root节点建好，赋值OK，下面针对left、righ来循环
        queue<TreeNode*> q;
        q.push(root);

        int pos = 1;                            //错误1： 这里pos是1，因为上面vec已经取了一个了。
        while( !q.empty() )
        {
            int cnt = q.size();
            for( int i = 0; i < cnt; ++i)           //处理每一层
            {
                TreeNode * p = q.front();
                q.pop();

                int idx = pos++;                    //step1：左子树创建节点、设置
                if(idx > vec.size() - 1) 
                    return root;
                if (  vec[ idx ] == "#" )
                    p->left = nullptr;
                else
                {
                    p->left = new TreeNode( stoi( vec[ idx ] ) );
                    q.push(p->left);
                }

                idx = pos++;                        //step2：右子树创建节点、设置
                if(idx > vec.size() - 1) 
                    return root;
                if (  vec[ idx ] == "#" )
                    p->right = nullptr;
                else
                {
                    p->right = new TreeNode( stoi( vec[ idx ] ) );
                    q.push(p->right);
                }
            }
        }

        return root;
    }
};
/* 
fish：此题的注意点，decode时，每次循环里，处理的是left、right，而不是root ！！！
encode时，循环里每次处理的是root。

 */


class Codec_recursion {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "#,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    //技巧，在递归里，pos是引用而不是值，这样就可以一直更新，而不必在下面主代码里+1(这样反而会不对了，通过不了)
    void create(TreeNode* &p, vector<string> &vec, int &pos)     //错误：TreeNode* 后面少了 & ，指针的副本，导致外部的root不能被修改
    {
        string str = vec[pos++];              //错误，pos++要放在这里，这样每次迭代取vec的值才都会偏移， 因为已经取了vec里的值
        if(str == "#" || pos > vec.size() - 1 )
            p = nullptr;
        else
        {
            int val = stoi( str );
            p = new TreeNode(val);
            create( p->left,    vec, pos);
            create( p->right,   vec, pos);
        }
    }

    void toVec(string str, vector<string> &vec)
    {
        for( int beg = 0; beg < str.size(); )
        {
            int end = str.find(',', beg);
            if(end == -1)
                break;
            vec.push_back( str.substr(beg, end-beg) );
            beg = end+1;
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vec;
        toVec( data, vec);

        TreeNode * root = nullptr;
        int pos = 0;
        create(root, vec, pos);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end

/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 *
 * https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (44.41%)
 * Likes:    145
 * Dislikes: 0
 * Total Accepted:    16.3K
 * Total Submissions: 36K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * 
 * 序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。
 * 
 * 请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 /
 * 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
 * 
 * 示例: 
 * 
 * 你可以将以下二叉树：
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠    / \
 * ⁠   4   5
 * 
 * 序列化为 "[1,2,3,null,null,4,5]"
 * 
 * 提示: 这与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode
 * 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。
 * 
 * 说明: 不要使用类的成员 / 全局 / 静态变量来存储状态，你的序列化和反序列化算法应该是无状态的。
 * 
 */

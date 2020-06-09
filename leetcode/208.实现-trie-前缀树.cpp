// @lc code=start
class Trie {
public:
    //对于数据成员，不必 struct Node{ ... } ，因为class Trie本身就是一个节点，内部的方法并不占用存储空间
    bool isStringEnd;           //当前结点是否为一个字符串的末尾
    Trie* next[26];             //存储指针的数组，26个Trie* 指针。里头存储着 char 这个字符所在的节点，并不是当前节点

    /** Initialize your data structure here. */
    Trie() 
    {
        isStringEnd = false;
        memset(next, 0, sizeof(next) );
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        if(word.empty())  return ;

        Trie* p = this;                                 //trie.insert("apple"); 这里使得指针（root） 指向 trie对象(this)的地址
        for( int i = 0; i < word.size(); ++i)
        {
            char c = word[i];
            if( !p->next[c - 'a'] )                     //【注意】根节点p = this 内部只是指向26个字母的开头，自身并不代表某个字母的地址，相当于空的根节点
                p->next[c - 'a'] = new Trie();
            p = p->next[c - 'a'] ;
        }

        p->isStringEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if(word.empty()) return true;

        Trie* p = this;                         // p 初始化为根结点指针
        int i = 0;
        for( ; i < word.size(); ++i)
        {
            char c = word[i] ;
            if(!p) 
                return false;

            p = p->next[c - 'a'];                               //有很多个指针，所以next要有下标
        }

        return (i == word.size() && p && p->isStringEnd );      //错误：这里少了 && p。上面的循环最后，p指向了最后一个字母的节点，所以这里还要判空
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if(prefix.empty()) return true;

        Trie* p = this;
        int i = 0;
        for( ; i < prefix.size(); ++i)
        {
            char c = prefix[i] ;
            if(!p) 
                return false;

            p = p->next[c - 'a'];
        }

        return (i == prefix.size() && p);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

/* 
fish：
//【注意】根节点p = this 内部只是指向26个字母的开头，自身并不代表某个字母的地址，相当于空的根节点，和其他的树不一样

Trie* obj = new Trie();
obj->insert(word);

this在这里就是方法的调用对象 obj

https://leetcode-cn.com/problems/implement-trie-prefix-tree/solution/cshi-xian-qian-zhui-shu-by-mxsyxin/
https://blog.csdn.net/johnny901114/article/details/80711441

 */


/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 *
 * https://leetcode-cn.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (64.49%)
 * Likes:    215
 * Dislikes: 0
 * Total Accepted:    26.4K
 * Total Submissions: 40.4K
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n' +
  '[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * 实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。
 * 
 * 示例:
 * 
 * Trie trie = new Trie();
 * 
 * trie.insert("apple");
 * trie.search("apple");   // 返回 true
 * trie.search("app");     // 返回 false
 * trie.startsWith("app"); // 返回 true
 * trie.insert("app");   
 * trie.search("app");     // 返回 true
 * 
 * 说明:
 * 
 * 
 * 你可以假设所有的输入都是由小写字母 a-z 构成的。
 * 保证所有输入均为非空字符串。
 * 
 * 
 */

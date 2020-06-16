// @lc code=start
struct Node {
    int n, t, k, v;     //n:count, t: time, k: key,  v:value

    Node(int _cnt, int _time, int _key, int _value) : 
        n(_cnt), t(_time), k(_key), v(_value) {}

    bool operator < (const Node& r) const 
    {
        return n == r.n ? t < r.t : n < r.n;
    }
};

class LFUCache 
{
public:
    int cap, t;
    set<Node> st;
    unordered_map<int, Node> mp;

    LFUCache(int capacity) 
    {
        cap = capacity;
        t = 0;

        st.clear();
        mp.clear();
    }
    
    int get(int k) 
    {
        auto it = mp.find(k);
        if (it == mp.end())             // 如果不存在，则返回-1
            return -1;

        // 存在的话，更新st中的cnt
        Node cache = it->second;
        st.erase(cache);
        cache.n++;
        cache.t = ++t;
        st.insert(cache);
        it->second = cache;

        return cache.v;
    }
    
    void put(int k, int v) 
    {
        if (cap == 0) 
            return;

        // 判断键是否存在
        auto it = mp.find(k);
        if (it == mp.end()) 
        {
            // 不存在,则先判断是否满容量了
            if (mp.size() == cap) 
            {
                // 容量满了,则先删除一个键，删除的键为S的begin指针指向的键
                int rmkey = st.begin()->k;
                st.erase(st.begin());
                mp.erase(rmkey);
            }

            // 插入一个键
            Node cache(1, ++t, k, v);
            // 插入st和key_table
            st.insert(cache);
            mp.insert(make_pair(k, cache));
        } 
        else 
        {
            // 存在，与get函数类似
            Node cache = it->second;

            st.erase(cache);
            cache.n++;
            cache.t = ++t;
            cache.v = v;
            st.insert(cache);
            it->second = cache;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(k);
 * obj->put(k,v);
 */
// @lc code=end


/* 作者：wo-yao-yi-tong-jiang-hu
链接：https://leetcode-cn.com/problems/lfu-cache/solution/460-lfuhuan-cun-bi-ji-by-wo-yao-yi-tong-jiang-hu/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。 


解题思路
在set中每个元素的值都唯一，而且系统能根据元素的值自动进行排序，内部采用的就是一种非常高效的平衡检索二叉树：红黑树
在c++中struct与class的语法除了默认的访问权限，其他没有区别
struct的构造函数Node(int _cnt, int _time, int _key, int _value) : n(_cnt), t(_time), k(_key), value(_value) {}
 
1. 容器缓存了节点，节点类要确保支持拷贝(否则出现浅拷贝问题，导致崩溃) 
2. 容器中的一般节点类，需要提供拷贝构造函数，并重载等号操作符(用来赋值) 
3. 容器在插入元素时，会自动进行元素的拷贝。

C++中类的拷贝有两种：深拷贝，浅拷贝：当出现类的等号赋值时，即会调用拷贝函数。在未定义显示拷贝构造函数的情况下，系统会调用默认的拷贝函数——即浅拷贝，它能够完成成员的一一复制。当数据成员中没有指针时，浅拷贝是可行的；但当数据成员中有指针时，如果采用简单的浅拷贝，则两类中的两个指针将指向同一个地址，当对象快结束时，会调用两次析构函数，而导致指针悬挂现象，所以，此时，必须采用深拷贝。

unordered_map（哈希表）需要定义hash_value函数并且重载operator==，无序；
使用时map（二叉搜索树）的key需要定义operator<，有序。
 

*/



/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU缓存
 *
 * https://leetcode-cn.com/problems/lfu-cache/description/
 *
 * algorithms
 * Hard (34.44%)
 * Likes:    203
 * Dislikes: 0
 * Total Accepted:    14K
 * Total Submissions: 33.5K
 * Testcase Example:  '["LFUCache","put","put","get","put","get","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[3],[4,4],[1],[3],[4]]'
 *
 * 请你为 最不经常使用（LFU）缓存算法设计并实现数据结构。它应该支持以下操作：get 和 put。
 * 
 * 
 * get(k) - 如果键存在于缓存中，则获取键的值（总是正数），否则返回 -1。
 * put(k, v) -
 * 如果键已存在，则变更其值；如果键不存在，请插入键值对。当缓存达到其容量时，则应该在插入新项之前，使最不经常使用的项无效。在此问题中，当存在平局（即两个或更多个键具有相同使用频率）时，应该去除最久未使用的键。
 * 
 * 
 * 「项的使用次数」就是自插入该项以来对其调用 get 和 put 函数的次数之和。使用次数会在对应项被移除后置为 0 。
 * 
 * 
 * 
 * 进阶：
 * 你是否可以在 O(1) 时间复杂度内执行两项操作？
 * 
 * 
 * 
 * 示例：
 * 
 * LFUCache cache = new LFUCache( 2  ); //  capacity (缓存容量) 
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // 返回 1
 * cache.put(3, 3);    // 去除 k 2
 * cache.get(2);       // 返回 -1 (未找到key 2)
 * cache.get(3);       // 返回 3
 * cache.put(4, 4);    // 去除 k 1
 * cache.get(1);       // 返回 -1 (未找到 k 1)
 * cache.get(3);       // 返回 3
 * cache.get(4);       // 返回 4
 * 
 */

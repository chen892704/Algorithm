# LCP 07. 传递信息
> 来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/chuan-di-xin-xi

小朋友 A 在和 ta 的小伙伴们玩传信息游戏，游戏规则如下：

- 有 n 名玩家，所有玩家编号分别为 0 ～ n-1，其中小朋友 A 的编号为 0
- 每个玩家都有固定的若干个可传信息的其他玩家（也可能没有）。传信息的关系是单向的（比如 A 可以向 B 传信息，但 B 不能向 A 传信息）。
- 每轮信息必须需要传递给另一个人，且信息可重复经过同一个人
- 给定总玩家数 n，以及按 [玩家编号,对应可传递玩家编号] 关系组成的二维数组 relation。返回信息从小 A (编号 0 ) 经过 k 轮传递到编号为 n-1 的小伙伴处的方案数；若不能到达，返回 0。


## 解题思路
### BFS
- 通过 map + set, 记录每个节点的下一跳集合
- bfs 跑 k 轮, 然后统计一共有多少达到终点的

## 代码实现
时间复杂度 O(m\*n), 空间复杂度 O(m\*n)
```cpp
class Solution {
public:
    int numWays(int n, vector<vector<int> >& relation, int k) {
        // map<当前玩家, 可传递的下家集合 >
        map<int, set<int> > mp;
        // 初始化
        for (int i=0; i<n; ++i) {
            mp[i] = {};
        }
        for (auto& ele : relation) {
            auto& nexts = mp[ele[0]];
            nexts.insert(ele[1]);
        }

        // bfs
        queue<int> q;
        q.push(0);
        int times = 0;
        while (times < k && !q.empty()) {
            int size = q.size();
            for (int i=0; i<size; ++i) {
                int cur = q.front();
                q.pop();
                auto& st = mp[cur];
                for (auto& next : st) {
                    q.push(next);
                }
            }
            ++times;
        }

        // 跑完 k 轮, 查看有几个达到终点的
        int ans = 0;
        while (!q.empty()) {
            if (q.front() == n-1)
                ++ans;
            q.pop();
        }
        return ans;
    }
};
```

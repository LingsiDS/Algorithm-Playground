//暴力法，dfs求得根节点到其他所有节点的距离，对每个节点dfs一次，时间复杂度O(n^2)，超时
class Solution {
public:
    bool visited[10010];
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        

        vector<vector<int>> table(N+1);
        for (auto e: edges) {//建立邻接表
            table[e[0]].push_back(e[1]);
            table[e[1]].push_back(e[0]);
        }
        vector<int> res(N, 0);
        for (int i = 0; i < N; i++) {
            int cnt = 0, dist = 0;
            memset(visited, 0, sizeof(visited));
            dfs(i, table, dist, cnt);
            res[i] = dist;
            //cout << cnt << ' ' << dist;
        }
        return res;
    }

    void dfs(int rt, vector<vector<int>>& table, int &dist, int &cnt) {
        if (table[rt].size() == 0) {//叶子节点
            //dist += 1;
            cnt += 1;
            return;
        }
        visited[rt] = 1;
        for (int i = 0; i < table[rt].size(); i++) {
            if (visited[table[rt][i]]) continue;
            int sub = 0;//table[rt][i]这一棵子树的节点数
            dfs(table[rt][i], table, dist, sub);
            dist += sub;//当前节点距其他节点的距离为加上每一子树的节点数
            cnt += sub; //维护cnt返回给上一层使用， cnt是当前根节点rt的所有子树中节点的数量和
        }
        cnt++;//加上当前节点
    }
};




//树形dp，时空复杂度O(n),思路参考官方题解
//https://leetcode-cn.com/problems/sum-of-distances-in-tree/solution/shu-zhong-ju-chi-zhi-he-by-leetcode-solution/
class Solution {
public:
    bool visited[10010];
    vector<int> ans;//ans[i]表示以i为根节点，其他所有节点到该节点的距离之和
    vector<int> dp;//dp[i]表示以i为根节点，以i构成的子树中其他节点到该节点的距离之和
    vector<int> sz;//sz[i]表示以i为根节点的子树中所有儿子的数量
    vector<vector<int>> table;//邻接表

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        dp.resize(N, 0);
        sz.resize(N, 0);
        ans.resize(N, 0);
        table.resize(N, {});

        for (auto e: edges) {//建立邻接表
            table[e[0]].push_back(e[1]);
            table[e[1]].push_back(e[0]);
        }
        
        memset(visited, 0, sizeof visited);
        dfs(0);
        memset(visited, 0, sizeof visited); 
        dfs2(0);

        return ans;
    }

    void dfs(int rt) {
        visited[rt] = 1;
        dp[rt] = 0;//初始化距离为0
        sz[rt] = 1;//初始化当前子树节点数量，至少包含当前节点，初始化为1
        for (int i = 0; i < table[rt].size(); i++) {
            int child = table[rt][i];
            if (visited[child]) continue;
            dfs(child);
            sz[rt] += sz[child];            //所有的数量等于所有子树中节点数量之和
            dp[rt] += dp[child] + sz[child];//到当前根节点的距离等于到子节点的距离加上以子节点为根的树中节点的数量
        }
    }

    void dfs2(int rt) {//更换根节点
        visited[rt] = 1;
        ans[rt] = dp[rt];//dp[i]表示以rt为根其他节点到该节点的距离
        for (auto child: table[rt]) {
            if (visited[child]) continue;
            int root1 = dp[rt], root2 = sz[rt];
            int son1 = dp[child], son2 = sz[child];
            
            

            //child作为根节点，rt作为子节点
            dp[rt] = dp[rt] - dp[child] - sz[child];
            sz[rt] = sz[rt] - sz[child];

            dp[child] = dp[child] + dp[rt] + sz[rt];
            sz[child] = sz[child] + sz[rt];
            
            //递归换根
            dfs2(child);
            
            //回溯，还原信息，方便对下一个子树进行换根操作
            dp[rt] = root1;
            sz[rt] = root2;
            dp[child] = son1;
            sz[child] = son2;
        }
    }
};
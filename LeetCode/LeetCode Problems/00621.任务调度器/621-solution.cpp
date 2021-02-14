//贪心思路：因为相同的任务之间要间隔时间n，所以在“一轮”中应该先让任务次数最多的任务先执行，然后让任务出现次数第二多的任务执行...，
//直到让任务出现次数第n + 1多的任务执行，期间如果没有任务了，则该时刻为待命状态
//设tasks的长度为m，则时间复杂度为O(m*n*log26)，空间复杂度为O(26)，这里的26是大写字符集的大小
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int, char>, vector<pair<int, char>>, less<pair<int, char>>> pq;
        vector<int> cnt(26, 0);
        
        int num = 0;
        for (auto c: tasks) {//统计所有字符出现的次数
            cnt[c - 'A']++;
            num++;
        }
        for (int i = 0; i < cnt.size(); i++) {
            if (cnt[i])
                pq.push({cnt[i], i + 'A'});//将{出现次数， 字符}入队，pq中最多有26个字符
        }

        string res;
        while (num) {//O(tasks)
            queue<pair<int, char>> q;

            //贪心：按出现次数从高到低，依次放入n+1个字符，n+1是因为放了一个字符后，再放n个不重复的，然后再放出现次数最多的
            for (int i = 0; i <= n; i++) {//O(n)
                if (pq.size()) {
                    res.push_back(pq.top().second);//放入res中
                    if (pq.top().first - 1 != 0)
                        q.push({pq.top().first - 1, pq.top().second});//暂时放入队列中，下一轮继续放入堆中
                    pq.pop();//O(log(26))
                    num--;
                } else if (num) res.push_back('x');//如果还有字符，且堆内元素在当前这一轮以及用完，则放入空字符
            }
            while (q.size()) {//将队列里的所有元素放入堆中
                pq.push(q.front());
                q.pop();
            }
        }
        return res.size();
    }
};


//数学
//时间复杂度O(m)
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        for (auto c: tasks) cnt[c - 'A']++;//统计所有字符的出现次数
        auto maxFre = *max_element(cnt.begin(), cnt.end());//出现频率最大的字符
        int equalMaxFre = 0;
        for (auto a: cnt) 
            if (a == maxFre) equalMaxFre++;//所有出现频率为maxFre的字符个数
        return max((maxFre - 1) * (n + 1) + equalMaxFre, (int)tasks.size()); //tasks.size()表示不需要填充空字符
    }
};
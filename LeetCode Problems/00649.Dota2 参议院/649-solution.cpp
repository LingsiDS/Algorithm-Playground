//时间复杂度O(n), 空间复杂度O(n)
//循环队列+贪心
//假设遇到一名R阵营的议员，它应该优先禁止其后面第一个D阵营的议员的投票权利，如果不这样做，其后第一个D阵营的议员
//将会使得一名R阵营的议员失去投票权利，如果R阵营议员后面没有D阵营的议员，那么应该将从头开始第一个D阵营的议员的权利禁止

class Solution {
public:
    string predictPartyVictory(string senate) {
        deque<char> dq;//循环队列，保存还有权利的议员
        int totR = 0, totD = 0;//表示两个阵营的总人数
        for (auto a: senate) {
            dq.push_back(a);
            if (a == 'R') totR++;
            else totD++;
        }
        int delR = 0, delD = 0;//delR, delD分别表示需要紧张Radiant和Dire阵营的人数
        while (totD && totR) {
            auto top = dq.front();
            dq.pop_front();
            if (top == 'R' && delR) {//当前元素为R,并且需要还存在需要紧张R阵营的名额
                delR--;
                totR--;//禁止一名R阵营的议员
                continue;
            }
            if (top == 'D' && delD) {
                delD--;
                totD--;//禁止一名D阵营的议员
                continue;
            }
            
            if (top == 'R') delD++;//禁止敌对阵营的人员
            else delR++;
            dq.push_back(top);//重新加入循环队列
        }
        return totD == 0 ? "Radiant" : "Dire";
    }
};
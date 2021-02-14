class Solution {
public:
    string maximumTime(string time) {
        for (int i = 0; i < time.size(); i++) {
            if (time[i] == '?' && i == 0) {
                if (time[i + 1] == '?') {
                    time[i] = '2';
                    time[i + 1] = '3';
                    i++;
                    continue;
                }
                if (time[i + 1] < '4')
                    time[i] = '2';
                else time[i] = '1';
            }
            if (time[i] == '?' && i == 1) {
                if (time[i - 1] == '2')
                    time[i] = '3';
                else if (time[i - 1] == '1')
                    time[i] = '9';
                else time[i] = '9';
            }
            if (time[i] == '?' && i == 3) {
                time[i] = '5';
            }
            if (time[i] == '?' && i == 4) {
                time[i] = '9';
            }
        }
        return time;
    }
};
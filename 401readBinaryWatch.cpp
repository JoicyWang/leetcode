class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        if (num == 0) return {"0:00"};
        vector<int> hour{8, 4, 2, 1}, minute{32, 16, 8, 4, 2, 1};
        for (int i = 0; i <= num; i++) {
            vector<int> hours = gen(hour, i);
            vector<int> minutes = gen(minute, num - i);
            for (int h : hours) {
                if (h > 11) continue;
                for (int m : minutes) {
                    if (m > 59) continue;
                    res.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
                }
            }
        }
        return res;
    }
private:
    vector<int> gen(vector<int>& nums, int cnt) {
        vector<int> res;
        helper(nums, cnt, 0, 0, res);
        return res;
    }
    void helper(vector<int>& nums, int cnt, int pos, int out, vector<int>& res) {
        if (cnt == 0) {
            res.push_back(out);
            return;
        }
        for (int i = pos; i < nums.size(); i++) {
            helper(nums, cnt - 1, i + 1, out + nums[i], res);
        }
    }
};
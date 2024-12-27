
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int score = INT_MIN;
        int mx = values[0] + 0;
        for (int j = 1; j < values.size(); j++) {
            score = max(score, mx + values[j] - j);
            mx = max(mx, values[j] + j);
        }
        return score;
    }
};


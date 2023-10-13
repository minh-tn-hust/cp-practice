class Solution {
public:
    static bool compareEndTime(const vector<int> &eventA, const vector<int> &eventB) {
        return eventA[1] < eventB[1];
    }

    bool isPrevEventEnd(vector<int> &eventPrev, vector<int> &curEvent) {
        return eventPrev[1] < curEvent[1];
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), compareEndTime);
        
        int eventSize = events.size();
        vector<int> dp(eventSize + 1, 0);
        vector<int> eventCount(eventSize + 1, 0);

        for (int i = 0; i < eventSize; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (isPrevEventEnd(events[j], events[i]) && eventCount[j] < k) {
                    if (dp[i] < dp[j] + events[i][2]) {
                        eventCount[i] = eventCount[j] + 1;
                        dp[i] = dp[j] + events[i][2];
                    }
                }
            }
            if (dp[i] < events[i][2]) {
                dp[i] = events[i][2];
                eventCount[i] = 1;
            }
        }

        int maxValue = INT_MIN;
        for (int i = 0; i < eventSize; i++) {
            maxValue = max(maxValue, dp[i]);
        }

        return maxValue;
    }
};
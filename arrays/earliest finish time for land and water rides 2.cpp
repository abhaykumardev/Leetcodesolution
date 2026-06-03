class Solution {
public:
    struct Helper {
        vector<int> start;
        vector<long long> prefMinDur;
        vector<long long> suffMinFinish;

        Helper(vector<int>& s, vector<int>& d) {
            int n = s.size();

            vector<pair<int,int>> rides;
            for (int i = 0; i < n; i++) {
                rides.push_back({s[i], d[i]});
            }

            sort(rides.begin(), rides.end());

            start.resize(n);
            prefMinDur.resize(n);
            suffMinFinish.resize(n);

            for (int i = 0; i < n; i++) {
                start[i] = rides[i].first;
            }

            prefMinDur[0] = rides[0].second;
            for (int i = 1; i < n; i++) {
                prefMinDur[i] = min(prefMinDur[i - 1],
                                    (long long)rides[i].second);
            }

            suffMinFinish[n - 1] =
                (long long)rides[n - 1].first + rides[n - 1].second;

            for (int i = n - 2; i >= 0; i--) {
                suffMinFinish[i] = min(
                    suffMinFinish[i + 1],
                    (long long)rides[i].first + rides[i].second
                );
            }
        }

        long long query(long long t) {
            int pos = upper_bound(start.begin(), start.end(), t) - start.begin();

            long long ans = LLONG_MAX;

            // rides with start <= t
            if (pos > 0) {
                ans = min(ans, t + prefMinDur[pos - 1]);
            }

            // rides with start > t
            if (pos < (int)start.size()) {
                ans = min(ans, suffMinFinish[pos]);
            }

            return ans;
        }
    };

    long long earliestFinishTime(vector<int>& landStartTime,
                                 vector<int>& landDuration,
                                 vector<int>& waterStartTime,
                                 vector<int>& waterDuration) {

        Helper water(waterStartTime, waterDuration);
        Helper land(landStartTime, landDuration);

        long long ans = LLONG_MAX;

        // land -> water
        for (int i = 0; i < landStartTime.size(); i++) {
            long long landEnd =
                (long long)landStartTime[i] + landDuration[i];

            ans = min(ans, water.query(landEnd));
        }

        // water -> land
        for (int j = 0; j < waterStartTime.size(); j++) {
            long long waterEnd =
                (long long)waterStartTime[j] + waterDuration[j];

            ans = min(ans, land.query(waterEnd));
        }

        return ans;
    }
};


//leetcode 3635

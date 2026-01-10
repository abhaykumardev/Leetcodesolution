class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;  // endWord must be in dictionary

        queue<string> q;
        q.push(beginWord);

        unordered_set<string> visited;
        visited.insert(beginWord);

        int level = 1; // first step includes beginWord

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                string word = q.front();
                q.pop();

                if (word == endWord) return level;

                for (int i = 0; i < word.size(); i++) {
                    char original = word[i];

                    // Try all 26 letters at this position
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == original) continue;

                        word[i] = c;

                        if (dict.count(word) && !visited.count(word)) {
                            visited.insert(word);
                            q.push(word);
                        }
                    }

                    word[i] = original;
                }
            }

            level++;
        }

        return 0;
    }
};
//leetcode 127. Word Ladder
//problem link:
https://leetcode.com/problems/word-ladder/description/
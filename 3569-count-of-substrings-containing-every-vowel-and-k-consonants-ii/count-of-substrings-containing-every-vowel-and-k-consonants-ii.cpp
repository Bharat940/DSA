class Solution {
public:
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        } else {
            return false;
        }
    }

    long long atLeastK(string& word, int k) {
        long long validCount = 0;
        int n = word.length(), left = 0, right = 0, consonantCount = 0;
        unordered_map<char, int> vowelFreq;

        while (right < n) {
            if (isVowel(word[right])) {
                vowelFreq[word[right]]++;
            } else {
                consonantCount++;
            }

            while (vowelFreq.size() == 5 && consonantCount >= k) {
                validCount += n - right;
                if (isVowel(word[left])) {
                    if (--vowelFreq[word[left]] == 0) {
                        vowelFreq.erase(word[left]);
                    }
                } else {
                    consonantCount--;
                }
                left++;
            }
            right++;
        }
        return validCount;
    }

    long long countOfSubstrings(string word, int k) {
        return atLeastK(word, k) - atLeastK(word, k + 1);
    }
};
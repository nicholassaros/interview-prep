class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int wordPtr = 0;
        int abbrPtr = 0;

        while (abbrPtr < static_cast<int>(abbr.size())) {
            if (std::isdigit(static_cast<unsigned char>(abbr[abbrPtr]))) {
                // Leading zero is not allowed.
                if (abbr[abbrPtr] == '0') {
                    return false;
                }

                int skip = 0;

                while (
                    abbrPtr < static_cast<int>(abbr.size()) &&
                    std::isdigit(static_cast<unsigned char>(abbr[abbrPtr]))
                ) {
                    skip = skip * 10 + (abbr[abbrPtr] - '0');
                    abbrPtr++;
                }

                wordPtr += skip;

                if (wordPtr > static_cast<int>(word.size())) {
                    return false;
                }
            } else {
                if (
                    wordPtr >= static_cast<int>(word.size()) ||
                    word[wordPtr] != abbr[abbrPtr]
                ) {
                    return false;
                }

                wordPtr++;
                abbrPtr++;
            }
        }

        return wordPtr == static_cast<int>(word.size());
    }
};
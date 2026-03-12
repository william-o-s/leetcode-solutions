class Solution {
public:
    string intToRoman(int num) {
        // looks like a simulation question
        // recursive function
        // assume num is what remains to be converted to a Roman Numeral

        if (num <= 0) {
            return string{""};
        }

        // subtractive forms starting with 4 or 9
        if (num == 4) {
            return string{"IV"};
        }
        if (num == 9) {
            return string{"IX"};
        }
        if (num >= 40 and num < 50) {
            return string{"XL"} + intToRoman(num - 40);
        }
        if (num >= 90 and num < 100) {
            return string{"XC"} + intToRoman(num - 90);
        }
        if (num >= 400 and num < 500) {
            return string{"CD"} + intToRoman(num - 400);
        }
        if (num >= 900 and num < 1000) {
            return string{"CM"} + intToRoman(num - 900);
        }

        auto values = map<int, string>{};
        values.emplace(1, string{"I"});
        values.emplace(5, string{"V"});
        values.emplace(10, string{"X"});
        values.emplace(50, string{"L"});
        values.emplace(100, string{"C"});
        values.emplace(500, string{"D"});
        values.emplace(1000, string{"M"});

        // eg.g. 123
        // we need the last value s.t. v <= num
        // it's one before first v s.t. v > num -> upper bound - 1
        // select highest value symbol that can be subtracted from the input. i.e. first S s.t. num > S
        auto hi = values.upper_bound(num);
        --hi;

        // otherwise
            // use a set to make this a bit easier
                // subtract its value
                // append S
                // subtract num - S
                // then convert the rest to roman numeral
        return hi->second + intToRoman(num - hi->first);
    }
};

class Solution {
public:
    // set as null if the number is too small to have a certain base
    // the pointers should all be set to null to begin with
    void find_bases(int number, optional<int>& thousands, optional<int>& hundreds, optional<int>& tens, optional<int>& ones) {
        if (number >= 1000) {
            thousands = number / 1000;
        }
        if (number >= 100) {
            hundreds = (number % 1000) / 100;
        }
        if (number >= 10) {
            tens = (number % 100) / 10;
        }
        ones = number % 10;
    }

    int one_digit_number_to_char(int number) {
        return '0' + number;
    }

    // return the new spot where writing should begin
    auto write_compression(size_t start, char curr, int count, vector<char>& chars) -> size_t {
        // write the letter
        chars.at(start++) = curr;

        if (count == 1) {
            return start;
        }

        // use optional for this
        auto thousands = optional<int>{nullopt};
        auto hundreds = optional<int>{nullopt};
        auto tens = optional<int>{nullopt};
        auto ones = optional<int>{nullopt};
        find_bases(count, thousands, hundreds, tens, ones);
        // write the 1000s
        if (thousands) {
            chars.at(start++) = one_digit_number_to_char(*thousands);
        }
        // write the 100s
        if (hundreds) {
            chars.at(start++) = one_digit_number_to_char(*hundreds);
        }
        // write the 10s
        if (tens) {
            chars.at(start++) = one_digit_number_to_char(*tens);
        }
        // write the 1s
        if (ones) {
            chars.at(start++) = one_digit_number_to_char(*ones);
        }

        return start;
    }

    int compress(vector<char>& chars) {
        // the first letter is always the first thing in the compression
        // string cannot be empty
        char curr = *chars.begin();
        int count = 1;
        size_t start = 0ULL;

        // need to use an index-based for loop to modify in-place
        for (size_t i = 1ULL; i < chars.size(); ++i) {
            auto c = chars.at(i);

            // same letter as before
            if (c == curr) {
                ++count;
                continue;
            }

            // new letter -> need to write
            start = write_compression(start, curr, count, chars);

            // reset curr
            curr = c;
            // reset count
            count = 1;
        }

        // must run on the last group
        return static_cast<int>(write_compression(start, curr, count, chars));
    }
};

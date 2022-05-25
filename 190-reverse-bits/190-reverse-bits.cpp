class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string s = bitset<32>(n).to_string();
        reverse(s.begin(), s.end());
        bitset<32> num(s);
        return num.to_ulong();
    }
};
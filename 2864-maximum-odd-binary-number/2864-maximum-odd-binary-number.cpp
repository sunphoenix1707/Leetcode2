class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones=0,zeroes=0,len=s.size();
        for(auto c:s) ones+=(c-'0');
        zeroes=len-ones;
        string l="";
        for(int i=0;i<ones-1;i++) 
            l.push_back('1');
        for(int i=0;i<zeroes;i++)
            l.push_back('0');
        l.push_back('1');
        return l;
    }
};
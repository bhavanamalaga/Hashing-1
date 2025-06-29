//timecomplexity - O(n), n is the length of the strings
//space complexity - O(1); two hash map sizes will be of 26, 26 charactors only so constant space

//approach : take two hash maps one maps charactors of s to chars of t and checks if one char of s is mapped to two different charactors of t 
//another map is to amp char of t to char of s and check if whether two different chars of s is mapped to same char of t 

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()){ // if length of string are not equal they are not isomorphic
            return false;
        }
        unordered_map<char, char>s_t; //hashmap from string s to t
        unordered_map<char, char>t_s; //hashmap from sting t to s 
        for(int i = 0; i < s.length(); i++){
            char schar = s[i]; //storing the characters of two strings
            char tchar = t[i];

            //checking if a character is present in s_t map and its key is not equal to corresponding t_char
            if(s_t.count(schar) && (s_t[schar] != tchar)){
                return false;
            }
            //simiarly check for t_s map also
            if(t_s.count(tchar) && (t_s[tchar] != schar)){
                return false;
            }


            //adding new mapping
            s_t[schar] = tchar; //mapping schar, tchar in s_t map
            t_s[tchar] = schar; // mapping t_char, s_char in t_s map       
        }
        return true;        
    }

};

//time complexity  - O(n) - for coonverting string of words to word 
// space complexity - O(1) as maximum of different lettwers in a pattern is 26 

//approach is same as isomorphic strings 
//maintaing two hashmaps


class Solution {
public:
    bool wordPattern(string pattern, string s) {

        istringstream iss(s);
        vector<string> words;
        string word;
        while(iss >> word){
            words.push_back(word);
        }
        
        if(words.size() != pattern.size()){ // if length of words are not equal to pattern
            return false;
        }
        unordered_map<char, string>pattern_words; //hashmap from string s to t
        unordered_map<string, char>words_pattern; //hashmap from sting t to s 

        for(int i = 0; i < pattern.size(); i++){
            char pattern_char = pattern[i]; //storing the characters of two strings
            string w = words[i];

           
            if(pattern_words.count(pattern_char) && (pattern_words[pattern_char] != w)){
                return false;
            }
            
            if(words_pattern.count(w) && (words_pattern[w] != pattern_char)){
                return false;
            }


            //adding new mapping
            pattern_words[pattern_char] = w;
            words_pattern[w] = pattern_char;       
        }
        return true;  
    }
};


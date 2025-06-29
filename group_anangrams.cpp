//timecomplexity - O(n*klog(k)) - n is the no of words, and k-is the max no of charactors in a word
//for sorting a word it requires klogk and as theier are n words total complexity is n*k*logk
//space complexity  = n*k storing all words at worst case when each word is a seperate anagram

//approach :
//create a hash map with key as the sorted string and value is the vector of strings with same key
//for each string in strs make key as string and sort it
//result is for (auto& pair : in map)result.push_back(pair.second)
//result is vector of vector of strings.


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagram_map; 
        for(const string& s: strs){ // for all strings in str  
            string key = s;
            sort(key.begin(), key.end()); //sort the string             
            anagram_map[key].push_back(s); // group using sorted string 
        }

        vector<vector<string>> result;
        for(auto& pair : anagram_map){ // for all pairs in hash map
            result.push_back(pair.second); //push the second value of the pair to the result vector 
        }
        return result;
    }
};

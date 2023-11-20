#include<iostream>
#include<vector>
#include<string>

class Patterns {
	public: bool compare(std::string s1, std::string s2) {
    if (s1.size() != s2.size()) return false;
    for (int i = 0; i < s1.size(); i++) {
      for (int j = 0; j < s1.size(); j++) {
        if (s2[i] == s2[j] && s1[i] != s1[j]) {
          return false;
        } else if (s2[i] != s2[j] && s1[i] == s1[j]) {
          return false;
        }
      }
    }
    return true;
  }
  std::vector<std::string> findAndReplacePattern(std::vector<std::string> & words, std::string pattern) {
    std::vector<std::string> v;
    for (int i = 0; i < words.size(); i++) {
      if (compare(words[i], pattern) == true) {
        v.push_back(words[i]);
      }
    }
    return v;
  }
};

void printVector(std::vector<std::string> vec, std::string msg="vector"){
	std::cout<<msg << " = [";
	for(std::string i : vec){
		std::cout << i <<" ";
	}
	std::cout << "]";
}

int main(){
  std::vector<std::string> words = {"abc","deq","mee","aqq","dkd","ccc"};
  std::string pattern = "abb";
  Patterns p;
  std::vector<std::string> result = p.findAndReplacePattern(words,pattern);
  printVector(result,"Result");
  return 0;
}

#include <algorithm>
#include <string>

bool hasMissingOrDuplicate(std::string key){
  int alphabetic[26] = {0};
  
  int len = key.length();
  for (int i = 0; i < len; i++){
    if(key.at(i) >= 'A' && key.at(i) <= 'Z'){
      alphabetic[key[i] - 65] += 1;
    }
  }
  
  for (int i = 0; i < 26; i++){
    if(alphabetic[i] != 1) return true;
  }
  
  return false;
}

std::string Monoalphabetic(std::string plaintext, std::string key){
  /* to uppercase */
  std::transform(plaintext.begin(), plaintext.end(),plaintext.begin(), ::toupper);
  std::transform(key.begin(), key.end(),key.begin(), ::toupper);

  if(key.length() != 26) return "key is not 26 characters";
  if(hasMissingOrDuplicate(key)) return "invalid key";

  int len = plaintext.length(); 
  for(int i = 0; i < len; i++){
    if(plaintext.at(i) >= 'A' && plaintext.at(i) <= 'Z'){
      plaintext[i] = key[plaintext[i] - 65];
    }
  }

  return plaintext;
}
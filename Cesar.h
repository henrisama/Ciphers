#include <algorithm>
#include <string>

std::string Cesar(std::string plaintext, int key){
  /* to uppercase */
  std::transform(plaintext.begin(), plaintext.end(),plaintext.begin(), ::toupper);

  if(key < 0 || key > 26){
    return "invalid key";
  }

  int len = plaintext.length();
  for(int i = 0; i < len; i++){
    if(plaintext.at(i) >= 'A' && plaintext.at(i) <= 'Z'){
      (plaintext[i] + key) > 90? plaintext[i] += (key - 26) : plaintext[i] += key;
    }
  }

  return plaintext;
}
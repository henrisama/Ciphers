#include <algorithm>
#include <string>

std::string ROT13(std::string plaintext){
  /* to uppercase */
  std::transform(plaintext.begin(), plaintext.end(),plaintext.begin(), ::toupper);

  int len = plaintext.length();
  for(int i = 0; i < len; i++){
    if(plaintext.at(i) >= 'A' && plaintext.at(i) <= 'M'){
      plaintext[i] += 13;
    }else if(plaintext.at(i) >= 'N' && plaintext.at(i) <= 'Z'){
      plaintext[i] -= 13;
    }
  }

  return plaintext;
}
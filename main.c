#include <stdlib.h>
#include <memory.h>
#include "vigenere.h"

int main(int argc, char *argv[]) {
  char mode;
  char *fileName;

  if(argv[1][0] == '-') {
    mode = argv[1][1];
    if(mode == 'h') {
      hack(argv[2], argv[3]);
      return 0;
    }
    fileName = argv[2];
  } else {
    mode = 'e';
    fileName = argv[1];
  }

  char passPhrase[MAX_PASS_LEN] =  "abc123def456";
  int passPhraseLen = 12;
//  char passPhrase[MAX_PASS_LEN];
//  int passPhraseLen = askForPassPhrase(passPhrase);

  switch(mode) {
    case 'e':
      encrypt(passPhrase, passPhraseLen, fileName);
      break;
    case 'd':
      decrypt(passPhrase, passPhraseLen, fileName);
      break;
    default:
      exit(1);
  }

  exit(0);
}
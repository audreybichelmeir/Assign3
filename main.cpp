#include "fileReader.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
string error = "error";
string file = " ";
bool readFile = false;
  if(argc > 1){
    file = argv[1];

    fileReader *fr = new fileReader();
    fr->readAFile(file);
    delete fr;

  }else{
    fileReader *fr = new fileReader();
    fr->filePrompt(error);
    delete fr;

  }
  return 0;
}

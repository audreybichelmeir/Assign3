#include "fileReader.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{

string file = " ";
  if(argc > 1){
    file = argv[1];
  }

  fileReader *fr = new fileReader();
  fr->readAFile(file);
  delete fr;

  return 0;
}

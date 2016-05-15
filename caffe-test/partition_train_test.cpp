//
//  partition_train_test.cpp
//  caffe-test
//
//  Created by James Cox on 15/05/2016.
//  Copyright © 2016 James Cox-Morton. All rights reserved.
//

#include <unistd.h>

#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <assert.h>

int main(int argc, const char *argv[]) {
  if (argc != 2) {
    std::cout << "Expected path to list file as an argument" << std::endl;
    return 1;
  }
  
  std::string input_list_file(argv[1]);
  
  std::ifstream input_file(input_list_file);
  assert(input_file.good());
  
  std::vector<std::string> file_entries;
  std::string line;
  while (std::getline(input_file, line)) {
    file_entries.push_back(line);
  }
  
  std::random_device rd;
  std::mt19937 g(rd());
  
  std::shuffle(file_entries.begin(), file_entries.end(), g);
  
  for(std::vector<std::string>::const_iterator iter = file_entries.begin(); iter != file_entries.end(); iter++) {
    std::cout << *iter << std::endl;
  }
  
  return 0;
}
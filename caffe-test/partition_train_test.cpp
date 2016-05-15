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

const int PERCENT_TO_SPLIT = 60;

int main(int argc, const char *argv[]) {
  if (argc != 2) {
    throw std::invalid_argument("Method takes one argument: INPUT_FILENAME");
    return 1;
  }
  std::string input_filename(argv[1]);
  
  std::ifstream input_file(input_filename);
  assert(input_file.good());
  
  std::vector<std::string> file_entries;
  std::string line;
  while (std::getline(input_file, line)) {
    file_entries.push_back(line);
  }
  
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(file_entries.begin(), file_entries.end(), g);
  
  size_t train_count = file_entries.size() * (PERCENT_TO_SPLIT / double(100.0));
  std::vector<std::string>::const_iterator iter = file_entries.begin();
  
  std::string train_filename = input_filename + ".train";
  std::ofstream train_file(train_filename);
  while(train_count > 0) {
    train_file << *iter << std::endl;
    iter++;
    train_count--;
  }
  train_file.close();
  std::cout << "Wrote training file: " << train_filename << std::endl;
  
  std::string test_filename = input_filename + ".test";
  std::ofstream test_file(test_filename);
  while(iter != file_entries.end()){
    test_file << *iter << std::endl;
    iter++;
  }
  test_file.close();
  std::cout << "Wrote test file: " << test_filename << std::endl;
  
  return 0;
}
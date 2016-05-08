//
//  build_rect_list_file.cpp
//  caffe-test
//
//  Created by James Cox on 08/05/2016.
//  Copyright © 2016 James Cox-Morton. All rights reserved.
//

#include "build_rect_list_file.hpp"
#include <iostream>
#include <vector>
#include <glob.h>

using namespace std;

vector<string> list_directory(const string &rect_folder) {
  vector<string> folders;
  glob_t glob_result;
  glob((rect_folder + "/*").c_str(), GLOB_TILDE, NULL, &glob_result);
  for(unsigned int i=0;i<glob_result.gl_pathc;++i){
    folders.push_back(string(glob_result.gl_pathv[i]));
  }
  return folders;
}

string extract_filename(const string &full_filename) {
  string::const_iterator last_slash = full_filename.begin();
  for(string::const_iterator iter = full_filename.begin(); iter != full_filename.end(); ++iter) {
    if (*iter == '/') {
      last_slash = iter;
    }
  }

  return string(++last_slash, full_filename.end());
}

string extract_label(const string &filename) {
  static const char split_char = '-';
  string::const_iterator iter = filename.begin();
  while(*iter != split_char)
    ++iter;
  
  return string(filename.begin(), iter);
}

void build_list_file(const std::string &rect_folder, const std::string &target_path) {
  vector<string> folders = list_directory(rect_folder);
  vector<string> not_present_images = list_directory(folders[0]);
  
  for(vector<string>::const_iterator iter = not_present_images.begin(); iter != not_present_images.end(); iter++) {
    string full_filename = *iter;
    string filename = extract_filename(full_filename);
    string label = extract_label(filename);
    cout << *iter << endl;
  }
}
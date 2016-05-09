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
#include <assert.h>

using namespace std;

PathAndLabel::PathAndLabel(string thePath, string theLabel) {
  path = thePath;
  label = theLabel;
}

vector<string> list_directory(const string &rect_folder) {
  vector<string> folders;
  glob_t glob_result;
  glob((rect_folder + "/*").c_str(), GLOB_TILDE, NULL, &glob_result);
  for(unsigned int i=0;i<glob_result.gl_pathc;++i){
    folders.push_back(string(glob_result.gl_pathv[i]));
  }
  return folders;
}

string remove_prefix(const string str, const string prefix) {
  string::const_iterator str_iter = str.begin();
  for(string::const_iterator prefix_iter = prefix.begin(); prefix_iter != prefix.end(); ++prefix_iter) {
    assert(*str_iter == *prefix_iter);
    ++str_iter;
  }
  
  return string(str_iter, str.end());
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

vector<PathAndLabel> build_list_file(const std::string &rect_folder, const std::string &target_path) {
  vector<string> folders = list_directory(rect_folder);
  vector<string> not_present_images = list_directory(folders[0]);
  
  vector<PathAndLabel> paths_and_labels;
  
  for(vector<string>::const_iterator iter = not_present_images.begin(); iter != not_present_images.end(); iter++) {
    string relative_filepath = remove_prefix(*iter, rect_folder);
    string filename = extract_filename(relative_filepath);
    string label = extract_label(filename);
    paths_and_labels.push_back(PathAndLabel(relative_filepath, label));
  }
  
  return paths_and_labels;
}
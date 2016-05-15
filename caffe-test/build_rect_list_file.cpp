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
#include <assert.h>
#include "dir_utils.hpp"

using namespace std;

PathAndLabel::PathAndLabel(string thePath, string theLabel) {
  path = thePath;
  label = theLabel;
}

string remove_prefix(const string str, const string &prefix) {
  string::const_iterator str_iter = str.begin();
  for(string::const_iterator prefix_iter = prefix.begin(); prefix_iter != prefix.end(); ++prefix_iter) {
    assert(*str_iter == *prefix_iter);
    ++str_iter;
  }
  
  return string(str_iter, str.end());
}

string extract_label(const string &filename) {
  static const char split_char = '-';
  string::const_iterator iter = filename.begin();
  while(*iter != split_char)
    ++iter;
  
  string label_text(filename.begin(), iter);
  if (label_text == "present") {
    return "1";
  } else if (label_text == "empty") {
    return "0";
  } else {
    cout << "Unexpected label!!: " << label_text << endl;
    assert(false);
    return "";
  }
}

vector<PathAndLabel> build_list_file(const string &folder_path, const std::string &root_folder) {
  vector<string> not_present_images = DirUtils::list_directory(folder_path);
  
  vector<PathAndLabel> paths_and_labels;
  
  for(vector<string>::const_iterator iter = not_present_images.begin(); iter != not_present_images.end(); iter++) {
    string relative_filepath = remove_prefix(*iter, root_folder + "/");
    string filename = DirUtils::extract_filename(relative_filepath);
    string label = extract_label(filename);
    paths_and_labels.push_back(PathAndLabel(relative_filepath, label));
  }
  
  return paths_and_labels;
}
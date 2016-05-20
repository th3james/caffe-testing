//
//  build_full_image_listfile.cpp
//  caffe-test
//
//  Created by James Cox on 19/05/2016.
//  Copyright © 2016 James Cox-Morton. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <assert.h>

#include "dir_utils.hpp"
#include "path_and_label.hpp"
#include "list_file_writer.hpp"

const std::string IMAGES_PATH = "/Users/th3james/src/curricular/ros_labelled_image_streamer/training/training-data/full";
const std::string LIST_FILE = "/Users/th3james/src/curricular/cpp/caffe-test/caffe-test/full_images.list";

typedef std::string::const_iterator str_itr_t;
typedef std::vector<std::string>::const_iterator strv_itr_t;

std::string convertLabelStrToLabel(const std::string &labelStr) {
  if (labelStr == "Left") {
    return "0";
  } else if (labelStr == "Forward") {
    return "1";
  } else if (labelStr == "Right") {
    return "2";
  } else {
    std::cout << "Unexpected label!!: " << labelStr << std::endl;
    assert(false);
    return "";
  }
}

PathAndLabel splitPathAndLabel(const std::string &fullFilename) {
  const std::string filename = DirUtils::extract_filename(fullFilename);
  str_itr_t iter = filename.begin();

  while(*iter != '-') {
    ++iter;
  }
  std::string labelStr(filename.begin(), iter);
  
  return PathAndLabel(filename, convertLabelStrToLabel(labelStr));
}

int main(int argc, const char * argv[]) {
  
  std::vector<std::string> images = DirUtils::list_directory(IMAGES_PATH);

  std::vector<PathAndLabel> listEntries;
  for(strv_itr_t iter = images.begin(); iter != images.end(); ++iter) {
    listEntries.push_back(splitPathAndLabel(*iter));
  }
  
  ListFileWriter::writeFile(listEntries, LIST_FILE);
  
  std::cout << "List file written to " << LIST_FILE  << std::endl;
  return 0;
}
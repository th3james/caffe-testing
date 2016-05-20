//
//  main.cpp
//  caffe-test
//
//  Created by James Cox on 30/04/2016.
//  Copyright © 2016 James Cox-Morton. All rights reserved.
//

#include <unistd.h>

#include <iostream>
#include <vector>
#include <string>

#include "build_rect_list_file.hpp"
#include "dir_utils.hpp"
#include "list_file_writer.hpp"

const std::string IMAGES_PATH = "/Users/th3james/src/curricular/ros_labelled_image_streamer/training/training-data/rects";
const std::vector<std::string> paths = {"0", "4", "7", "14", "11", "25", "present"};

const std::string LIST_FILE = "/Users/th3james/src/curricular/cpp/caffe-test/caffe-test/rect_images.list";

int main(int argc, const char * argv[]) {
  typedef std::vector<std::string>::const_iterator strv_iter;
  
  std::vector<std::string> sub_folders = DirUtils::list_directory(IMAGES_PATH);
  strv_iter new_end = remove_if(sub_folders.begin(), sub_folders.end(),
    [](const std::string &folder) {
      strv_iter iter = paths.begin();
      while(iter != paths.end()) {
        if (*iter == DirUtils::extract_filename(folder)) {
          return false;
        }
        iter++;
      }
      return true;
    }
  );

  sub_folders.erase(new_end, sub_folders.end());
  
  std::vector<PathAndLabel> list_components;
  
  for(strv_iter iter = sub_folders.begin(); iter != sub_folders.end(); iter++) {
    std::vector<PathAndLabel> folder_list_components = build_list_file(*iter, IMAGES_PATH);
    
    copy(folder_list_components.begin(), folder_list_components.end(), back_inserter(list_components));
  }
  
  ListFileWriter::writeFile(list_components, LIST_FILE);
  
  std::cout << "List file written to " << LIST_FILE  << std::endl;
  return 0;
}
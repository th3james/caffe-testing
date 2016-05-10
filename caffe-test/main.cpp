//
//  main.cpp
//  caffe-test
//
//  Created by James Cox on 30/04/2016.
//  Copyright © 2016 James Cox-Morton. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

#include "build_rect_list_file.hpp"
#include "dir_utils.hpp"

using namespace std;

const string IMAGES_PATH = "/Users/th3james/src/curricular/ros_labelled_image_streamer/training/training-data/rects";
const vector<string> paths = {"0", "4", "7", "14", "11", "25", "present"};

const string LIST_FILE = "./rect_images.list";

int main(int argc, const char * argv[]) {
  vector<string> sub_folders = DirUtils::list_directory(IMAGES_PATH);
  vector<string> sub_folders_to_use;
  copy_if(sub_folders.begin(), sub_folders.end(), back_inserter(sub_folders_to_use),
          [](string folder) {
            vector<string>::const_iterator iter = paths.begin();
            while(iter != paths.end()) {
              if (*iter == DirUtils::extract_filename(folder)) {
                return true;
              }
              iter++;
            }
            return false;
          });
  
  vector<PathAndLabel> list_components;
  
  for(vector<string>::const_iterator iter = sub_folders_to_use.begin(); iter != sub_folders_to_use.end(); iter++) {
    vector<PathAndLabel> folder_list_components = build_list_file(*iter, IMAGES_PATH);
    
    copy(folder_list_components.begin(), folder_list_components.end(), back_inserter(list_components));
  }
  
  for(vector<PathAndLabel>::const_iterator iter = list_components.begin(); iter != list_components.end(); iter++) {
    cout << iter->path << ", " << iter->label << endl;
  }
  return 0;
}
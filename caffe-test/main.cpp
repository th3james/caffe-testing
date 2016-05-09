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
const std::vector<string> paths {"0", "4", "7", "14", "11", "25", "present"};

const string LIST_FILE = "./rect_images.list";

int main(int argc, const char * argv[]) {
  vector<string> sub_folders = DirUtils::list_directory(IMAGES_PATH);
  vector<PathAndLabel> list_components = build_list_file(sub_folders[0], IMAGES_PATH);
  
  for(vector<PathAndLabel>::const_iterator iter = list_components.begin(); iter != list_components.end(); iter++) {
    cout << iter->path << ", " << iter->label << endl;
  }
  return 0;
}
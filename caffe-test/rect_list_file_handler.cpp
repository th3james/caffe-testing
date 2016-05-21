//
//  build_rect_list_file.cpp
//  caffe-test
//
//  Created by James Cox on 08/05/2016.
//  Copyright © 2016 James Cox-Morton. All rights reserved.
//

#include "rect_list_file_handler.hpp"
#include <iostream>
#include <vector>
#include <assert.h>
#include "dir_utils.hpp"
#include "path_and_label.hpp"

namespace RectListFileHandler {
  typedef std::string::const_iterator str_citr;

  std::string removePrefix(const std::string str, const std::string &prefix) {
    str_citr str_iter = str.begin();
    for(str_citr prefix_iter = prefix.begin(); prefix_iter != prefix.end(); ++prefix_iter) {
      assert(*str_iter == *prefix_iter);
      ++str_iter;
    }
    
    return std::string(str_iter, str.end());
  }

  std::string extractLabel(const std::string &filename) {
    static const char split_char = '-';
    str_citr iter = filename.begin();
    while(*iter != split_char)
      ++iter;
    
    std::string label_text(filename.begin(), iter);
    if (label_text == "present") {
      return "1";
    } else if (label_text == "empty") {
      return "0";
    } else {
      std::cout << "Unexpected label!!: " << label_text << std::endl;
      assert(false);
      return "";
    }
  }

  std::vector<PathAndLabel> fetchListEntries(const std::string &folder_path, const std::string &root_folder) {
    std::vector<std::string> not_present_images = DirUtils::list_directory(folder_path);
    
    std::vector<PathAndLabel> paths_and_labels;
    
    for(std::vector<std::string>::const_iterator iter = not_present_images.begin(); iter != not_present_images.end(); iter++) {
      std::string relative_filepath = removePrefix(*iter, root_folder + "/");
      std::string filename = DirUtils::extract_filename(relative_filepath);
      std::string label = extractLabel(filename);
      paths_and_labels.push_back(PathAndLabel(relative_filepath, label));
    }
    
    return paths_and_labels;
  }
}
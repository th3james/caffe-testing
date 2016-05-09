//
//  build_rect_list_file.hpp
//  caffe-test
//
//  Created by James Cox on 08/05/2016.
//  Copyright © 2016 James Cox-Morton. All rights reserved.
//

#ifndef build_rect_list_file_hpp
#define build_rect_list_file_hpp

#include <string>
#include <vector>

struct PathAndLabel {
  std::string path;
  std::string label;
  
  PathAndLabel(std::string thePath, std::string theLabel);
};

std::vector<PathAndLabel> build_list_file(const std::string &rect_folder, const std::string &target_path);

#endif /* build_rect_list_file_hpp */
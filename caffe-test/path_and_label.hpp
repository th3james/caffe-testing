//
//  path_and_label.hpp
//  caffe-test
//
//  Created by James Cox on 20/05/2016.
//  Copyright © 2016 James Cox-Morton. All rights reserved.
//

#ifndef path_and_label_hpp
#define path_and_label_hpp

#include <stdio.h>
#include <string>

struct PathAndLabel {
  std::string path;
  std::string label;
  
  PathAndLabel(std::string thePath, std::string theLabel);
};


#endif /* path_and_label_hpp */

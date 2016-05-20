//
//  path_and_label.cpp
//  caffe-test
//
//  Created by James Cox on 20/05/2016.
//  Copyright © 2016 James Cox-Morton. All rights reserved.
//

#include "path_and_label.hpp"
#include <string>

PathAndLabel::PathAndLabel(std::string thePath, std::string theLabel) {
  path = thePath;
  label = theLabel;
}
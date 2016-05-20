//
//  list_file_writer.cpp
//  caffe-test
//
//  Created by James Cox on 20/05/2016.
//  Copyright © 2016 James Cox-Morton. All rights reserved.
//

#include "list_file_writer.hpp"
#include <iostream>
#include <fstream>

namespace ListFileWriter {
  void writeFile(const std::vector<PathAndLabel> &pathAndLabels, const std::string &filePath) {
    std::ofstream outputFile(filePath);
    
    for(std::vector<PathAndLabel>::const_iterator iter = pathAndLabels.begin(); iter != pathAndLabels.end(); iter++) {
      outputFile << iter->path << " " << iter->label << std::endl;
    }
  }

}
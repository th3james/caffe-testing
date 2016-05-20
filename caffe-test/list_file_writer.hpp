//
//  list_file_writer.hpp
//  caffe-test
//
//  Created by James Cox on 20/05/2016.
//  Copyright © 2016 James Cox-Morton. All rights reserved.
//

#ifndef list_file_writer_hpp
#define list_file_writer_hpp

#include <stdio.h>
#include <vector>

#include "path_and_label.hpp"

namespace ListFileWriter {
  void writeFile(const std::vector<PathAndLabel> &pathAndLabels, const std::string &filePath);
}

#endif /* list_file_writer_hpp */

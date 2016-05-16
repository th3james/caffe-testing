#!/bin/sh

#  build_rect_image_set.sh
#  caffe-test
#
#  Created by James Cox on 08/05/2016.
#  Copyright © 2016 James Cox-Morton. All rights reserved.

CAFFE_PATH="/Users/th3james/src/curricular/cpp/caffe-test/caffe-test/caffe"

$CAFFE_PATH/build/tools/caffe train --solver=rects_solver.prototxt
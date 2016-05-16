#!/bin/sh

#  build_rect_image_set.sh
#  caffe-test
#
#  Created by James Cox on 08/05/2016.
#  Copyright © 2016 James Cox-Morton. All rights reserved.

CAFFE_PATH="/Users/th3james/src/curricular/cpp/caffe-test/caffe-test/caffe"
IMAGES_PATH="/Users/th3james/src/curricular/ros_labelled_image_streamer/training/training-data/rects/"
LIST_FILE_PATH="rect_images.list"
OUTPUT_PATH="rects_lmdb"

$CAFFE_PATH/build/tools/convert_imageset.bin $IMAGES_PATH $LIST_FILE_PATH.train $OUTPUT_PATH.train -shuffle
$CAFFE_PATH/build/tools/convert_imageset.bin $IMAGES_PATH $LIST_FILE_PATH.test $OUTPUT_PATH.test -shuffle
#!/bin/sh

#  Script.sh
#  caffe-test
#
#  Created by James Cox on 21/05/2016.
#  Copyright © 2016 James Cox-Morton. All rights reserved.

CAFFE_PATH="/Users/th3james/src/curricular/cpp/caffe-test/caffe-test/caffe"
IMAGES_PATH="/Users/th3james/src/curricular/ros_labelled_image_streamer/training/training-data/full/"
LIST_FILE_PATH="full_images.list"
OUTPUT_PATH="full_lmdb"

$CAFFE_PATH/build/tools/convert_imageset.bin $IMAGES_PATH $LIST_FILE_PATH.train $OUTPUT_PATH.train -shuffle
$CAFFE_PATH/build/tools/convert_imageset.bin $IMAGES_PATH $LIST_FILE_PATH.test $OUTPUT_PATH.test -shuffle
# Experimenting with Caffe deep learning framework
This project expects Caffe to be checked out into ./caffe and built.

## Building an LMDB image database for caffe
Caffe expects images to be converted to LMDB for training on. The following script uses caffe's built in convert_imageset.bin to convert images in a LISTFILE into an LMDB

    ./build_rect_image_set.sh

### Building a LISTFILE for input into the previous script
A list file is simply described (in convert_imageset.cpp in Caffe's source) as 

    // LISTFILE should be a list of files as well as their labels, in the format as
    //    subfolder1/file1.JPEG 7

build_rect_list_file.hpp in this project has some utilities for formatting a list file.

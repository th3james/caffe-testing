# Experimenting with Caffe deep learning framework
This project expects Caffe to be checked out into ./caffe and built.

## Building an LMDB image database for caffe
Caffe expects images to be converted to LMDB for training on. The following scripts use caffe's built in convert_imageset.bin to convert images in a LISTFILE into an LMDB

    ./build_rect_image_set.sh
    ./build_full_image_set.sh

### Building a LISTFILE for input into the previous script
A list file is simply described (in convert_imageset.cpp in Caffe's source) as 

    // LISTFILE should be a list of files as well as their labels, in the format as
    //    subfolder1/file1.JPEG 7

The XCode scheme 'build_rect_image_listfile' will build a list file based on the sliced rect images collected from the turtlebot.
The XCode scheme 'build_full_image_listfile' will build a list file based on the full images collected from the turtlebot.

### Partitioning the LISTFILE into train and test datasets
The XCode scheme 'partition-train-test' partitions a given LISTFILE into 60/40 split training and test files

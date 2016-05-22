#!/bin/sh

SOURCE_FILES="sort_entrance.c *sort.c"
TARGET=sort

echo "sorce files: $SOURCE_FILES"


#gcc sort_entrance.c countsort.c quicksort.c issort.c mergesort.c -o sort

gcc $SOURCE_FILES -o $TARGET

#!/bin/sh

rm ./jni/*.c
rm ./jni/*.h
cp ../*.h ./jni
cp ../*.c ./jni

#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-10-27 15:46:04
# @Author  : Sundae Chen (sundaechn@gmail.com)
# @Link    : http://sundae.applinzi.com/home

import cv2
import sys

inputImageFile = sys.argv[1]
faceClassifier = cv2.CascadeClassifier('/opencv-3.3.0/data/haarcascades_cuda/haarcascade_frontalface_alt_tree.xml')
objImage = cv2.imread(inputImageFile)
cvtImage = cv2.cvtColor(objImage, cv2.COLOR_BGR2GRAY)
foundFaces = faceClassifier.detectMultiScale(cvtImage, scaleFactor=1.1, minNeighbors=3)

for (x, y, w, h) in foundFaces:
    #cv2.rectangle(objImage, (x, y), (x + w, y + h), (0, 0, 255), 2)
    pass

cv2.imshow('img', objImage)
cv2.waitKey(0)
i=32 #or other num
faceROI=objImage[x-i:x+w-i,y+i:y+h+i]
cv2.imshow('faceROI', faceROI)
cv2.waitKey(0)
myface=cv2.resize(faceROI,(92,112))
cv2.imshow('myface', myface)
cv2.waitKey(0)
cv2.imwrite('new_'+inputImageFile,myface)

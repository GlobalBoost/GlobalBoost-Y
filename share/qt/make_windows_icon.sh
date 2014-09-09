#!/bin/bash
# create multiresolution windows icon
ICON_SRC=../../src/qt/res/icons/bitcoin.png
ICON_DST=../../src/qt/res/icons/bitcoin.ico
convert ${ICON_SRC} -resize 16x16 globalboost-y-16.png
convert ${ICON_SRC} -resize 32x32 globalboost-y-32.png
convert ${ICON_SRC} -resize 48x48 globalboost-y-48.png
convert globalboost-y-16.png globalboost-y-32.png globalboost-y-48.png ${ICON_DST}


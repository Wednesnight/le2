#!/bin/sh

mkdir -p "${BUILD_DIR}/${CONFIGURATION}/${PRODUCT_NAME}.app/Contents/Resources"
rm -fr "${BUILD_DIR}/${CONFIGURATION}/${PRODUCT_NAME}.app/Contents/Resources/resources"
cp -R resources "${BUILD_DIR}/${CONFIGURATION}/${PRODUCT_NAME}.app/Contents/Resources/resources"

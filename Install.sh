#!/bin/bash

cd smartplus-builder/
cd build/
cmake ..
make
cd ..
cd ..
cp smartplus-builder/build/lib/smartplus.so python-setup/simmit/smartplus.so
cd python-setup/

current_dir=$(pwd)

python ${current_dir}/setup.py install
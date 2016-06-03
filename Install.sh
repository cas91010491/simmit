#!/bin/bash

#Find th current directory
current_dir=$(pwd)

cd smartplus-builder/

#Test if build exist and if it's necessary to erase it
if [ ! -d "build" ]
then
mkdir ${current_dir}/smartplus-builder/build
echo "Folder created.\n"
else
echo "Build directory already exists."

while true; do
read -p "Do you want to erase old compilation files (Recommended : No) ? " yn
case $yn in
[YyOo]* ) rm -r ${current_dir}/smartplus-builder/build/*; break;;
[Nn]* ) break;;
* ) echo "Please answer yes (y) or no (n).";;
esac
done
fi

cd ${current_dir}/smartplus-builder/build
cmake ..
echo ""
make
make install
make test
cd ..
cd ..
cp ${current_dir}/smartplus-builder/build/lib/smartplus.so ${current_dir}/python-setup/simmit/smartplus.so
cp ${current_dir}/smartplus-builder/build/lib/identify.so ${current_dir}/python-setup/simmit/identify.so
cd python-setup/

#Change the current dir and install python library
current_dir=$(pwd)

python ${current_dir}/setup.py install
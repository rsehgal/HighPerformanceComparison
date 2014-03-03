mkdir build
cd build
cmake ..
make clean
make
echo "Deleting Temporary File created during compilation"
cd ..
rm -rf build 

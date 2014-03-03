mkdir build
cd build
cmake -DUSEAVX=ON ..
make clean
make
echo "Deleting Temporary File created during compilation"
cd ..
rm -rf build 

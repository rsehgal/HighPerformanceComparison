rm -rf build
mkdir build
cd build
cmake -DUSEAVX=ON -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..
make clean
make
#echo "Deleting Temporary File created during compilation"
cd ..
#rm -rf build 


rem out of source build used by cmake

mkdir build  
cd build

cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX:PATH=../setup  -G"NMake Makefiles" ../ 

nmake install

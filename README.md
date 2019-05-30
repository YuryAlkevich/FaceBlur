# FaceBlur

## Compilation and runnung on Linux

``` bash
git clone https://github.com/YuryAlkevich/FaceBlur.git
cd FaceBlur
cmake .
make
# run tests
make test

# run example
cd bin
./FaceBlurDemo ../Tests/testdata ./result
```

## Compilation and runnung on Windows

``` bash
# in FaceBlur directory from Windows command prompt
cmake -S . -B .\build
cmake --build .\build --target FaceBlurDemo --config Release
# run tests
cmake --build .\build --target runTests --config Release
cd .\build
ctest -C Release
# run example
cd .\bin
.\FaceBlurDemo.exe ..\..\Tests\testdata\ .\result


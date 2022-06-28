# Arduino

These are some small libraries that will hopefully be useful to somebody. To use, you just need to download the files that you want to use (located in the `lib` directory). 

I created the classes `array` and `vector` because I like to use std::array and std::vector in C++ a lot. So I just wanted them in Arduino as well. 

## Building

Put the libraries in a folder where your `*.ino` file can find it. You should be able to just `#include` the header file you want to use in your `*.ino` file. 

Example: The file `main.ino` is the file you are currently working on. It is using the `lib::array`, so you created a directory `lib` inside the directory where your `main.ino` file resides in. The `array.h` file is placed there. 

The example should compile just fine. If not, please feel free to open up issues. 


## Building the tests

Inside the `test` directory the tests are located. Those can be build by executing `g++ testname.cpp`. I personally also like to use the compiler flags `-Wall -Wextra -Werror` for additional warnings. 

Compilation should work pretty straightforward out of the box if you clone the repo. 


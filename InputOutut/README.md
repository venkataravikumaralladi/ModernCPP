### IO Module
C++ IO system is provided by IO component of C++ library and is based on streams. A stream acts as a source or destination. Streams does not interact directly with device, streams interact with buffers which then writes/reads to/from device based on stream type is read or write. Due to this indirection programmer can effortlessly redirect input and output by setting the buffer pointers (by calling rdbuf(streambuf* p) and passing that buff pointer to stream we are interested) instead of dealing with devices.

cin and cout are build int standard streams that opens automatically and connects to standard input device (keyboard) and output device (monitor).

High level overview of class diagram for input stream is shown below.

![image](https://user-images.githubusercontent.com/10434795/150637407-8987bb13-01b9-42a9-8855-64bdbea4c618.png)


### Basic difference between C IO module and C++ IO module
#####  C IO System <br>
        IO Header is stdio.h <br>
        printf to print to console <br>
        Console is stdout <br>
        printf is a variadic function <br>
        \n to go to the new line <br>
        \n is escaped new line character <br>


  ##### C++ IO System <br>
        IO Header is iostream <br>
        operator<< to stream to console <br>
        Console is std::cout ostream (in std namespace) <br>
        operator<< is a binary operator <br>
        std::endl (in std namespace) to go to the new line <br>
        std::endl is stream manipulator (newline) functor <br>

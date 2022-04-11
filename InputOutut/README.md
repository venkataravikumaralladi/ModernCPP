### IO Module
C++ IO system is provided by IO component of C++ library and is based on streams. A stream acts as a source or destination. Streams does not interact directly with device, streams interact with buffers which then writes/reads to/from device based on stream type is read or write. Due to this indirection programmer can effortlessly redirect input and output by setting the buffer pointers (by calling rdbuf(streambuf* p) and passing that buff pointer to stream we are interested) instead of dealing with devices.

cin and cout are build int standard streams that opens automatically and connects to standard input device (keyboard) and output device (monitor).

Redirection of input and output to diffent streams template is shown in `redirect_io_template.cpp`

High level overview of class diagram for input stream is shown below.

![image](https://user-images.githubusercontent.com/10434795/150637407-8987bb13-01b9-42a9-8855-64bdbea4c618.png)


### Basic difference between C IO module and C++ IO module
#####  C IO System <br>
        IO Header is stdio.h
        printf to print to console
        Console is stdout
        printf is a variadic function
        \n to go to the new line
        \n is escaped new line character


  ##### C++ IO System <br>
        IO Header is iostream 
        operator<< to stream to console
        Console is std::cout ostream (in std namespace)
        operator<< is a binary operator
        std::endl (in std namespace) to go to the new line
        std::endl is stream manipulator (newline) functor

### Basic notes on `cin` and `getline`
`getline` does not ignore leading whitespace characters, you should take special care when using it in conjunction with `cin >>`. The problem is `cin >>` leaves the newline character `(\n)` in the iostream.  If getline is used after `cin>>`, the `getline` sees this newline character as leading whitespace, thinks it is finished and stops
reading any further. Though `getline` reads `\n` character it ignores while writing to ouput stream.

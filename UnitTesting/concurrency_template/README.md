### Test Driven Development for concurrency programming
Here unit test template for concurrency programming is provided. This template can be modified as per requirments. This idea is reusable. Following are core concepts for test driving threads. In Unit tests we use condition variables from C++ to wait for threads to respond according to our timing requirements.

Building multithreaded code is perhaps the most difficult task in software development. Few of us regularly write code that must support concurrency, which makes it that much harder. Using TDD, your approach to multithreaded code moves in the direction of scientific method and away from mystic art. Instead of hoping that your reasoning around concurrent execution is correct and instead of throwing locks and synchronization at any problems, you use TDD as a tool to validate or disprove your hypotheses about where the concurrency issues truly lie. We can use below ideas while working on concurrency developement using TDD. This text and code is taken from reference Modern C++ Programming with Test-Driven Development by Jeff Langr from The Pragmatic Programmers publishers.

1. `Seperate threading logic from application logic:` Threading is one concern, and your application logic is another. Keep them seperate as much as possible and minimize the intermingling.
2. `Throttle down to single-threaded for application specific tests:` Your application code must firest work in a single threaded environment before you introduce threads. Once threads are in place you'll still need to demonstrate that the applicatoin logic works correctly. Providing a way to eliminate concurrency concerns for the application-specific unit tests will help keep code clean. In a sense, testing multithreaded code moves you into realm of intergration testing. To override threading control, you can either design hooks into your application or introduce test doubles.
3. `Demonstrate concurrency issues before introducing concurrency controls:` Core theme of idea is first write a test that demonstrates a potential concurrency problem and then exacerbating it to the point where the test fails every time. Demonstrating failure first allows you to remain test-driven. You add only the concurrency control that makes the test pass.
4. 

#### Demo template implements following user story

The GeoServer provides support for client applications seeking to track the geographic location of large number of users (we can think of users as cabs in case users are tracked are not legal :) )

As a client user, I expect the "retrive nearby users" request to respond almost immediately. I want to receive each element from the list of nearby users asynchronously so that I can display each on the map as I receive it.

High level class diagram is shown below

![image](https://user-images.githubusercontent.com/10434795/166135976-18e32430-7a5d-479e-a485-8ca56c077122.png)

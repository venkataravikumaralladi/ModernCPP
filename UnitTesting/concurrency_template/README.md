### Test Driven Development for embedded development
Most of the literature available from unit testing is from application point of view. Here we will learn how we can apply these techniques from embedded development point of view. In embedded product most of the times hardware and software development happens parallely. So software developers put their ideas in document or code a lot and wait for hardware to provided for testing purpose. If bug is found there is argument on where bug is, hardware or software meetings, talk, argue etc. Unit testing ideas plays an important role here. We can use the techniques from unit testing framework needed to test code that interacts with other modules in the system. We can stub out the dependencies of the code under test. We will use ideas test double and a mock object, both important to being able to thoroughly test-drive your code. <br>
Computer programming is a very complex activity. Among other reasons, Test Driven Development (TDD) is needed to systematically get our code working as intended and to produce the
automated test cases that keep the code working. Test-Driven Development is not a testing technique, it is a way to solve programming problems. It helps software developers make good design decisions. Following picture (source: Test driven development for embedded C by James W Grenning) shows comparision of bug fixing with out TDD and with TDD

![image](https://user-images.githubusercontent.com/10434795/152630601-9082acb4-da92-4eea-9dc1-5faaadd3be22.png)

From embedded software development perspective TDD helps to isolate hardware/software interaction issues by modeling hardware interactions in the tests. Improve software design through the decoupling of modules from each other and the hardware. Testable code is, by necessity, modular.

### Why Test Driven Development (TDD)
In TDD At any given point, your complete set of tests declares the behaviors you intend your system to have. That implies the converse: if no test describes a
behavior, it either doesn’t exist or isn’t intended (or the tests do a poor job of describing behavior).

TDD helps us in developing code incrementally in particular agile process. As requriments change or new requirments come TDD helps us in making changes in effective, and confident way with out worrying about existing functionality.

The strength of TDD is its ability to let you move forward in the face of incomplete information and in its ability to let you correct earlier choices as new information arises. TDD is not a hard science; instead, think of it as a craftperson’s tool for incrementally growing a codebase. It’s a tool that accommodates
continual experimentation, discovery, and refinement. It’s a good idea that promotes focusing on the `behavior` of the tests, instead of centering tests
around functions.

### Is TDD Test-Driving or Testing? :

The most important consideration in TDD is that we are test-driving, not testing. Using a testing technique, you would seek to exhaustively analyze the specification
in question (and possibly the code) and devise tests that exhaustively cover the behavior. TDD is instead a technique for driving the design of the code. Your tests primarily serve the purpose of specifying the behavior of what you will build. The tests in TDD are almost a by-product of the process. They provide you with the necessary confidence to make subsequent changes to the code. The important aspect is that TDD represents more of a sufficiency mentality. If you know that the logic won’t need to change any further, you stop writing tests.


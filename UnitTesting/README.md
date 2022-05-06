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

From embedded point of view with out TDD We spent many an evening in central offices sitting on concrete floors with oscilloscopes, logic analyzers, etc. to debug problems.

`Well - structured tests become a form of executable and unambiguous documentation. A working example is worth 1,000 words.` Test-Driven Development is not a testing technique, although you do write a lot of valuable automated tests. It is a way to solve programming problems. It helps software developers make good design decisions.
Tests provide a clear warning when the solution takes a wrong path or breaks some forgotten constraint. Tests capture the production code’s desired behavior.

Improve software design through the decoupling of modules from each other and the hardware. Testable code is, by necessity, modular. 

Tests capture assumptions, constraints, and illustrate representative usage. When new code violates a constraint or assumption, the tests fail.

TDD helps get code working in the first place, but the bigger payoff is in the future, where it supports future developers in understanding the code and keeping it working. Code can be (almost) fearlessly changed.


### Is TDD Test-Driving or Testing? :

The most important consideration in TDD is that we are test-driving, not testing. Using a testing technique, you would seek to exhaustively analyze the specification
in question (and possibly the code) and devise tests that exhaustively cover the behavior. TDD is instead a technique for driving the design of the code. Your tests primarily serve the purpose of specifying the behavior of what you will build. The tests in TDD are almost a by-product of the process. They provide you with the necessary confidence to make subsequent changes to the code. The important aspect is that TDD represents more of a sufficiency mentality. If you know that the logic won’t need to change any further, you stop writing tests.

### Important point related to unit test case:

One other possible outcome during a test run is a crash. Generally speaking, C is not a safe language. The code can go off into the weeds, never to return. sprintf( ) is a dangerous function. If you pass it an output buffer that is too small, it will corrupt memory. This error might crash the system now. It might crash later. The behavior is undefined. Consequently, a test run may silently exit with an OK, silently exit early showing no errors, or crash with a bang.

When you have a silent failing or crashing test, let the test harness help you confirm what is wrong. Sometimes a production code change will cause a previously passing test to fail, or even crash. So, before chasing the crash, make sure you know which test is failing. Because the test harness is normally quiet except for test failures, when a test crashes, you probably won’t get any useful output. Test harness tools like google test, Unity and CppUTest have a command-line option for running the test in verbose mode (-v). With -v, each TEST( ) announces itself before running. Conveniently, the last TEST( ) mentioned is the one that crashed. You can also filter tests by test group (-g testgroup) and test case (-n testname). This lets you get very precise about which test cases are running. These are very helpful for chasing down crashes.

### Unit test case has four phases:
    The four phases:
        • Setup: Establish the preconditions to the test.
        • Exercise: Do something to the system.
        • Verif y: Check the expected outcome.
        • Cleanup: Return the system under test to its initial state after the test.
        
To keep your tests clear, make the above steps visible in your tests.

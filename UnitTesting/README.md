### Unit testing basics
Most of the literature available from unit testing is from application point of view. Here we will learn how we can apply these techniques from embedded development point of view. In embedded product most of the times hardware and software development happens parallely. So software developers put their ideas in document or code a lot and wait for hardware to provided for testing purpose. If bug is found there is argument on where bug is, hardware or software meetings, talk, argue etc. Unit testing ideas plays an important role here. We can use the techniques from unit testing framework needed to test code that interacts with other modules in the system. We can stub out the dependencies of the code under test. We will use ideas test double and a mock object, both important to being able to thoroughly test-drive your code. <br>
Computer programming is a very complex activity. Among other reasons, Test Driven Development (TDD) is needed to systematically get our code working as intended and to produce the
automated test cases that keep the code working. Test-Driven Development is not a testing technique, it is a way to solve programming problems. It helps software developers make good design decisions. Following picture (source: Test driven development for embedded C by James W Grenning) shows comparision of bug fixing with out TDD and with TDD

![image](https://user-images.githubusercontent.com/10434795/152630601-9082acb4-da92-4eea-9dc1-5faaadd3be22.png)



### General safety software design idea

#### Creating software safety requirments

Building software systems are not easy, especially safe software systems are even harder.  Design hazards must be added to hazard analysis and tracker during development process.

Safety requirements can account for most of the complexity of the system. The process of construction safe systems can be broken up into multistep plan as shown below. Following is approach used to create safety requirements.

1. Identify the hazards
2. Determine the risks
3. Define the safety measure like documenting, educating, Alarm, internal checking to name a few
4. Create safe requirements
5. Create safe designs example like build in power-on and periodic run-time tests to identify latent faults.
6. Implement safety like language selection, strong compile time checking, run-time checking, exception handling.
7. Follow safety process
8. Test


#### embedded software design
 
The embedded software is divided into two parts: safety related part and non-safety related part. 
These two parts are totally isolated to make sure they will not affect each other.  Now a days one single board which has multi core processor,
multiple ports to name a few is used in safety system. Various modules like safety, non-safety is run on the board on top of RTOS.
We have to handle various scenarios for separation of safety and non-safety like below. As part of specification we have to handle safety and non-safety separation.

 Below are few guidelines act as input when designing software for safety 
 
 `Timing` How can we guarantee that one subsystem will not absorb so much processor time that another subsystem is starved?

`Deadlocks and live locks` What prevent two unrelated subsystems that share a peripheral (e.g., a mutex) from forming a deadlock or live lock?

`Memory` How does the design guarantee that one subsystem will not write over the memory used by another subsystem?

`Messaging` If one subsystem depends on receiving messages from another subsystem, how does the system guarantee continued safety if a message is lost, 
            corrupted, delayed, or duplicated?

In addition we have to handle common which are invisible to application like cache, bus, etc. <br>
How to handle system limitation rather than system malfunction?

#### Following are software techniques widely used in safety programming are

 1. HAZOP (Hazard and Operability Study) analysis. (usually performed in brain storm session) <br>
 2. Subset of language features. <br>
 3. Use safety approved components like safe OS, certified libraries, to name a few. <br>
 4. Defensive programming. <br>
 5. Programming by contract <br>
 6. Fault injection testing (FITs) <br>
 7. Static code analysis. <br>
 8. Unit testing <br>
 9. Code coverage <br>

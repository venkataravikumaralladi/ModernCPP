
### Brief notes on IEC 61508

Generally something must continue to function to keep the system safe.

The generic model used in IEC61508 is a piece of industrial equipment that can inherently give raise to safety hazards, and a safety function 
that monitors it an move it into a safe state when a hazardous situation is detected. IEC 61508 idea is that the study of device safety is 
the study of device failure i.e., based on reliability-theoretical approach to safety. Traditionally safety is preventing failures. 
It defines SIL’s based on failure probability.

#### About SIL 

Safety Integrity Level (SIL): If we have safety system which is based on demand, then SIL is defined as probability of failure when invoked for example
SIL1 it is less than 0.1, SIL4 it is less than 0.0001. If we have safety system that operates continuously then SIL is defined as probability of failure
is per hour, for SIL1 it is less than 10^-5 per hour of operation and for SIL4 it is less than 10^-8. SIL is a measure of the performance of 
safety instrumented function. In each SIL case, the intention is to reduce the probability of device failure. Higher the SIL the safety requirements are high.

Safety is demonstrated not by compliance with prescribed processes, but by assessing hazards, mitigating those hazards, and showing that the residual risk 
is acceptable. Our aim is to produce a safe product, rather than a product that meets the wording of one standard.
(Ref: A. Rae, \Acceptable Residual Risk: Principles, Philosophy and Practicalities," in 2nd IET International Conference on System Safety, (London),2007.)

As stated in definition, SILs are intended to provide targets for developers. In the case of simple electromechanical hardware, it may be possible
to claim achievement of the SIL, using historic random-failure rates. But for complex systems, and for software, whose failures are systematic
and not random, such a claim is unsupportable by evidence. Thus, SILs are used to define the rigour to be used in the development processes. 
In other words, because evidence of the rate of dangerous failures of the product cannot be determined with confidence, attention is turned 
to the development process

#### My experience notes

My experience is that good process may not always lead to safe product. The fact that a process has been followed in developing a product does not tell you
anything about the properties of the product itself. Strong processes need to be enforced during the development of a product, not because that will ensure
that the product is of good quality, but because, without strong processes, we cannot trust any of the information we need to produce our safety case.

 

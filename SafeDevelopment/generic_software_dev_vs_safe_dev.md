#### Generic software development vs Safety software development

Safety product development is different from general product development like apps for example. In safety product development there are requirements
like meeting safety standards, development process, performing hazard and risk analysis (like HAZOP), safety case, failure analysis, safety plan/handbook,
safety manual, using certified products, safe state to be defined, safety culture of organization etc. to name a few.

In industrial application controller is brain as it receives various sensor signals and drives different types of actuators. Functional safety is one of
most important requirements for controller. Everyone concerned with the development of a safety-critical device needs to be aware that human life / environment
may hang on the quality of the design and implementation.  It is important any developer working on a safety critical product has the right to know how to
assess a risk and has the duty to bring safety considerations forward. Developer can gain knowledge from other industrial experts’ knowledge which are
documented through standards.

IEC 61508 is one such standard which prescribe and proscribe processes, procedures, techniques, tools, etc.  Industrial domain functional safety is achieved 
for required safety integrity level (SIL) by implementing requirements specified in IEC 61508.

The data provided with safety products allow the user to integrate them into safety systems, to the IEC 61508 standard, and then state with confidence
that the system meets the safety requirements. This is usually recorded in safety case which is used during audit for safety.

In addition to safety, security is another important non-functional requirement that should be considered in safe product development.
Safety and security go hand to hand. Safety cannot be achieved with out proper security in place. Safety arguments tend to change slowly, 
security arguments can change overnight. Safety and security should be balanced in overall design.  

#### How testing is differnt in Safety?

Heavy dependency on testing at end of product development cycle is an example of poor safety culture. (Reference ISO 26262-2 standard). For safety development right checks at right place should be in place like risk analysis, design verification, error detection (e.g., memory corruption, task missing deadline.). Safety testing includes fault injection testing, unit testing, functional testing, integration testing, black box testing, system testing etc to name a few.

 Design is better mentioned in formal notation. If we can express our designs in a mathematical (i.e., formal) language, then it should be possible to reason about universal concepts. Given our system design, we should be able to prove mathematically  that for any combination and sequence of requests and interrupts, the system will continue to make progress and not lock up. Proving the correctness of a system differs from testing it: Testing demonstrates that it works for the particular set of conditions that occurred during the testing, whereas proving demonstrates that it works under all conditions.

 

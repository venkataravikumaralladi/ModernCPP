This section consists of my notes on safe software development. Safety software development is differnt from general software development. 
In particular safety software development starts with following analysis though list below is not exhaustive. Additional analysis is performed
based on the product being developed.

  1. `Hazard and risk analysis`: This identifies the hazards and risks associated with the use of the final product. This analysis is particularly crucial because the project's
                               safety requirements and data for the failure analysis are derived from it.
  2. `Safety case`: This is a document where we document why we think product being developed is safe to use in mentioned environment.
  3. `Failure analysis`: All systems eventually fail, and it is important to understand how often and in what ways your system is expected to fail. 
  4. `Safety plan`: This lays out the specific practices to be followed during the development of the product. For example, a company may have several coding standards,
                    each suitable for a different type of coding; the safety plan specifies which is to be used for the project. It also defines the precise
                    responsibilities and authorities of each member of the project team.
  5. `Safety manual`: This document mention liability coverage, in an embedded software product, it also defines the environment within which the product must be
                      used and provides a list of proscriptions, e.g., function abc() must not be invoked unless at least 100 Mebibytes of free memory are available.
                      
While designing and implementing a software-based device designed for a safety-critical application, there are numerous analyses that must be carried out. The central of these is the preparation of the safety case, the presentation of the argument as to why the device is considered safe. This will contain a clear statement of the claims made about the device, an argument justifying its use in safety-critical applications, and the evidence backing the argument. The safety case will incorporate the results of other analyses, including the hazard and risk analysis and the failure analysis.

#### Example of hazard
 
 Hazatrd: is memory gets corrupted.
 Risk is configuration data read might be wrong.  This risk can be written as

device_conf_risk_001: If a memory error corrupts the configuration data holding the scheduling policy, the operating system could silently schedule threads incorrectly, causing the application to behave unpredictably.

above risk can be mitigated with safety requirment

device_safety_requirement_001-A: All configuration data SHALL be stored in such a way that memory corruption can be detected.

device_safety_requirement_001-B: The values of each configuration datum SHALL be stored as distinctive multibit values such that no single or double bit corruption
                                 would lead to another valid value.
                                 
device_safety_requirement_001-C: The means of storing multibit values in accordance with requirement
 
 Overview of above activites shown below
  
  ![image](https://user-images.githubusercontent.com/10434795/180604714-d4e5a117-8eb3-4e0b-b262-41d94ce65ec6.png)


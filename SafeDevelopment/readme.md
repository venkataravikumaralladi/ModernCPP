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
                      
  Overview of above activites shown below
  
  ![image](https://user-images.githubusercontent.com/10434795/180604714-d4e5a117-8eb3-4e0b-b262-41d94ce65ec6.png)


### Failure Analayis

This analysis will find how often system fail after considering hazard and risk analysis and safety requirements in place.
Various techniques are used for failure analysis are mentioned below. Failure analysis is usually performed by semi-structured language for example
Bayesian structure network (BSN) is shown below. 

![image](https://user-images.githubusercontent.com/10434795/180649035-c525fcc6-9af0-47e7-a1e2-833ea43f4729.png)

#### Below techniques can be used for failure analysis

1.` Markov analysis`

2. `Failure Mode Effect and Criticality Analysis (FMECA)` (also known as bottom-up approach). For software we use SWFMECA.
       Here we use bottom-up approach “if this component were to fail, what dangerous condition might occur?”.  FMECA requires 
       `failure rate of componen`t, for hardware failure rate is provided in manual, whereas for software failure rate can be made
       from incoming bugs from history.  We can also use code repository in identifying the modules and functions where the most faults 
       are likely to lie. FMECA also requires `failure mode`, `severity effect of failure` of component on overall system.
       For each component calculate its contribution to the system failure.  FMECA also looks at how to identity failure and recover it.
       Example of estimating software bugs in system is shown in above picture.
 
 3. `Fault tree analysis (FTA)` also known as top-down approach). Here we start with dangerous condition and asks what might cause this
    dangerous condition occurs? For example, stack overflow occurs, here we will see what various scenarios how this can occur.
    
 4. `Event-Centric analysis`: Here analysis is done based on external events rather than components.

Tools like Coccinelle is an open-source checker which can be used to check guidelines/rules of a product are correctly implemented mentioned
in user manual of products used internal to product development. It is possible some of the guidelines/safety rules may not possible 
to implement and should be passed to high level. Below diagram shows how handling of processor safety manual are handled.

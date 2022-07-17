### Safety Case

While designing and implementing a software-based device designed for a safety-critical application, there are numerous analyses that must be carried out.
Designers of dependable systems need to present assurance cases that support the claims made about the system’s dependability. Building this assurance case,
incorporating different types of evidence and reasoning, can be daunting. The central of these is the preparation of the `safety case`, the presentation 
of the argument as to why the device is considered safe. This will contain a clear statement of the claims made about the device, an argument justifying
its use in safety-critical applications, and the evidence backing the argument. The safety case will incorporate the results of other analyses, 
including the hazard and risk analysis and the failure analysis.

We must ensure that the production of the safety case is an integral part of the development project, not an add-on. 

When preparing safety case arguments. Do we look for evidence to confirm our pre-existing belief that the system is safe,
or do we specifically look for evidence that goes against our belief? The latter provides information that is more useful.

Safety case document generally contains `boundaries of the product`, `claim`, `argument` and `evidence`. 
Arguments might be written in semi-formal language   like Goal Structuring Notation (GSN), Bayesian Belief Network (BBN), ideas like eliminative argumentation.

The GSN is a graphical notation used to document explicitly the elements and structure of an argument and the argument's relationship to evidence.

Evidence is required to support the argument. Once the structure of the argument is agreed, the evidence for each elementary claim (leaf node" in the GSN or BBN graph) must be gathered and made accessible. A piece of evidence might be a document, a test result, a training record, a formal model, the proofs of theorems, or any other artifact that supports the argument.

Sometimes there is a sub-argument like as to why that particular piece of evidence is adequate? This gap between the evidence and the claim that 
it is presented to support is known as the `assurance deficit`."I believe that assessing the assurance deficit is one argument for using a
quantitative notation, such as BBNs, rather than a qualitative notation such as GSN, for expressing the safety case argument.
With a quantitative notation, the analyst can express the size of the deficit directly in the argument.

In present world where devices are connected to `internet` safety case should be made in context of `security`. A security vulnerability is a fault that does not lead to an error until it is discovered, and then the probability of an error immediately changes from zero to a value close to one. This is different from the behavior of a Heisenbug where the probability of the error is greater than zero, but remains constant.

 

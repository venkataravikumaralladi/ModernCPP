## Hazard, fault, error, and risk

 

`Analogy: The iceberg is the hazard; the risk is that a ship will run into it. One mitigation might be to paint the iceberg yellow to make it more visible.
Even when painted yellow, there is still the residual risk that a collision might happen at night or in fog.`

More generally, I use the term hazard" as something `passive` that exists in the environment and which may be the cause of risks.
Risks are `active` and may give rise to dangerous circumstances. When a risk has been identified, if it is serious enough, it will need to be mitigated;
that is, action will have to be taken to reduce it.

`Hazard` as something passive that exists in the environment (e.g., in code) and which may be the cause of risks. Hazard is potential source of harm.

`Risk` should be mitigated with proper analysis. Usually, there are several risks associated with each hazard, and several mitigations associated with each risk.

`Fault` present in code for example missing deleting allocated memory.

`Error`  The fault may causes error. The error can be handled by defence programming with out failure to occur.

`Failure` is an observable event that component is not working as expected.

 #### Below note is important from design and analysis point of view

Differentiating between faults, errors, and failures allows us to tackle them in different ways. We want to reduce the number of faults inserted
into the system, to detect and remove faults before they become errors, to detect errors and prevent them from becoming failures and, if a failure 
does occur, to handle it in the safest way possible. If we able to detect error we can handle them before causing failure by moving the system
to pre-correct state or pre-defined fixed state.

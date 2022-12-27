Definition
A Turing Machine (TM) is a mathematical model which consists of an infinite length tape divided into cells on which input is given. It consists of a head which reads the input tape. A state register stores the state of the Turing machine. After reading an input symbol, it is replaced with another symbol, its internal state is changed, and it moves from one cell to the right or left. If the TM reaches the final state, the input string is accepted, otherwise rejected.

A TM can be formally described as a 7-tuple (Q, X, ∑, δ, q0, B, F) where −

Q is a finite set of states

X is the tape alphabet

∑ is the input alphabet

δ is a transition function; δ : Q × X → Q × X × {Left_shift, Right_shift}.

q0 is the initial state

B is the blank symbol

F is the set of final states


Example of Turing machine
Turing machine M = (Q, X, ∑, δ, q0, B, F) with

Q = {q0, q1, q2, qf}
X = {a, b}
∑ = {1}
q0 = {q0}
B = blank symbol
F = {qf }
δ is given by −

Tape alphabet symbol    Present State ‘q0’    Present State ‘q1’    Present State ‘q2’
a |    1Rq1 |    1Lq0 |    1Lqf
b |    1Lq2 |    1Rq1 |    1Rqf

Here the transition 1Rq1 implies that the write symbol is 1, the tape moves right, and the next state is q1. Similarly, the transition 1Lq2 implies that the write symbol is 1, the tape moves left, and the next state is q2.

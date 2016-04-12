% - - - 16.02.2015 - - - 

% Task 1
% Define predicate p(N, K), which finds the primal divisors of N
% Define predicate q(N, X), which lists all primal divisors in ACC order

% Generator for the numbers between A and B, A > B
btween(A, _, A).
btween(A, B, X) :- 
    A > B, 
    A1 is A - 1, 
    btween(A1, B, X).

% The predicate 'p' that finds the primal devisors of N
p(N, K) :- 
    Nsq is N / 2, 
    btween(Nsq, 1, K), 
    0 is N mod K.

% The predicate 'q' that finds the list in ACC order
q(N, X) :- q(N, [], X).
q(N, L, X) :-
    p(N, K),
    not(member(K, L)), !,
    q(N, [K|L], X).
q(_, X, X).

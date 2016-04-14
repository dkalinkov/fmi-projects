% - - - 16.02.2015 - - - 

% Task 1
% Define a predicate p(N, K), which finds the primal divisors of N
% Define a predicate q(N, X), which lists all primal divisors in ACC order

% Generator for the numbers between A and B, A > B
btween(A, _, A).
btween(A, B, X) :- 
    A > B, 
    A1 is A - 1, 
    btween(A1, B, X).

% The predicate 'p' that finds the primal devisors of N
p(N, K) :- 
    Nsq is N / 2, 
    btween(Nsq, 2, K), 
    0 is N mod K.

% The predicate 'q' that finds the list in ACC order
q(N, X) :- q(N, [], X).
q(N, L, X) :-
    p(N, K),
    not(member(K, L)), !,
    q(N, [K|L], X).
q(_, X, X).


% - - - 19.11.2011 - - -

% Task 2
% Define a predicate p(X, Y), which checks if two integers have a common primal divisor

% We are using the predicate from task above
p2(X, Y) :- 
    p(X, X1), 
    p(Y, X1).

% Task 1
% Define a predicate p(X, Y), that finds the Cartesian product of the members of a list
% X is the list in the predicate 

% This predicate returns every numbers from the list
getEl([H|_], H).
getEl([_|T], X) :- getEl(T, X).

% This predicate generates the different cartesian entries
dec([], []).
dec([H|T], [K|Y]) :- 
    getEl(H, K), 
    dec(T, Y).


% - - - 05.02.2012 - - -

% Task 1
% Define a predicate p(L, M) that generates all subsets of a list L

% This generates all subsets of the list it receives as argument
sub([_|T], T).
sub([_|T], R):- sub(T, R).
sub([H|T], [H|R]):- sub(T, R).
sub(X, X).

% The task is not yet finished.

% Task 2
% Define a predicate that transposes a matrix
% See the code for transposing a matrix in lists-arrays.pl
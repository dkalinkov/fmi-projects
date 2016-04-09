% Append one list to another
apnd([], X, X).
apnd([H|A], X, [H|Y]):- apnd(A,X,Y).

% Reversing a list
rev(A, X):- rev(A, X, []).
rev([H|A], B, X):- rev(A, B, [H|X]).
rev([], X, X). 

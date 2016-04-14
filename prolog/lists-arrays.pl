% Appends one list to another
% Example:  apnd([1, 2, 3], [4, 5], X).
% Output:   X = [1, 2, 3, 4, 5].
apnd([], X, X).
apnd([H|A], X, [H|Y]) :- apnd(A, X, Y).

% Reversing a list
% Example:  rev([1, 2, 3], X).
% Output:   X = [3, 2, 1].
rev(A, X) :- rev(A, X, []).
rev([H|A], B, X) :- rev(A, B, [H|X]).
rev([], X, X). 

% Тransposing a matrix
% Example:  transpose([[1, 2, 3], [4, 5, 6]], X).
% Output:   X = [[1, 4], [2, 5], [3, 6]].
transpose([[]|_], []).
transpose(M, [H|T]) :- 
    row(M, H, M1), 
    transpose(M1, T).

row([], [], []).
row([[Hm|Tm]|Rm], [Hm|Rt], [Tm|Z]) :- row(Rm, Rt, Z).

% Finds the minimal value in a list
% Example:  minEl([1,2,3], X).
% Output:   X = 1.
minVal([L], L) :- !.
minVal([X,Y|T], O) :-
    (X > Y ->
        minVal([Y|T], O);
        minVal([X|T], O)).

% Finds the maximum value in a list
% Example:  minEl([1,2,3], X).
% Output:   X = 1.
maxVal([L], L) :- !.
maxVal([X,Y|T], O) :-
    (X < Y ->
        maxVal([Y|T], O);
        maxVal([X|T], O)).

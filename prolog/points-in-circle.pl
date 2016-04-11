% The problem asks to find all integer points that
% are inside a circle (around (0,0)) or that are on
% the circle's borders

% Generates all numbers between A and B
gen(A, _, A). 
gen(A, B, X) :- 
    A < B, 
    A1 is A + 1, 
    gen(A1, B, X).

% Checks if a given point(X, Y) in 2D space is 
% in a circle with radius R around the (0, 0) point
isInCirc(X, Y, R) :- 
    X2 is X * X,
    Y2 is Y * Y, 
    R2 is R * R, 
    X2 + Y2 =< R2.

% Generates all the poins in format (X, Y) that are 
% in the circle with radius R around the (0, 0) point
allPoints(X, Y, R) :- 
    R2 is 0 - R, 
    gen(R2, R, X), 
    gen(R2, R, Y), 
    isInCirc(X, Y, R).

% We have a graph G = [[1,2],[2,3],[2,1],[3,2]]
% The task is to find a path between A and B

% Checks if X is a member of the list
% Example:  isMember(1, [1,2,3,4,5]).
% Output:   true ; ...
isMember(X, [Y|T]) :- 
    X = Y; 
    isMember(X, T).

% Checks if there is a path between A and B.
% We are remembering the visited nodes. Use 'isMember' 
% from above if not allowed to use 'member'
path(A, B, G) :- pathHelp(A, B, G, []).
pathHelp(A, B, G, _) :- member([A, B], G).
pathHelp(A, B, G, Visited) :- 
    not(member([A, B], G)),
    member([A, X], G),
    not(member(X, Visited)),
    pathHelp(X, B, G, [A|Visited]).

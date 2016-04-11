% We have a graph G = [[1,2],[2,3],[2,1],[3,2]]
% The task is to find a path between A and B

% Checks if there is a path between A and B.
% We are remembering the visited nodes
path(A, B, G) :- pathHelp(A, B, G, []).
pathHelp(A, B, G, _) :- isMember([A, B], G).
pathHelp(A, B, G, Visited) :- 
    not(isMember([A, B], G)),
    isMember([A, X], G),
    not(isMember(X, Visited)),
    pathHelp(X, B, G, [A|Visited]).
    
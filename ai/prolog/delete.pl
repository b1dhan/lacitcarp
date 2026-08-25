delt(X,[X|Tail],Tail).
delt(X,[Y|Tail],[Y|Tail]):-
delt(X,Tail,Tail).

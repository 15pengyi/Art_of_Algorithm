
Program pku1003;

Var r,s: real;
  n: integer;
Begin
  readln(r);
  While r>0 Do
    Begin
      s := 0;
      n := 1;
      While s<r Do
        Begin
          n := n+1;
          s := s+1/n;
        End;
      writeln(n-1,' card(s)');
      readln(r);
    End;
End.

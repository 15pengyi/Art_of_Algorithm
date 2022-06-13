
Program pku1004;

Var s,r: real;
  i: integer;
Begin
  For i:=1 To 12 Do
    Begin
      readln(r);
      s := s+r;
    End;
  writeln('$',s/12:0:2);
End.

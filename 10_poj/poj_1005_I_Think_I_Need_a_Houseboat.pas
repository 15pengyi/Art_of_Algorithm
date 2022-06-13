
Const Pi = 3.1415926536;

Var n,i: integer;
  x,y: real;
Begin
  readln(n);
  For i:=1 To n Do
    Begin
      readln(x,y);
      writeln('Property ',i,': This property will begin eroding in year ',trunc(
              Pi*(x*x+y*y)/100)+1,'.');
    End;
  writeln('END OF OUTPUT.');
End.

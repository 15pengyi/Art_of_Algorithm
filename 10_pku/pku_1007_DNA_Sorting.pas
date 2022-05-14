
Program pku1007;

Const Max = 100;

Var t: array[0..Max,1..2] Of integer;
  str: array[1..Max] Of string[50];
  i,j,k,n,m: integer;
Procedure sort(x,y:integer);

Var si,sj: integer;
Begin
  si := x;
  sj := y;
  t[0] := t[si];
  Repeat
    While (t[sj,2]>=t[0,2])And(sj>si) Do
      dec(sj);
    If sj>si Then t[si] := t[sj]
    Else break;
    While (t[si,2]<=t[0,2])And(si<sj) Do
      inc(si);
    If si<sj Then t[sj] := t[si]
    Else break;
  Until false;
  t[si] := t[0];
  If sj-1>x Then sort(x,sj-1);
  If sj+1<y Then sort(sj+1,y);
End;
Begin
  readln(n,m);
  For i:=1 To m Do
    Begin
      readln(str[i]);
      t[i,1] := i;
      For j:=1 To n-1 Do
        For k:=j+1 To n Do
          If str[i][j]>str[i][k] Then inc(t[i,2]);
    End;
  sort(1,m);
  For i:=1 To m Do
    writeln(str[t[i,1]]);
End.

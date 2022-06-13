
Program pku1001;

Const max = 100;

Var str: string[6];
  t: array[0..max] Of longint;
  i,j,k,n,c: longint;

Procedure multiply;

Var mi: integer;
Begin
  For mi:=1 To t[0] Do
    t[max+1-mi] := t[max+1-mi]*n;
  mi := 1;
  While mi<=t[0] Do
    Begin
      t[max-mi] := t[max-mi]+t[max+1-mi] Div 10;
      t[max+1-mi] := t[max+1-mi] Mod 10;
      mi := mi+1;
      If t[max-t[0]]>0 Then t[0] := t[0]+1;
    End;
End;
Begin
  While Not seekeof(input) Do
    Begin
      fillchar(t,sizeof(t),0);
      n := 0;
      readln(str,c);
      i := 6;
      While str[i]='0' Do
        i := i-1;
      j := i;
      While str[j]<>'.' Do
        j := j-1;
      t[0] := i-1;
      For k:=1 To j-1 Do
        Begin
          t[max-i+k+1] := ord(str[k])-ord('0');
          n := n*10+t[max-i+k+1];
        End;
      For k:=j+1 To i Do
        Begin
          t[max-i+k] := ord(str[k])-ord('0');
          n := n*10+t[max-i+k];
        End;
      For k:=1 To c-1 Do
        multiply;
      i := (i-j)*c;
      If i=0
        Then For k:=t[0] Downto 1 Do
               write(t[max+1-k])
               Else
                 Begin
                   For k:=t[0] Downto i+1 Do
                     write(t[max+1-k]);
                   write('.');
                   For k:=i Downto 1 Do
                     write(t[max+1-k]);
                 End;
      writeln;
    End;
End.

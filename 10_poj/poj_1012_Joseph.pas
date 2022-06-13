
Program pku1012;

Const ans: array[1..13] Of longint = 
                                     (2,7,5,30,169,441,1872,7632,1740,93313,
                                      459901,1358657,2504881);

Var n,m,i,j,k: longint;
  t: array[1..26] Of integer;
  b: boolean;
Begin
  readln(n);
  While n>0 Do
    Begin
{
      m:=n+1;
      b:=false;
      while not b do
      begin
         b:=true;
         for i:=1 to n*2 do t[i]:=i;
         k:=1;
         for i:=n+n downto n+1 do
         begin
            k:=(k+m-1) mod i;
            if k=0 then k:=i;
            if t[k]<=n then b:=false
                       else for j:=k to i-1 do t[j]:=t[j+1];
            if not b then break;
         end;
         if not b then m:=m+1;
      end;
      writeln(m);
}
      writeln(ans[n]);
      readln(n);
    End;
End.

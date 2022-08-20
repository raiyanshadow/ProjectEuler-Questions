-- Even Fibonacci sums
with Ada.Text_IO, Ada.Integer_Text_IO;
with Ada.Real_Time; use Ada.Real_Time;

procedure Main is
	Start, Stop : Time;
	Elapsed : Time_Span;
	Max_Fibonacci_Limit : Integer;
	function Even_Fibonacci_Sum (Max : Integer) return Integer is
		A, C : Integer := 0;
		B : Integer := 1;
		Fibonacci_Sum : Integer := 0;
	begin
		while B < Max loop
			if (A + B) mod 2 = 0 then
				Fibonacci_Sum := (Fibonacci_Sum + A + B);
			end if;
			A := B;
			B := (B + C);
			C := A;
		end loop;
		return Fibonacci_Sum;
	end Even_Fibonacci_Sum;

begin 
	Ada.Integer_Text_IO.Get (Max_Fibonacci_Limit);

	Start := Clock;

	Ada.Text_IO.Put_Line (Integer'Image (Even_Fibonacci_Sum (Max_Fibonacci_Limit)));
	
	Stop := Clock;
	Elapsed := Stop - Start;
	Ada.Text_IO.Put_Line ("Elapsed time: " & Duration'Image (To_Duration (Elapsed)) & " seconds");
end Main;
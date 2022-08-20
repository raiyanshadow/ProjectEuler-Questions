-- Multiples of 3 and 5
with Ada.Text_IO, Ada.Integer_Text_IO;
with Ada.Real_Time; use Ada.Real_Time;

procedure Main is
	Start, Stop : Time;
	Elapsed : Time_Span;
	Sum : Integer;
	function Multiple (Var : Integer) return Integer is
		A : Integer := 0; 
	begin 
		for I in 1 .. Var loop
			if I mod 3 = 0 or else I mod 5 = 0 then
				A := A + I;
			end if;
		end loop;
		return A;
	end Multiple;

begin 
	Ada.Integer_Text_IO.Get (Sum);
	Start := Clock;
	Sum := Multiple (Sum);
	Ada.Text_IO.Put_Line (Integer'Image(Sum));
	Stop := Clock;
	Elapsed := Stop - Start;
	Ada.Text_IO.Put_Line ("Elapsed time: " & Duration'Image (To_Duration (Elapsed)) & " seconds");
end Main;
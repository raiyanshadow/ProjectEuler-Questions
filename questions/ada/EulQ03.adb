-- Largest prime factor
with Ada.Text_IO, Ada.Integer_Text_IO;
with Ada.Real_Time; use Ada.Real_Time;
with Ada.Numerics.Elementary_Functions; use Ada.Numerics.Elementary_Functions;

procedure Main is
	type LInteger is range 0 .. 2**64;
	Start, Stop : Time;
	Elapsed : Time_Span;
	LInput : LInteger := 600851475143;

	function Is_Prime (N : LInteger) return Boolean is
		Value : LInteger := 2;
	begin
		while (Value ** 2) <= N loop
			if N mod Value = 0 then
				return False;
			end if;
			Value := Value + 1;
		end loop;
		return True;
	end Is_Prime;

	function Highest_Prime_Factor (N : LInteger) return LInteger is
		Highest : LInteger := 0; 
		I : LInteger := 3;
		Copy : LInteger := N;
	begin
		while Copy mod 2 = 0 loop
			Highest := 2;
			Copy := Copy / 2;
		end loop;

		while I <= LInteger (Sqrt (Float (Copy))) loop
			loop
				if not Is_Prime (I) then
					exit;
				else
					while Copy mod I = 0 loop
						Highest := I;
						Copy := Copy / I;
					end loop;
					exit;
				end if;
			end loop;
			I := I + 1;
		end loop;
		return (if Highest = 2 then 2 else Copy) ;
	end Highest_Prime_Factor;
begin
	Start := Clock;

	Ada.Text_IO.Put_Line (LInteger'Image (Highest_Prime_Factor (LInput)));
	
	Stop := Clock;
	Elapsed := Stop - Start;
	Ada.Text_IO.Put_Line ("Elapsed time: " & Duration'Image (To_Duration (Elapsed)) & " seconds");
end Main;
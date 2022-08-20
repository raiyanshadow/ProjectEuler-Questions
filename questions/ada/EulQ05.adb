-- Smallest multiple
with Ada.Text_IO, Ada.Integer_Text_IO;
with Ada.Real_Time; use Ada.Real_Time;

procedure Main is
	type LInteger is range 0 .. 2**64;
	Start, Stop : Time;
	Elapsed : Time_Span;
	Input : Integer;

	function Find_Smallest_Multiple (Max_Divisor : Integer) return LInteger is
		Check : Boolean := False;
		I : LInteger := LInteger(Max_Divisor);
	begin
		loop
			if Check then
				exit;
			end if;
			Check := True;
			for J in 2 .. Max_Divisor loop
				if Check then
					if I mod LInteger(J) = 0 then
						Check := True;
						if J = Max_Divisor then
							return I;
						end if;
					else
						Check := False;
					end if;
				else
					exit;
				end if;
			end loop;
			I := I + 1;
		end loop;
		return 0;
	end Find_Smallest_Multiple;

begin
	Start := Clock;

	Ada.Integer_Text_IO.Get (Input);
	Ada.Text_IO.Put_Line (LInteger'Image (Find_Smallest_Multiple (Input)));

	Stop := Clock;
	Elapsed := Stop - Start;
	Ada.Text_IO.Put_Line ("Elapsed time: " & Duration'Image (To_Duration (Elapsed)) & " seconds");
end Main;
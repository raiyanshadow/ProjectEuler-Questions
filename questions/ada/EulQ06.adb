-- Sum square difference
with Ada.Text_IO, Ada.Integer_Text_IO;
with Ada.Real_Time; use Ada.Real_Time;

procedure Main is
	type LInteger is range 0 .. 2**64;
	Start, Stop : Time;
	Elapsed : Time_Span;
	Input : Integer;

	function Sum_Square_Difference (X : Integer) return LInteger is
		Square_Of_Sums : LInteger := ((LInteger(X) * (LInteger(X) + 1)) / 2) ** 2;
		Sum_Of_Squares : LInteger := (LInteger(X) * (LInteger(X) + 1) * ((2 * (LInteger(X)) + 1))) / 6;
	begin
		return Square_Of_Sums - Sum_Of_Squares;
	end Sum_Square_Difference; 

begin
	Start := Clock;

	Ada.Integer_Text_IO.Get (Input);
	Ada.Text_IO.Put_Line (LInteger'Image (Sum_Square_Difference (Input)));

	Stop := Clock;
	Elapsed := Stop - Start;
	Ada.Text_IO.Put_Line ("Elapsed time: " & Duration'Image (To_Duration (Elapsed)) & " seconds");
end Main;
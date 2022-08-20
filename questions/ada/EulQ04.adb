-- Largest palindrome product
with Ada.Text_IO, Ada.Integer_Text_IO;
with Ada.Real_Time; use Ada.Real_Time;

procedure Main is
	type LInteger is range 0 .. 2**64;
	Start, Stop : Time;
	Elapsed : Time_Span;
	Input : Integer;

	function Number_Digits (N : LInteger) return Integer is
		Copy : LInteger := N;
		I : Integer := 0;
	begin
		while Copy /= 0 loop
			I := I + 1;
			Copy := Copy / 10;
		end loop;
		return I;
	end Number_Digits;

	function Is_Palindrome (N : LInteger) return Boolean is
		Temp_Copy : LInteger := N;
		Copy : LInteger := 0;
		I : Integer := Number_Digits (N) - 1;
	begin
		while Temp_Copy /= 0 loop
			Copy := Copy + ((Temp_Copy mod 10) * (10 ** I));
			Temp_Copy := Temp_Copy / 10;
			I := I - 1;
		end loop;
		return (N = Copy);
	end Is_Palindrome;
	
	function Largest_Palindrome_Product (Number_Of_Digits : Integer) return LInteger is
		Min : LInteger := 10 ** (Number_Of_Digits - 1);
		Max : LInteger := 10 ** Number_Of_Digits;
		Product : LInteger;
		Return_Value : LInteger := 0;
	begin
		if Number_Of_Digits < 2 then
			return 9;
		end if;

		for I in reverse Min .. (Max - 1) loop
			for J in reverse Min .. (Max - 1) loop
				Product := I * J;
				if Is_Palindrome (Product) and then Product > Return_Value then
					Return_Value := Product;
					exit;
				end if; 
			end loop;
		end loop;
		return Return_Value;
	end Largest_Palindrome_Product;

begin
	Start := Clock;

	Ada.Integer_Text_IO.Get (Input);
	Ada.Text_IO.Put_Line (LInteger'Image (Largest_Palindrome_Product (Input)));

	Stop := Clock;
	Elapsed := Stop - Start;
	Ada.Text_IO.Put_Line ("Elapsed time: " & Duration'Image (To_Duration (Elapsed)) & " seconds");
end Main;
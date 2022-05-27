

public class logicalandBitwiseOperators{
	public static void main(String[] args){

		// Logical operations &&, ||, !
		boolean a = true;
		boolean b = false;
		System.out.println(a || b);
		System.out.println(a && b);
		System.out.println(!a);

		//bitwise operations  &, |, ~
		int num1 = 60;//111100
		int num2 = 42;//101010
					  //101000 => 40
		System.out.println(num1 & num2);
		System.out.println(num1 | num2);
		System.out.println(~num1);
	}
}

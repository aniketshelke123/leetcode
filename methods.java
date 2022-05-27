

class Methods{
	public static void main(String [] args){
		/*
		 * Creating methods in java
		 * HOw does a mehtod return value?
		 */

		Methods m = new Methods();
		m.doThis();
		m.addition(100, 200);
		int x = m.multiply(4, 20);
		System.out.println(x);
	}
	public void doThis(){
		System.out.println("Do this executed");
	}

	public void addition(int num1, int num2){
		System.out.println(num1 + num2);
	}

	public int multiply(int num1, int num2){
		int num3 = num1 * num2;
		return num3;
	}
}

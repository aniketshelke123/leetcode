
public class Access_main {
	public static void main(String[] args){
		Access_specifiers ac = new Access_specifiers();
		ac.doThisPublic();
		ac.doThisDefault();
		ac.doThisPrivate();
	}
}

class Access_specifiers {
	/*
	 * public Access_specifiers
	 * default access/ no Access_specifiers
	 * private Access_specifiers
	 * Protected Access_specifiers
	 */
	public void doThisPublic(){
		System.out.println("Public method");
	}

	private void doThisPrivate(){
		System.out.println("private method");
	}

	void doThisDefault(){
		System.out.println("Private methos");
	}
}
			

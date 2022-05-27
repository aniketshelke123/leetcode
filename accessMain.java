public class Main
{
	public static void main(String[] args) {
		System.out.println("Hello World");
		
		As a = new As();
		
		a.doPublic();
	//	a.doPrivate();
	   a.doDefault();
		
	}
}

 class As{
    
    
    public void doPublic(){
        System.out.println("public Method");
    }
    
    private void doPrivate(){
        System.out.println("Private method");
        
    }
    
    void doDefault(){
        System.out.println("Default");
    }
}

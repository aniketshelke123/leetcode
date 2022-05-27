class Test
{
	public static void main(String ar[])
	{
		System.out.println("main starts");
		int i;
		A a1 = new A();
		B b1 = new B();
		C c1 = new C();

		a1.start();
		b1.start();
		c1.start();

		for(i=1;i<=7;i++)
		{
			System.out.println("Thread Main : " + i);
		}				

		System.out.println("main ends");
	}
}


class A extends Thread
{
	public void run()
	{
		int i;
		for(i=1;i<=7;i++)
		{
			System.out.println("Thread A : " + i);
		}
	}
}

class B extends Thread
{
	public void run()
	{
		int i;
		for(i=1;i<=7;i++)
		{
			System.out.println("Thread B : " + i);
		}
	}
}

class C extends Thread
{
	public void run()
	{
		int i;
		for(i=1;i<=7;i++)
		{
			System.out.println("Thread C : " + i);
		}
	}
}


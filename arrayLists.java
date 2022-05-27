
import java.util.ArrayList;

public class arrayList{
	public static void main(String[] args){

		ArrayList arr = new ArrayList();
		arr.add("Red");
		arr.add("21");
		arr.add("Pink");
		arr.add("Green");
		arr.add("Yellow");
		arr.add("Pink");
		arr.add("Black");

		System.out.println(arr);

		System.out.println(arr.get(3));

		arr.set(2, "bright");
		System.out.println(arr.get(2));
		arr.remove(0);
		arr.remove("Black");
		System.out.println(arr);

		//index of and last index of
		System.out.println(arr.indexOf("Pink"));
		System.out.println(arr.lastIndexOf("Pink"));
		System.out.println(arr.contains("Yellow"));

		System.out.println(arr.subList(1, 3));

		System.out.println(arr.isEmpty());
		System.out.println(arr.size());

		for (var x : arr){
			System.out.println(x);
		}
	}
}



public class string_operations{
	public static void main(String[] args){
		/*
		 * Concatenate
		 * Length
		 * Trim
		 * Uppercase
		 * Lowercase
		 * Empty
		 */

		String str1 = "De Zinnia";
		String str2 = "Institutes";
		String str3 = str1 + str2;
		System.out.println(str3);

		String str4 = str1.concat(str2);
		System.out.println(str4);

		int num1 = 100;
		System.out.println(str1 + num1); // convert num into string auto

		// coutn the characters in string
		System.out.println(str1.length());

		// get rid of space at the beginning and at the end
		String str5 = "    skdfjsdf skdf dfsdkf jf     ";
		System.out.println(str5.trim());

		// Upper case
		System.out.println(str5.toUpperCase());
		// Lower Case
		System.out.println(str5.toLowerCase());
		// Empty
		System.out.println(str5.isEmpty());

		

	}
}

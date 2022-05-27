

public class reverseString{
	public static void main(String[] args){

		// Substring is used for slicing str1.substring(begin, end);
		String str1 = "Aniket Shelke";
		String str2 = "";

		int lenOfStr1 = str1.length();
		System.out.println(lenOfStr1);

		for (int i = lenOfStr1 - 1; i >= 0; i--){
			char c = str1.charAt(i);
			str2 += c;
		}
		System.out.println(str2);
	}
}
